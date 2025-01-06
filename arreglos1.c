#include <stdio.h>

#define TAMANO_MAX 50
#define APROBATORIO 60 // Se asume que la calificación mínima aprobatoria es 60

// Prototipos de funciones
void leerNotas(int notas[], int *n);
float calcularPromedio(int notas[], int n);
void mostrarPromedio(float promedio);
void mostrarAprobadasYReprobadas(int notas[], int n);

int main() {
    int notas[TAMANO_MAX];
    int n; // Número de calificaciones

    leerNotas(notas, &n);                     // Leer las calificaciones
    float promedio = calcularPromedio(notas, n); // Calcular el promedio
    mostrarPromedio(promedio);               // Mostrar el promedio
    mostrarAprobadasYReprobadas(notas, n);   // Mostrar las aprobatorias y reprobatorias

    return 0;
}

// Función para leer las calificaciones
void leerNotas(int notas[], int *n) {
    printf("Ingrese el número de calificaciones (máximo %d): ", TAMANO_MAX);
    scanf("%d", n);

    if (*n > TAMANO_MAX) {
        printf("El número de calificaciones no puede exceder %d.\n", TAMANO_MAX);
        *n = TAMANO_MAX;
    }

    printf("Ingrese las %d calificaciones:\n", *n);
    for (int i = 0; i < *n; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%d", &notas[i]);
    }
}

// Función para calcular el promedio de las calificaciones
float calcularPromedio(int notas[], int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += notas[i];
    }
    return (float)suma / n;
}

// Función para mostrar el promedio de las calificaciones
void mostrarPromedio(float promedio) {
    printf("El promedio de las calificaciones es: %.2f\n", promedio);
}

// Función para mostrar las calificaciones aprobatorias y reprobatorias
void mostrarAprobadasYReprobadas(int notas[], int n) {
    printf("Calificaciones aprobatorias (>= %d):\n", APROBATORIO);
    for (int i = 0; i < n; i++) {
        if (notas[i] >= APROBATORIO) {
            printf("%d ", notas[i]);
        }
    }
    printf("\n");

    printf("Calificaciones reprobatorias (< %d):\n", APROBATORIO);
    for (int i = 0; i < n; i++) {
        if (notas[i] < APROBATORIO) {
            printf("%d ", notas[i]);
        }
    }
    printf("\n");
}
