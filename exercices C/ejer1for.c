#include <stdio.h>
int sumaWhile();
int sumaDoWhile();
int sumaFor();
void Salida(int resultado);


void main (){
	int opc, resultado =0;
	printf("escoga una opcion\n");
	printf("1-While\n");
	printf("2-Do-while\n");
	printf("3-For\n");
	printf("Ingrese su opcion\n");
	scanf("%d", &opc);


	switch (opc) {
        case 1:
            resultado = sumaWhile();
            break;
        case 2:
            resultado = sumaDoWhile();
            break;
        case 3:
            resultado = sumaFor();
            break;
        default:
            printf("Opción no válida.\n");
    }
	Salida(resultado);
}

int sumaWhile(){
	int suma=0;
	int i = 10;

	while(i<=100){
		if (i%5 == 0)
		{
			suma+= i;

		}
		i++;
	}
	return suma;
}

int sumaDoWhile(){
	int suma = 0;
	int i = 10;
	do{
		if (i%5==0)
		{
			suma+=+i;

		}
		i++;
	}
	while(i<=100);
	return suma;

}
int sumaFor(){
	int suma = 0;
	for (int i = 10; i <= 100; ++i)
	{
		if (i%5 == 0)
		{
			suma += + i;
		}
	}
	return suma;
}
void Salida(int resultado){
	printf("La suma de los multiplos es de: %d\n", resultado );
}