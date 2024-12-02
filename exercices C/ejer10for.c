#include <stdio.h>
#include <math.h>

// Prototipos de funciones
void leerDatos(float *a, float *b, int *n);
float calcularNumerador(float a, float b, int n);
float calcularDenominador(float a, int n);
void mostrarResultado(float x);

int main() {
    float a, b, x;
    int n;

    // Leer los datos de entrada
    leerDatos(&a, &b, &n);

    // Calcular el numerador y el denominador
    float numerador = calcularNumerador(a, b, n);
    float denominador = calcularDenominador(a, n);

    // Calcular el resultado de x
    x = numerador / denominador;

    // Mostrar el resultado
    mostrarResultado(x);

    return 0;
}

// Función para leer los datos de entrada
void leerDatos(float *a, float *b, int *n) {
    printf("Introduce el valor de a (decimal): ");
    scanf("%f", a);
    printf("Introduce el valor de b (decimal): ");
    scanf("%f", b);
    printf("Introduce el valor de n (entero): ");
    scanf("%d", n);
}

// Función para calcular el numerador
float calcularNumerador(float a, float b, int n) {
    float suma = 0;
    for (int i = 1; i <= n; i++) {
        suma += pow(a - b, i) - 3 + n;
    }
    return suma;
}

// Función para calcular el denominador
float calcularDenominador(float a, int n) {
    float producto = 1;
    for (int i = 2; i <= n - 1; i++) {
        producto *= (2 + a * (i - 1));
    }
    return producto;
}

// Función para mostrar el resultado
void mostrarResultado(float x) {
    printf("El valor de x es: %.4f\n", x);
}