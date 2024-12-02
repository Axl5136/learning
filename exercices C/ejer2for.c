#include <stdio.h>
#include <math.h>

double evaluarFuncion(double x);
void mostrarResultados();

void main() {
    mostrarResultados();

}

double evaluarFuncion(double x) {
    return pow(x, 3) + 2 * x - 4;
}

void mostrarResultados() {
    double x, y;

    printf("\nResultados:\n");
    printf("x\t\tY\n");
    printf("-----------------------\n");

    for (x = 0.5; x < 15; x += 0.5) {
        y = evaluarFuncion(x);
        printf("%.2lf\t\t%.2lf\n", x, y);
    }
}