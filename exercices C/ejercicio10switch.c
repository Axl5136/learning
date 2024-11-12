#include <stdio.h>

void ingreso (int *, char *);
void proceso(int *, char *, float *);
void salida(float * );

void main (){
	int horas;
	char clase;
	float total;
	ingreso(&horas,&clase);
	proceso(&horas,&clase, &total);
	ingreso(&total);
}

void ingreso(int * horas, char * clase){
	printf("Ingresa las horas trabajadas\n" );
	scanf("%d", horas);
	printf("Ingresa la clase de trabajador\n" );
	scanf("%c", clase);
}

void proceso(int * horas, char * clase, float * total){
	switch(*clase){
	case 'A': *total: *horas * 7;
		break;
	case 'B': *total: *horas * 5;
		break;
	case 'C': *total: *horas * 4;
		break;
	case 'C': *total: *horas * 3.5;
		break;
	default: printf("clase no valida\n");

	}
}
void salida(float * total){
	printf("el total del sueldo del trabajador es de: %f\n", *total );
}
