#include <stdio.h>

// Prototipos de funciones
void solicitarCantidad(int *n);
void introducirElementos(int vector[], int n);
void ordenarSeleccion(int vector[], int n);
void ordenarBurbuja(int vector[], int n);
void mostrarElementos(int vector[], int n);
void menu(int vector[], int *n);

int main() {
    int vector[50]; // Máximo tamaño del vector
    int n = 0;      // Cantidad de elementos
    menu(vector, &n);
    return 0;
}

// Función para mostrar el menú
void menu(int vector[], int *n) {
    int opcion;
    do {
        printf("\nMenú de opciones:\n");
        printf("1. Solicitar la cantidad de elementos a introducir\n");
        printf("2. Introducir los elementos del vector\n");
        printf("3. Ordenar los elementos en orden creciente (método selección)\n");
        printf("4. Ordenar los elementos en orden decreciente (método burbuja)\n");
        printf("5. Mostrar los elementos del vector\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                solicitarCantidad(n);
                break;
            case 2:
                introducirElementos(vector, *n);
                break;
            case 3:
                ordenarSeleccion(vector, *n);
                printf("Vector ordenado en orden creciente.\n");
                break;
            case 4:
                ordenarBurbuja(vector, *n);
                printf("Vector ordenado en orden decreciente.\n");
                break;
            case 5:
                mostrarElementos(vector, *n);
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 6);
}

// Función para solicitar la cantidad de elementos
void solicitarCantidad(int *n) {
    printf("Ingrese la cantidad de elementos (máximo 50): ");
    scanf("%d", n);
    if (*n > 50) {
        printf("El número máximo permitido es 50. Se ajustará a 50.\n");
        *n = 50;
    }
}

// Función para introducir los elementos del vector
void introducirElementos(int vector[], int n) {
    printf("Ingrese los %d elementos del vector:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vector[i]);
    }
}

// Función para ordenar el vector en orden creciente (método selección)
void ordenarSeleccion(int vector[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (vector[j] < vector[minIdx]) {
                minIdx = j;
            }
        }
        // Intercambiar
        int temp = vector[i];
        vector[i] = vector[minIdx];
        vector[minIdx] = temp;
    }
}

// Función para ordenar el vector en orden decreciente (método burbuja)
void ordenarBurbuja(int vector[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vector[j] < vector[j + 1]) {
                // Intercambiar
                int temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
}

// Función para mostrar los elementos del vector
void mostrarElementos(int vector[], int n) {
    printf("Elementos del vector:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}
