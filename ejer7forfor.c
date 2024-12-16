#include <stdio.h>

// Declaración de funciones
void pedirDatos(int *M, int *N);
void calcularAlumnosExtraordinario(int *M, int *N, int *contadorExtra);
float calcularPromedioAlumno(int *N);

int main() {
    int M, N, contadorExtra = 0;

    // Solicitar número de alumnos y unidades
    pedirDatos(&M, &N);

    // Calcular alumnos con derecho a extraordinario
    calcularAlumnosExtraordinario(&M, &N, &contadorExtra);

    // Mostrar el total de alumnos con derecho al examen extraordinario
    printf("\nCantidad de alumnos con derecho al examen extraordinario: %d\n", contadorExtra);

    return 0;
}

// Función para pedir datos (número de alumnos y unidades)
void pedirDatos(int *M, int *N) {
    printf("Ingrese el numero de alumnos (M): ");
    scanf("%d", M);
    printf("Ingrese el numero de unidades (N): ");
    scanf("%d", N);
}

// Función para calcular cuántos alumnos tienen promedio menor a 6.0
void calcularAlumnosExtraordinario(int *M, int *N, int *contadorExtra) {
    float promedio;

    for (int i = 1; i <= *M; i++) {  // Recorre los alumnos
        printf("\nAlumno %d:\n", i);
        promedio = calcularPromedioAlumno(N);  // Calcula el promedio del alumno

        if (promedio < 6.0) {
            (*contadorExtra)++;  // Incrementa el contador si el promedio es menor a 6
        }
    }
}

// Función para calcular el promedio de un alumno
float calcularPromedioAlumno(int *N) {
    float suma = 0, calificacion;

    for (int i = 1; i <= *N; i++) {  // Recorre las unidades
        printf("  Calificacion de la unidad %d: ", i);
        scanf("%f", &calificacion);
        suma += calificacion;  // Suma las calificaciones
    }

    return suma / (*N);  // Devuelve el promedio
}
