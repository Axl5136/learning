#include <stdio.h>
#include <stdbool.h>

void entrada(float * numero);
bool Continuar();
void salida(float suma);

void main (){
	int suma = 0;
	float numero;
	bool Conti;

	do{
		entrada(&numero);
		suma += numero;

		Conti = Continuar();

	}while(Conti);
}

void entrada(float * numero){
	printf("ingrese un nummero entero\n");
	scanf("%f", numero);
}

bool Continuar(){
	char respuesta;
	printf("desea ingresar otro numero? (s/n)\n");
	scanf("%c", &respuesta);
	return (respuesta == 's' || respuesta == 'S');
}

void salida(float suma){
	printf("la suma total de los numeros es: %f\n", suma );
}