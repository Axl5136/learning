#include <stdio.h>

// Prototipos de funciones
void leerVector(double A[], int *n);
void calcularRestaExtremos(double A[], double B[], int n);
void mostrarVectores(double A[], double B[], int n);

int main() {
    int n;            // Tamaño del vector
    double A[50];     // Vector original
    double B[50];     // Vector resultado

    // Leer el vector A
    leerVector(A, &n);

    // Calcular la resta de extremos y guardar en B
    calcularRestaExtremos(A, B, n);

    // Mostrar ambos vectores
    mostrarVectores(A, B, n);

    return 0;
}

// Función para leer el vector A
void leerVector(double A[], int *n) {
    printf("Ingrese el número de elementos del vector (máximo 50): ");
    scanf("%d", n);

    if (*n > 50) {
        printf("El tamaño máximo permitido es 50. Se ajustará a 50.\n");
        *n = 50;
    }

    printf("Ingrese los %d elementos del vector A:\n", *n);
    for (int i = 0; i < *n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%lf", &A[i]);
    }
}

// Función para calcular la resta de extremos y guardar en B
void calcularRestaExtremos(double A[], double B[], int n) {
    for (int i = 0; i < n / 2; i++) {
        B[i] = A[n - 1 - i] - A[i];
    }
    if (n % 2 == 1) { // Caso cuando el número de elementos es impar
        B[n / 2] = A[n / 2];
    }
}

// Función para mostrar ambos vectores
void mostrarVectores(double A[], double B[], int n) {
    printf("\nVector A (original):\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", A[i]);
    }
    printf("\n");

    printf("\nVector B (resultado):\n");
    for (int i = 0; i < (n + 1) / 2; i++) { // Solo muestra los elementos calculados en B
        printf("%.2f ", B[i]);
    }
    printf("\n");
}
