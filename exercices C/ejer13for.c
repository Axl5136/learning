#include <stdio.h>
void leerNota(float *nota);
void calcularResultados(int *aprobadas, int *reprobadas, float *promedioAprobadas, float *promedioReprobadas, int N);
void mostrarResultados(int aprobadas, int reprobadas, float promedioAprobadas, float promedioReprobadas);
int main() {
    int N, aprobadas = 0, reprobadas = 0;
    float promedioAprobadas = 0, promedioReprobadas = 0;

    printf("Introduce el número de notas: ");
    scanf("%d", &N);

    calcularResultados(&aprobadas, &reprobadas, &promedioAprobadas, &promedioReprobadas, N);

    mostrarResultados(aprobadas, reprobadas, promedioAprobadas, promedioReprobadas);

    return 0;
}
void leerNota(float *nota) {
    printf("Introduce una nota: ");
    scanf("%f", nota);
}
void calcularResultados(int *aprobadas, int *reprobadas, float *promedioAprobadas, float *promedioReprobadas, int N) {
    float nota, sumaAprobadas = 0, sumaReprobadas = 0;
    for (int i = 1; i <= N; i++) {
        // Leer una nota
        leerNota(&nota);

        // Clasificar la nota y acumular resultados
        if (nota >= 6.0) {
            (*aprobadas)++;
            sumaAprobadas += nota;
        } else {
            (*reprobadas)++;
            sumaReprobadas += nota;
        }
    }

    // Calcular promedios
    if (*aprobadas > 0) {
        *promedioAprobadas = sumaAprobadas / (*aprobadas);
    }
    if (*reprobadas > 0) {
        *promedioReprobadas = sumaReprobadas / (*reprobadas);
    }
}
void mostrarResultados(int aprobadas, int reprobadas, float promedioAprobadas, float promedioReprobadas) {
    printf("\nResultados:\n");
    printf("Notas aprobadas: %d\n", aprobadas);
    printf("Notas reprobadas: %d\n", reprobadas);
    if (aprobadas > 0) {
        printf("Promedio de notas aprobadas: %.2f\n", promedioAprobadas);
    } else {
        printf("Promedio de notas aprobadas: No hay notas aprobadas.\n");
    }
    if (reprobadas > 0) {
        printf("Promedio de notas reprobadas: %.2f\n", promedioReprobadas);
    } else {
        printf("Promedio de notas reprobadas: No hay notas reprobadas.\n");
    }
}