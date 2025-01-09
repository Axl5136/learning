#include <stdio.h>
#include <string.h>

#define MAX 80

void leeCadena(char *s1, int tamanoMax);
void mostrarMenu(char *mensaje);
void invertirCadena(char *mensaje);
void mostrarLetrasImparesYpares(char *mensaje);
void alternarUltimaYPrimeraLetra(char *mensaje);

void main() {
    char mensaje[MAX];
    leeCadena(mensaje, MAX);
    mostrarMenu(mensaje);

}

void leeCadena(char *s1, int tamanoMax) {
    printf("Introduzca el mensaje (máximo %d caracteres):\n", tamanoMax - 1);
    scanf("%[^\n]", s1);
}

void mostrarMenu(char *mensaje) {
    int opcion;
    do {
        printf("\nElija una opción:\n");
        printf("1. Mostrar el mensaje en orden inverso\n");
        printf("2. Mostrar letras en posiciones impares y luego pares\n");
        printf("3. Alternar entre última y primera letra\n");
        printf("4. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);
        getchar();

        printf("\nMensaje original: %s\n", mensaje);
        printf("Resultado: ");
        switch (opcion) {
            case 1:
                invertirCadena(mensaje);
                break;
            case 2:
                mostrarLetrasImparesYpares(mensaje);
                break;
            case 3:
                alternarUltimaYPrimeraLetra(mensaje);
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 4);
}

void invertirCadena(char *mensaje) {
    int longitud = strlen(mensaje);
    for (int i = longitud - 1; i >= 0; i--) {
        printf("%c", mensaje[i]);
    }
    printf("\n");
}

void mostrarLetrasImparesYpares(char *mensaje) {
    int longitud = strlen(mensaje);

    for (int i = 0; i < longitud; i += 2) {
        printf("%c", mensaje[i]);
    }
    for (int i = 1; i < longitud; i += 2) {
        printf("%c", mensaje[i]);
    }
    printf("\n");
}

void alternarUltimaYPrimeraLetra(char *mensaje) {
    int longitud = strlen(mensaje);
    int i = longitud - 1; //
    int j = 0;            //

    while (i >= j) {
        printf("%c", mensaje[i]); // Imprimir desde el final
        i--;                      // Mover hacia el inicio desde el final
        if (i >= j) //si aún no se cruzan, imprime el carácter en posición
        {
            printf("%c", mensaje[j]); // Imprimir desde el inicio
            j++;                      // Mover hacia el final desde el inicio
        }
    }
    printf("\n");
}
