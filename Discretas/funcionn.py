from flask import Flask, render_template, request
import os
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd
import io
import base64
from werkzeug.utils import secure_filename

app = Flask(__name__)

# Definir las extensiones permitidas
ALLOWED_EXTENSIONS = {'txt', 'csv'}

def allowed_file(filename):
    """Verifica si el archivo tiene una extensión permitida."""
    return '.' in filename and \
           filename.rsplit('.', 1)[1].lower() in ALLOWED_EXTENSIONS

# Funciones de Clasificación

def prime(n):
    """Determina si un número es primo."""
    if n <= 1:
        return False
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return False
    return True

def compositive(n):
    """Determina si un número es compuesto."""
    return n > 1 and not prime(n)

def even(n):
    """Determina si un número es par."""
    return n % 2 == 0

def odd(n):
    """Determina si un número es impar."""
    return not even(n)

def sum_of_divisors(n):
    """Calcula la suma de los divisores propios de un número."""
    return sum(i for i in range(1, n) if n % i == 0)

def perfect(n):
    """Determina si un número es perfecto."""
    return n > 0 and sum_of_divisors(n) == n

def deficient(n):
    """Determina si un número es deficiente."""
    return n > 0 and sum_of_divisors(n) < n

def classify(n):
    """Clasifica un número según varias propiedades matemáticas."""
    classification = {
        "Primo": prime(n),
        "Compuesto": compositive(n),
        "Par": even(n),
        "Impar": odd(n),
        "Perfecto": perfect(n),
        "Deficiente": deficient(n)
    }
    return classification

def is_integer(s):
    """Verifica si una cadena puede convertirse a un entero."""
    try:
        int(s)
        return True
    except ValueError:
        return False

# Función para Parsear y Clasificar el Archivo o Texto Manual

def parse_and_classify_content(content):
    """
    Procesa el contenido (lista de líneas) y clasifica cada número.
    Retorna una lista de resultados y un diccionario de estadísticas.
    """
    results = []
    stats = {
        "Primo": 0,
        "Compuesto": 0,
        "Par": 0,
        "Impar": 0,
        "Perfecto": 0,
        "Deficiente": 0
    }

    for line in content:
        line = line.strip()
        if is_integer(line):
            num = int(line)
            if num < 0:
                results.append((num, "Número negativo"))
                continue
            classification = classify(num)
            # Convertir True/False a Sí/No
            classification_si_no = {k: ("Sí" if v else "No") for k, v in classification.items()}
            results.append((num, classification_si_no))
            # Actualizar estadísticas (solo contar "Sí")
            for key, value in classification.items():
                if value:
                    stats[key] += 1
        else:
            results.append((line, "Línea inválida"))
    return results, stats

# Función para Generar Gráfico

def generate_plot(stats):
    """
    Genera un gráfico de barras a partir de las estadísticas y lo codifica en base64.
    """
    sns.set(style="whitegrid")
    
    # Convertir las estadísticas a un DataFrame de Pandas
    df = pd.DataFrame(list(stats.items()), columns=["Clasificación", "Cantidad"])
    
    # Crear el gráfico de barras
    plt.figure(figsize=(10,6))
    bar_plot = sns.barplot(x="Clasificación", y="Cantidad", data=df, palette="viridis")
    
    # Añadir títulos y etiquetas
    plt.title("Distribución de Clasificaciones de Números")
    plt.xlabel("Clasificación")
    plt.ylabel("Cantidad")
    
    # Añadir etiquetas encima de las barras
    for index, row in df.iterrows():
        bar_plot.text(index, row.Cantidad + 0.1, row.Cantidad, color='black', ha="center")
    
    # Guardar el gráfico en un objeto BytesIO
    img = io.BytesIO()
    plt.tight_layout()
    plt.savefig(img, format='png')
    img.seek(0)
    plot_url = base64.b64encode(img.getvalue()).decode()
    
    # Cerrar la figura para liberar memoria
    plt.close()
    
    return plot_url

# Rutas de Flask

@app.route('/')
def upload_file():
    """Ruta principal para subir archivos y/o ingresar números manualmente."""
    return render_template('upload.html')

@app.route('/uploader', methods=['POST'])
def uploader_file():
    """Ruta para manejar la subida y procesamiento de archivos y/o números manuales."""
    results = []
    stats = {
        "Primo": 0,
        "Compuesto": 0,
        "Par": 0,
        "Impar": 0,
        "Perfecto": 0,
        "Deficiente": 0
    }

    # Procesar archivo si se ha subido
    if 'file' in request.files:
        file = request.files['file']
        if file and allowed_file(file.filename):
            filename = secure_filename(file.filename)
            try:
                # Leer el contenido del archivo
                file_content = file.read().decode('utf-8').splitlines()
                clasificados, estadisticas = parse_and_classify_content(file_content)
                results.extend(clasificados)
                # Actualizar estadísticas
                for key in stats:
                    stats[key] += estadisticas.get(key, 0)
            except Exception as e:
                return f"Error al procesar el archivo: {e}", 400

    # Procesar números manuales si se han ingresado
    manual_numbers = request.form.get('manual_numbers')
    if manual_numbers:
        # Dividir por líneas
        manual_content = manual_numbers.strip().splitlines()
        clasificados_manual, estadisticas_manual = parse_and_classify_content(manual_content)
        results.extend(clasificados_manual)
        # Actualizar estadísticas
        for key in stats:
            stats[key] += estadisticas_manual.get(key, 0)

    if not results:
        return "No se proporcionaron números para clasificar.", 400

    # Generar el gráfico si hay estadísticas
    plot = generate_plot(stats) if any(stats.values()) else None

    return render_template('results.html', results=results, plot=plot)

if __name__ == '__main__':
    app.run(debug=True)
