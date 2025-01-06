#include <stdio.h>

// Prototipo del procedimiento
void intercambia(int *A, int i, int j);

// Prototipo de funciones auxiliares
void leerArreglo(int A[], int *n);
void mostrarArreglo(int A[], int n);

int main() {
    int A[50]; // Arreglo con un máximo de 50 elementos
    int n;     // Cantidad de elementos
    int i, j;  // Posiciones a intercambiar

    // Leer el arreglo
    leerArreglo(A, &n);

    // Mostrar el arreglo antes del intercambio
    printf("Arreglo original:\n");
    mostrarArreglo(A, n);

    // Solicitar posiciones para intercambiar
    printf("\nIngrese la primera posición a intercambiar (1 a %d): ", n);
    scanf("%d", &i);
    printf("Ingrese la segunda posición a intercambiar (1 a %d): ", n);
    scanf("%d", &j);

    // Realizar el intercambio
    intercambia(A, i, j);

    // Mostrar el arreglo después del intercambio
    printf("\nArreglo después del intercambio:\n");
    mostrarArreglo(A, n);

    return 0;
}

// Procedimiento que intercambia los valores en las posiciones i y j
void intercambia(int *A, int i, int j) {
    // Convertir las posiciones del usuario (basadas en 1) a índices (basados en 0)
    i -= 1;
    j -= 1;

    // Realizar el intercambio
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

// Función para leer el arreglo
void leerArreglo(int A[], int *n) {
    printf("Ingrese el número de elementos del arreglo (máximo 50): ");
    scanf("%d", n);

    if (*n > 50) {
        printf("El número máximo permitido es 50. Se ajustará a 50.\n");
        *n = 50;
    }

    printf("Ingrese los %d elementos del arreglo:\n", *n);
    for (int i = 0; i < *n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &A[i]);
    }
}

// Función para mostrar el arreglo
void mostrarArreglo(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}
