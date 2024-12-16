#include <stdio.h>
#include <math.h>

// Declaración de funciones
void menuPrincipal();
void menuTrigonometrico();
void menuMatematico();
void calcularSeno();
void calcularCoseno();
void calcularTangente();
void elevarPotencia();
void raizCuadrada();
void logaritmo();

int main() {
    menuPrincipal();
    return 0;
}

void menuPrincipal(){
    int opc;
    do {
        printf("\nMenú principal\n");
        printf("1) Funciones trigonométricas\n");
        printf("2) Funciones matemáticas\n");
        printf("3) Salida\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opc);

        switch(opc){
        case 1: menuTrigonometrico();
            break;
        case 2: menuMatematico();
            break;
        case 3:
            printf("Saliendo del programa\n");
        default: printf("opcion no valida\n");
        }
    }
        while(opc !=3);
}

void menuTrigonometrico(){
    int opcion;
    double angulo;
    do{
        printf("\nMenú de Funciones Trigonométricas\n");
        printf("1) Seno de β\n");
        printf("2) Coseno de β\n");
        printf("3) Tangente de β\n");
        printf("4) Regreso al menú anterior\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion){
        case 1: calcularSeno();
            break;
        case 2: calcularCoseno();
            break;
        case 3: calcularTangente();
            break;
        case 4: printf("regresando al menu principal\n");
            break;
        default: printf("opcion no valida\n");
        }

    }while (opcion != 4);
}

void menuMatematico() {
    int opcion;
    do {
        printf("\nMenú de Funciones Matemáticas\n");
        printf("1) Elevar un número a cualquier potencia\n");
        printf("2) Obtener la raíz cuadrada de cualquier número\n");
        printf("3) El logaritmo de un número\n");
        printf("4) Regreso al menú anterior\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                elevarPotencia();
                break;
            case 2:
                raizCuadrada();
                break;
            case 3:
                logaritmo();
                break;
            case 4:
                printf("Regresando al menú principal...\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 4);
}

void calcularSeno() {
    double angulo;
    printf("Ingrese el ángulo en grados: ");
    scanf("%lf", &angulo);
    printf("El seno de %.2f es %.2f\n", angulo, sin(angulo * M_PI / 180));
}
void calcularCoseno() {
    double angulo;
    printf("Ingrese el ángulo en grados: ");
    scanf("%lf", &angulo);
    printf("El coseno de %.2f es %.2f\n", angulo, cos(angulo * M_PI / 180));
}

void calcularTangente() {
    double angulo;
    printf("Ingrese el ángulo en grados: ");
    scanf("%lf", &angulo);
    printf("La tangente de %.2f es %.2f\n", angulo, tan(angulo * M_PI / 180));
}

void elevarPotencia() {
    double base, exponente;
    printf("Ingrese la base: ");
    scanf("%lf", &base);
    printf("Ingrese el exponente: ");
    scanf("%lf", &exponente);
    printf("%.2f elevado a %.2f es %.2f\n", base, exponente, pow(base, exponente));
}

void raizCuadrada() {
    double numero;
    printf("Ingrese un número: ");
    scanf("%lf", &numero);
    if (numero >= 0)
        printf("La raíz cuadrada de %.2f es %.2f\n", numero, sqrt(numero));
    else
        printf("No es posible calcular la raíz cuadrada de un número negativo.\n");
}

void logaritmo() {
    double numero;
    printf("Ingrese un número: ");
    scanf("%lf", &numero);
    if (numero > 0)
        printf("El logaritmo de %.2f es %.2f\n", numero, log10(numero));
    else
        printf("No es posible calcular el logaritmo de un número menor o igual a 0.\n");
}