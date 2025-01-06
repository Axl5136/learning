#include <stdio.h>

// Prototipos de funciones
void leerArreglo(int A[], int *n);
void encontrarPosiciones(int A[], int n, int x, int B[], int *m);
void mostrarArreglo(int A[], int n, const char *nombre);

int main() {
    int A[50]; // Arreglo A con un máximo de 50 elementos
    int B[50]; // Arreglo B que contendrá las posiciones
    int n, m;  // Tamaños de los arreglos A y B
    int x;     // Valor a buscar

    // Leer el arreglo A
    leerArreglo(A, &n);

    // Solicitar el valor x a buscar
    printf("Ingrese el valor a buscar en el arreglo A: ");
    scanf("%d", &x);

    // Encontrar las posiciones donde A[i] == x
    encontrarPosiciones(A, n, x, B, &m);

    // Mostrar el arreglo A
    mostrarArreglo(A, n, "A");

    // Mostrar el arreglo B con las posiciones
    if (m > 0) {
        mostrarArreglo(B, m, "B (posiciones)");
    } else {
        printf("\nEl valor %d no se encuentra en el arreglo A.\n", x);
    }

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

    printf("Ingrese los %d elementos del arreglo A:\n", *n);
    for (int i = 0; i < *n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &A[i]);
    }
}

// Función para encontrar las posiciones de los elementos iguales a x
void encontrarPosiciones(int A[], int n, int x, int B[], int *m) {
    *m = 0; // Inicializar tamaño del arreglo B
    for (int i = 0; i < n; i++) {
        if (A[i] == x) {
            B[(*m)++] = i + 1; // Guardar la posición (1 basado) en B
        }
    }
}

// Función para mostrar un arreglo
void mostrarArreglo(int A[], int n, const char *nombre) {
    printf("\nArreglo %s:\n", nombre);
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}
