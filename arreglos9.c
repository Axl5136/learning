#include <stdio.h>

// Prototipos de funciones
void leerVectores(double A[], double B[], int *n);
void multiplicarVectores(double A[], double B[], double C[], int n);
void mostrarVector(double V[], int n, const char *nombre);

int main() {
    double A[50]; // Vector A
    double B[50]; // Vector B
    double C[50]; // Vector C
    int n;        // Tamaño de los vectores

    // Leer los vectores A y B
    leerVectores(A, B, &n);

    // Multiplicar elemento a elemento A y B, guardar en C
    multiplicarVectores(A, B, C, n);

    // Mostrar los tres vectores
    mostrarVector(A, n, "A");
    mostrarVector(B, n, "B");
    mostrarVector(C, n, "C");

    return 0;
}

// Función para leer los vectores A y B
void leerVectores(double A[], double B[], int *n) {
    printf("Ingrese el número de elementos de los vectores (máximo 50): ");
    scanf("%d", n);

    if (*n > 50) {
        printf("El número máximo permitido es 50. Se ajustará a 50.\n");
        *n = 50;
    }

    printf("Ingrese los %d elementos del vector A:\n", *n);
    for (int i = 0; i < *n; i++) {
        printf("A[%d]: ", i + 1);
        scanf("%lf", &A[i]);
    }

    printf("Ingrese los %d elementos del vector B:\n", *n);
    for (int i = 0; i < *n; i++) {
        printf("B[%d]: ", i + 1);
        scanf("%lf", &B[i]);
    }
}

// Función para multiplicar los vectores A y B, guardando el resultado en C
void multiplicarVectores(double A[], double B[], double C[], int n) {
    for (int i = 0; i < n; i++) {
        C[i] = A[i] * B[i];
    }
}

// Función para mostrar un vector
void mostrarVector(double V[], int n, const char *nombre) {
    printf("\nVector %s:\n", nombre);
    for (int i = 0; i < n; i++) {
        printf("%.2f ", V[i]);
    }
    printf("\n");
}
