#include<stdio.h>

void Entrada();
void verificar();
void proceso();
void salida();


void main (){
	int numero, cifras;
	Entrada(&numero);
	verificar(&numero);
	proceso(&numero, &cifras);
	salida(& numero, &cifras);

}

void Entrada(int * numero){
	printf("ingrese un numero entero positivo: \n");
	scanf("%d", numero);

}

void verificar(int * numero){
	while (*numero < 0){
		printf("el numero debe ser positivo, intenta de nuevo\n");
		scanf("%d", numero);

	}
}
void proceso (int * numero, int * cifras){
	*cifras = 0;
	int temp = *numero;

	while (temp > 0){
		temp /= 10;
		(*cifras)++;
	}
}

void salida(int * numero, int * cifras){
	printf("el numero %d tiene %d cifras\n", *numero, *cifras);
}