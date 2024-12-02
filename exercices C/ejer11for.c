#include <stdio.h>
#include <math.h>

// Prototipos de funciones
void leerNumero(int *N);
double calcularTermino(int i);
void imprimirSerieYSumar(int N, double *suma);
void mostrarResultado(double suma);

int main() {
    int N;
    double suma = 0;

    // Leer el número de términos de la serie
    leerNumero(&N);

    // Calcular la serie e imprimir cada término
    imprimirSerieYSumar(N, &suma);

    // Mostrar el resultado de la suma total
    mostrarResultado(suma);

    return 0;
}

// Función para leer el número de términos de la serie
void leerNumero(int *N) {
    printf("Introduce el número de términos (N): ");
    scanf("%d", N);
}

// Función para calcular un término específico de la serie
double calcularTermino(int i) {
    return (double)i / pow(2, i);
}

// Función para imprimir cada término y calcular la suma total
void imprimirSerieYSumar(int N, double *suma) {
    printf("Términos de la serie:\n");
    for (int i = 1; i <= N; i++) {
        double termino = calcularTermino(i);
        printf("Término %d: %.6f\n", i, termino);
        *suma += termino; // Acumular la suma total
    }
}

// Función para mostrar el resultado final
void mostrarResultado(double suma) {
    printf("La suma total de la serie es: %.6f\n", suma);
}