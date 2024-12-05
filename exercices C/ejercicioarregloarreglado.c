#include <stdio.h>
void busqueda(int *, int n, int elem);
void darNumElem(int *);
void insertarDatos(int *, int);
int darElem(int elem);
void busquedaRept(int *, int n, int elem);
void salida(int i);
void mostrar(int *, int);
void copiar(int *, int *, int n);
void menu(int *, int n, int *);

#define MAX 10

void main(){
	int n, elem, num[MAX], num2[MAX];
	darNumElem(&n);
	insertarDatos(num, n);
	menu(num, n, num2);
}
void menu(int * num, int n, int * num2){
	int opc, elem;
	char op;
	do{

	printf("Ingrese una opcion a la cual ejecutar: \n");
    printf("1.- Busqueda de un solo elemento en el arreglo. \n");
    printf("2.- Copiar elementos de un arreglo en otro. \n");
    printf("3.- Busqueda de elementos repetidos. \n");
    printf("4.- Mostrar los elemnos del arreglo. \n");
    scanf("%d", &opc);
    switch(opc){
    case 1: elem = darElem(elem);
    	busqueda(num, n, elem);
    	break;
    case 2: copiar(num, num2, n);
    	break;
    case 3: elem = darElem(elem);
    	busquedaRept(num, n, elem);
    	break;
    case 4: mostrar(num, n);
    	break;
    default:
    	printf("ingrese una opcion valida\n");
    	break;
    }
    printf("desea repetir el programa? (s/n):\n");
    scanf("%c", &op);
	}
	while(op == 's' || op == 'S');
}
void busqueda(int * num, int n, int elem){
	int i;
	for (int i = 0; i < n; ++i)
	{
		if (elem==num[i])
		{
			salida(i);
			break;
		}
	}
	if (i==n){
		printf("el elemento no se encuentra en el arreglo\n");
	}
}

int darElem(int elem){
	printf("Ingrese el elemento a buscar: \n");
	scanf("%d", elem);
	return elem;
}

void darNumElem(int * n){
	printf("ingrese el numero de elementos: \n");
	scanf("%d", n);
}

void insertarDatos(int * num, int n){
	int i;
	for (int i = 0; i < n; ++i)
	{
		printf("Elemento[%d]:", i + 1);
		scanf("%d", &num[i]);
	}
}

void busquedaRept(int* num, int n, int elem){
	int i, cont=0;
	for (int i = 0; i < n; ++i)
	{
		if(elem == num[i]){
			cont++;
		}
	}
	printf("el elemento se repite %d veces \n", cont);
	for (int i = 0; i < n; ++i)	{
		if (elem == num[i]){
			salida(i);
		}
	}
}

void salida(int i){
	printf("El elemento esta en la posicion %d\n", i+1);
}
void mostrar(int * num, int n){
	int i;
	printf("\n Los elementos son \n");
	for (int i = 0; i < n; ++i)
	printf("Dato [%d] = %d\n", i + 1, num[i]);

}
void copiar(int * num, int * num2, int n){
	int i;
	for (int i = 0; i < n; ++i)
	{
		num2[i]=num[i];
	}
}


