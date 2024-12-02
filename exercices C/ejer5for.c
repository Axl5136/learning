#include <stdio.h>


void serieStanislaw(int numero);

void main (){
	int numero;
	printf("ingree un numero entero\n");
	scanf("%d", &numero);

	printf("Serie generada \n");
	serieStanislaw(numero);
}

void serieStanislaw(int numero){
	while(numero != 1){
		printf("%d, ", numero );
		if (numero % 2 == 0)
		{
			numero/=2;

		}
		else{
			numero = numero * 3 + 1;
		}

	}
	printf("1\n");
}