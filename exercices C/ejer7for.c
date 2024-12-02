#include <stdio.h>

int Entrada();
void proceso(int cantidad, int * amarilla, int * rosa, int * roja, int * verde, int * azul);
void Salida(int amarilla, int rosa, int roja, int verde, int azul);

void main(){
	int cantidad, amarilla = 0, rosa = 0, roja = 0, verde = 0, azul = 0;
	cantidad = Entrada();
	proceso(cantidad, &amarilla, &rosa, &roja, &verde, &azul);
	Salida(amarilla, rosa, roja, verde, azul);

}
int Entrada(){
	int cantidad;
	printf("ingrese la cantidad de autos\n");
	scanf("%d", &cantidad);
	return cantidad;
}
void proceso(int cantidad, int * amarilla, int * rosa, int * roja, int * verde, int * azul){
	int digito;
	for (int i = 0; i < cantidad; ++i)
	{
		printf("ingrese el ultimo digito de la placa:%d\n", i + 1);
		scanf("%d", &digito);
		if (digito == 1 || digito == 2)
		{
			(*amarilla)++;
		}
		else if (digito == 3 || digito == 4)
		{
			(*rosa)++;
		}
		else if (digito == 5 || digito == 6)
		{
			(*roja)++;
		}
		else if (digito == 7 || digito == 8)
		{
			(*verde)++;
		}
		else if (digito == 9 || digito == 0)
		{
			(*azul)++;
		} else{
			printf("digito invalido\n");
		i--;
		}

	}

}

void Salida(int amarilla, int rosa, int roja, int verde, int azul){
	printf("\nResultados:\n");
    printf("Amarilla: %d\n", amarilla);
    printf("Rosa: %d\n", rosa);
    printf("Roja: %d\n", roja);
    printf("Verde: %d\n", verde);
    printf("Azul: %d\n", azul);
}