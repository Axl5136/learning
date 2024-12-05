#include <stdio.h>
// Prototipos de funciones
void mostrar(int *, int);
void salida(int *, int, int n);
void copiarSinRepetidos(int *, int *, int *, int);
void darNumElem(int *);
void insertarDatos(int *, int);
// Definir constantes
#define MAX 30
// Función principal
int main() {
    int n, a[MAX], b[MAX] = {0};
    int tb = 0;
    darNumElem(&n);
    insertarDatos(a, n);
    copiarSinRepetidos(a, b, &tb, n);
    salida(b, tb, n);
}
//cuerpo de las funciones
void darNumElem(int *n) {
    do {
        printf("Ingrese el número de elementos (máximo %d): ", MAX);
        scanf("%d", n);
    } while (*n < 1 || *n > MAX);
}
void insertarDatos(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("Elemento[%d]: ", i + 1);
        scanf("%d", &a[i]);
    }
}
void copiarSinRepetidos(int *a, int *b, int *tb, int n) {
    for (int i = 0; i < n; i++) {
        int repetido = 0;
        for (int j = 0; j < *tb; j++) {
            if (a[i] == b[j]) {
                repetido = 1;
                break;
            }
        }
        if (!repetido) {
            b[*tb] = a[i];
            (*tb)++;
        }
    }
}
void mostrar(int *arr, int n) {
     printf("\nVector a:\n");
    for (int i = 0; i < n; i++) {
        printf("Dato[%d] = %d\n", i + 1, arr[i]);
    }
}
void salida(int *b, int tb, int n) {
    printf("Vector b: ");
    if(tb == n){
        printf("No hay elementos repetidos. \n");
    } else {
    for (int i = 0; i < tb; i++) {
        printf("%d", b[i]);
        if (i < tb - 1) {
            printf(", ");
        }
    }
    printf("\n");
    }
}