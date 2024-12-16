#include <stdio.h>

// Declaración de funciones
void pedirDatos(int *G, int *N, int *M);
void calcularPromedios(int *G, int *N, int *M, float *promedioGrupos);
float promedioAlumno(int M);
void mostrarResultados(int *G, float *promedioGrupos);

int main() {
    int G, N, M;
    float promedioGrupos;

    // Pedir datos iniciales
    pedirDatos(&G, &N, &M);

    // Calcular los promedios
    calcularPromedios(&G, &N, &M, &promedioGrupos);

    // Mostrar resultados
    mostrarResultados(&G, &promedioGrupos);

    return 0;
}

// Función para pedir el número de grupos, alumnos y materias
void pedirDatos(int *G, int *N, int *M) {
    printf("Ingrese el numero de grupos (G): ");
    scanf("%d", G);
    printf("Ingrese el numero de alumnos por grupo (N): ");
    scanf("%d", N);
    printf("Ingrese el numero de materias por alumno (M): ");
    scanf("%d", M);
}

// Función para calcular los promedios de cada grupo
void calcularPromedios(int *G, int *N, int *M, float *promedioGrupos) {
    float sumaGrupo = 0, promedioAlumnoActual;

    for (int i = 1; i <= *G; i++) {  // Recorre grupos
        sumaGrupo = 0;
        printf("\nGrupo %d:\n", i);

        for (int j = 1; j <= *N; j++) {  // Recorre alumnos
            printf("  Alumno %d\n", j);
            promedioAlumnoActual = promedioAlumno(*M);  // Calcula promedio de un alumno
            printf("    Promedio del alumno: %.2f\n", promedioAlumnoActual);
            sumaGrupo += promedioAlumnoActual;
        }

        printf("  Promedio del grupo %d: %.2f\n", i, sumaGrupo / (*N));
        *promedioGrupos += sumaGrupo / (*N);  // Acumula promedio de cada grupo
    }

    *promedioGrupos /= *G;  // Calcula promedio general de todos los grupos
}

// Función para calcular el promedio de un alumno
float promedioAlumno(int M) {
    float sumaMaterias = 0, calificacion, promedioMateria;

    for (int i = 1; i <= M; i++) {  // Recorre materias
        sumaMaterias = 0;
        printf("    Materia %d:\n", i);

        for (int j = 1; j <= 3; j++) {  // Promedia 3 calificaciones
            printf("      Calificacion %d: ", j);
            scanf("%f", &calificacion);
            sumaMaterias += calificacion;
        }

        promedioMateria = sumaMaterias / 3;
        printf("      Promedio de la materia: %.2f\n", promedioMateria);
        sumaMaterias += promedioMateria;
    }

    return sumaMaterias / M;  // Promedio final del alumno
}

// Función para mostrar los resultados finales
void mostrarResultados(int *G, float *promedioGrupos) {
    printf("\nPromedio general de todos los grupos: %.2f\n", *promedioGrupos);
}
