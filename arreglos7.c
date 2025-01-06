#include <stdio.h>

// Prototipo del procedimiento
int cuentaCeros(int A[], int n);

// Prototipo de funciones auxiliares
void leerArreglo(int A[], int *n);

int main() {
    int A[50]; // Arreglo con un máximo de 50 elementos
    int n;     // Cantidad de elementos

    // Leer el arreglo
    leerArreglo(A, &n);

    // Contar los ceros en el arreglo
    int numeroCeros = cuentaCeros(A, n);

    // Mostrar el resultado
    printf("El arreglo contiene %d ceros.\n", numeroCeros);

    return 0;
}

// Procedimiento para contar los ceros en el arreglo
int cuentaCeros(int A[], int n) {
    int contador = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == 0) {
            contador++;
        }
    }
    return contador;
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
