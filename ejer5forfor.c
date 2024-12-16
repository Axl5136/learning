#include <stdio.h>

void pedirValor(int *n);
void figuraA(int *n);
void figuraB(int *n);
void figuraC(int *n);
void figuraD(int *n);

int main() {
    int n;


    pedirValor(&n);

    // Mostrar figuras
    printf("\nFigura A:\n");
    figuraA(&n);

    printf("\nFigura B:\n");
    figuraB(&n);

    printf("\nFigura C:\n");
    figuraC(&n);

    printf("\nFigura D:\n");
    figuraD(&n);

    return 0;
}

void pedirValor(int *n) {
    printf("Ingrese un valor entero N: ");
    scanf("%d", n);
}

void figuraA(int *n) {
    for (int i = 1; i <= *n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void figuraB(int *n) {
    for (int i = *n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void figuraC(int *n) {
    for (int i = 1; i <= *n; i++) {
        for (int j = 1; j <= *n - i; j++) {
            printf(" ");
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }
}

void figuraD(int *n) {
    for (int i = *n; i >= 1; i--) {
        for (int j = 1; j <= *n - i; j++) {
            printf(" ");
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }
}
