#include <stdio.h>

void entrada(int * presopuesto);
void determinarregalo(int * presopuesto, int * opcion);
void salida(int * presopuesto, int * opcion);

void main(){
	int presopuesto;
	int opcion;

	entrada(&presopuesto);
	determinarregalo(&presopuesto, &opcion);
	salida(&presopuesto, &opcion);

}

void entrada(int * presopuesto){
	printf("ingresa el presopuesto disponible: \n");
	scanf("%d", presopuesto);

}
void determinarregalo(int * presopuesto, int * opcion){
	*opcion = 0;
	if (*presopuesto <= 10)
	{
		*opcion = 1;
	} else if (*presopuesto <=100){
		*opcion = 2;
	}else if (*presopuesto <=250){
		*opcion = 3;
	}else {
		*opcion = 4;
	}
}

void salida(int * presopuesto, int * opcion){
	printf("su presopuesto es de  %d\n", *presopuesto );
	switch(*opcion){
	case 1: printf("usted puede comprar la tarjeta\n");
		break;
	case 2: printf("usted puede comprar chocolate\n");
		break;
	case 3: printf("usted puede comprar las flores\n");
		break;
	case 4: printf("usted puede comprar anillo\n");
		break;
	default : printf("no hay opciones disponible\n");

	}
}