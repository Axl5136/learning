#include <stdio.h>

void ingreso(int *, char *);
void proceso(int *, char *, float *);
void salida(float *);

void main (){
	int importe;
	char color;
	float total;

	ingreso(&importe, &color);
	proceso(&importe, &color, &total);
	salida(&total);
}
void ingreso(int * importe, char * color ){
	printf("ingrese el importe a pagar\n" );
	scanf("%d", importe);
	printf("ingrese el color de la bola\n" );
	scanf("%c", color);
}
void proceso(int * importe, char * color, float * total){
	switch(*color){
	case 'A': *total=*importe * 0.8;
		break;
	case 'R': *total = *importe * 0.7;
		break;
	case 'B': *total = *importe;
		break;
	default: printf("no escogiste ninguna opcion dada, no se aplica descuento\n");

	}
}

void salida (float * total){
	printf("el precio final es: %f\n", *total);
}
