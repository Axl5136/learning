#include <stdio.h>

// Prototipos de funciones
void leerArreglo(int A[], int *n);
void calcularRepeticiones(int A[], int B[], int n, int *m);
void mostrarArreglo(int A[], int n, const char *nombre);

int main() {
    int A[50]; // Arreglo de entrada
    int B[50]; // Arreglo de salida
    int n, m;  // Tamaño de A y B

    // Leer el arreglo A
    leerArreglo(A, &n);

    // Calcular el arreglo B
    calcularRepeticiones(A, B, n, &m);

    // Mostrar los arreglos
    mostrarArreglo(A, n, "A");
    mostrarArreglo(B, m, "B");

    return 0;
}

// Función para leer el arreglo A
void leerArreglo(int A[], int *n) {
    printf("Ingrese el número de elementos del arreglo A (máximo 50): ");
    scanf("%d", n);

    if (*n > 50) {
        printf("El número máximo permitido es 50. Se ajustará a 50.\n");
        *n = 50;
    }

    printf("Ingrese los %d elementos del arreglo A en orden creciente:\n", *n);
    for (int i = 0; i < *n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &A[i]);
    }
}

// Función para calcular las repeticiones y llenar el arreglo B
void calcularRepeticiones(int A[], int B[], int n, int *m) {
    int count = 1; // Contador de repeticiones
    int indexB = 0; // Índice para el arreglo B

    for (int i = 1; i < n; i++) {
        if (A[i] == A[i - 1]) {
            count++;
        } else {
            B[indexB++] = count; // Almacenar el número de repeticiones en B
            count = 1;           // Reiniciar el contador
        }
    }
    B[indexB++] = count; // Guardar la última cuenta
    *m = indexB;         // Actualizar el tamaño de B
}

// Función para mostrar un arreglo
void mostrarArreglo(int A[], int n, const char *nombre) {
    printf("\nArreglo %s:\n", nombre);
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}
