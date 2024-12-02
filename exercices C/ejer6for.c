#include <stdio.h>
#include <math.h>

double CalcularSerie(int n);

void main(){
	int n;
	printf("Ingresa un valor entero positivo: \n");
	scanf("%d", &n);

	if (n>0)
	{
		double res = CalcularSerie(n);
		printf("El resultado de la serie es: %f\n", res);
	}
	else{
		printf("el numero debe ser mayor a 0\n");
	}
}
double CalcularSerie(int n){
	double suma = 0.0;
	for (int i = 1; i <= 2 * n; ++i)
	{
		suma += pow(-1, i + 1) * (i+1)/i;

	}
	return suma;
}
