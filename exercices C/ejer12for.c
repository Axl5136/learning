#include <stdio.h>
#include <math.h>

// Prototipos de funciones
void leerNumero(int *M);
double calcularArea(int radio);
void imprimirAreas(int M);

int main() {
    int M;

    // Leer el número de radios (M)
    leerNumero(&M);

    // Calcular e imprimir las áreas
    imprimirAreas(M);

    return 0;
}

// Función para leer el valor de M
void leerNumero(int *M) {
    printf("Introduce el número de radios (M): ");
    scanf("%d", M);
}

// Función para calcular el área de una circunferencia dado su radio
double calcularArea(int radio) {
    return M_PI * radio * radio; // Fórmula: π * r^2
}

// Función para imprimir las áreas de las circunferencias
void imprimirAreas(int M) {
    printf("Áreas de las circunferencias con radios del 1 al %d:\n", M);
    for (int i = 1; i <= M; i++) {
        double area = calcularArea(i);
        printf("Radio %d: Área = %.4f\n", i, area);
    }
}