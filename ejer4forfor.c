#include<stdio.h>

void entrad(float * );
void determinar(float *, int *);
void salida(float * ,int * );

void main(){
	int paquete;
	float dinero;
	entrad(&dinero);
	determinar(&dinero, &paquete);
	salida(&dinero, &paquete);


}

void entrad(float * dinero){
	printf("ingrese el dinero obtenido\n");
	scanf("%f", dinero);

}
void determinar(float * dinero, int * paquete){
	if (*dinero >= 50000){
		*paquete = 1;

	} else if (*dinero >= 20000) {
        *paquete = 2;
    } else if (*dinero >= 10000) {
        *paquete = 3;
    } else {
        *paquete = 4;
    }
}

void salida(float * dinero, int * paquete){
	switch (*paquete) {
        case 1:
            printf("Paquete A: Una television, un modular, tres pares de zapatos, cinco camisas y cinco pantalones.\n");
            break;
        case 2:
            printf("Paquete B: Una grabadora, tres pares de zapatos, cinco camisas y cinco pantalones.\n");
            break;
        case 3:
            printf("Paquete C: Dos pares de zapatos, tres camisas y tres pantalones.\n");
            break;
        case 4:
            printf("Paquete D: Un par de zapatos, dos camisas y dos pantalones.\n");
            break;
        default:
            printf("Opcion invalida.\n");
    }
}