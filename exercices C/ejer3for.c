#include <stdio.h>

int Entrada(void);
void procesarNumeros(int M, int *mayoresCero, float *promedioPos, float *promedioImp);
void Resu(int mayoresCero, float promedioPos, float promedioImp);

void main() {
    int M = Entrada();

    int mayoresCero = 0;
    float promedioPos = 0, promedioImp = 0;

    procesarNumeros(M, &mayoresCero, &promedioPos, &promedioImp);

    Resu(mayoresCero, promedioPos, promedioImp);
}


int Entrada() {
    int M;
    printf("Ingrese la cantidad de números a leer: ");
    scanf("%d", &M);
    return M;
}


void procesarNumeros(int M, int *mayoresCero, float *promedioPos, float *promedioImp) {
    int numero, sumaPos = 0, sumaImp = 0;
    int contadorPos = 0, contadorImp = 0;

    for (int i = 0; i < M; i++) {
        printf("Ingrese el número %d: ", i + 1);
        scanf("%d", &numero);

        if (numero > 0) {
            (*mayoresCero)++;
            sumaPos += numero;
            contadorPos++;
        }

        if (numero % 2 != 0) {
            sumaImp += numero;
            contadorImp++;
        }
    }

    *promedioPos = (contadorPos > 0) ? (float)sumaPos / contadorPos : 0;
    *promedioImp = (contadorImp > 0) ? (float)sumaImp / contadorImp : 0;
}


void Resu(int mayoresCero, float promedioPos, float promedioImp) {
    printf("\nResultados:\n");
    printf("a) Cantidad de números mayores a 0: %d\n", mayoresCero);
    printf("b) Promedio de los números positivos: %.2f\n", promedioPos);
    printf("c) Promedio de los números impares: %.2f\n", promedioImp);
}