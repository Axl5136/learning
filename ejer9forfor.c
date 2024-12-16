#include <stdio.h>
#include <math.h>

// Declaración de funciones
void pedirCoeficientes(float *A, float *B, float *C, float *D, float *E, float *F);
void determinarGrafica(float *A, float *B, float *C);
void pedirPunto(float *x, float *y);
void determinarCuadrante(float *x, float *y);
void verificarPertenencia(float *A, float *B, float *C, float *D, float *E, float *F, float *x, float *y);

int main() {
    float A, B, C, D, E, F; // Coeficientes de la ecuación
    float x, y;             // Coordenadas del punto

    // Solicitar coeficientes de la ecuación
    pedirCoeficientes(&A, &B, &C, &D, &E, &F);

    // Determinar el tipo de gráfica
    determinarGrafica(&A, &B, &C);

    // Solicitar el punto
    pedirPunto(&x, &y);

    // Determinar en qué cuadrante está el punto
    determinarCuadrante(&x, &y);

    // Verificar si el punto pertenece a la gráfica
    verificarPertenencia(&A, &B, &C, &D, &E, &F, &x, &y);

    return 0;
}

// Función para pedir los coeficientes de la ecuación
void pedirCoeficientes(float *A, float *B, float *C, float *D, float *E, float *F) {
    printf("Ingrese los coeficientes de la ecuacion general (Ax^2 + Bxy + Cy^2 + Dx + Ey + F = 0):\n");
    printf("A: ");
    scanf("%f", A);
    printf("B: ");
    scanf("%f", B);
    printf("C: ");
    scanf("%f", C);
    printf("D: ");
    scanf("%f", D);
    printf("E: ");
    scanf("%f", E);
    printf("F: ");
    scanf("%f", F);
}

// Función para determinar el tipo de gráfica
void determinarGrafica(float *A, float *B, float *C) {
    float discriminante = (*B * *B) - (4 * (*A) * (*C));

    if (discriminante > 0) {
        printf("\nLa grafica es una hiperbola.\n");
    } else if (discriminante == 0) {
        if (*A == 0 && *C == 0) {
            printf("\nLa grafica es una recta.\n");
        } else {
            printf("\nLa grafica es una parabola.\n");
        }
    } else { // discriminante < 0
        if (*A == *C) {
            printf("\nLa grafica es una circunferencia.\n");
        } else {
            printf("\nLa grafica es una elipse.\n");
        }
    }
}

// Función para pedir las coordenadas de un punto
void pedirPunto(float *x, float *y) {
    printf("\nIngrese las coordenadas del punto (x, y):\n");
    printf("x: ");
    scanf("%f", x);
    printf("y: ");
    scanf("%f", y);
}

// Función para determinar el cuadrante del punto
void determinarCuadrante(float *x, float *y) {
    if (*x > 0 && *y > 0) {
        printf("El punto se encuentra en el primer cuadrante.\n");
    } else if (*x < 0 && *y > 0) {
        printf("El punto se encuentra en el segundo cuadrante.\n");
    } else if (*x < 0 && *y < 0) {
        printf("El punto se encuentra en el tercer cuadrante.\n");
    } else if (*x > 0 && *y < 0) {
        printf("El punto se encuentra en el cuarto cuadrante.\n");
    } else if (*x == 0 && *y != 0) {
        printf("El punto se encuentra sobre el eje Y.\n");
    } else if (*y == 0 && *x != 0) {
        printf("El punto se encuentra sobre el eje X.\n");
    } else {
        printf("El punto se encuentra en el origen.\n");
    }
}

// Función para verificar si el punto pertenece a la gráfica
void verificarPertenencia(float *A, float *B, float *C, float *D, float *E, float *F, float *x, float *y) {
    float resultado = (*A) * (*x) * (*x) + (*B) * (*x) * (*y) + (*C) * (*y) * (*y) + (*D) * (*x) + (*E) * (*y) + (*F);

    if (fabs(resultado) < 0.0001) { // Considera un pequeño margen de error
        printf("El punto (%.2f, %.2f) pertenece a la grafica.\n", *x, *y);
    } else {
        printf("El punto (%.2f, %.2f) NO pertenece a la grafica.\n", *x, *y);
    }
}
