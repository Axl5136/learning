#include <stdio.h>

void Entrada(int * opc);
void proceso(int * opc);
void suma(int, int);
void resta(int, int);
void multi(int, int);
void divi(int, int);
void SALIR();
void menu();

void main(){
	int opc;
	do{

	menu();
	Entrada(&opc);
	proceso(&opc);
	} while(opc != 5);

}
void menu(){
	printf("________________\n");
	printf("|  CALCULADORA\n");
	printf("|  1. SUMA\n");
	printf("|  2. RESTA\n"  );
	printf("|  3. MULTIPLICACION\n");
	printf("|  4. DIVISION\n");
	printf("|  5. SALIR\n");
	printf("|________________\n");

}
void Entrada(int * opc){
	printf("Ingrese la opcion requerida\n");
	scanf("%d", opc);
}
void proceso(int * opc){
	int a, b;
	if (*opc >= 1 && *opc<=4)
	{
		printf("ingrese el primer numero\n");
		scanf("%d", &a);
		printf("ingrese el segundo numero\n");
		scanf("%d", &b);
	}
	switch(*opc){
	case 1: suma(a, b);
	break;
	case 2: resta(a, b);
	break;
	case 3: multi(a, b);
	break;
	case 4: divi(a, b);
	break;
	case 5: SALIR();
	break;

	default: printf("opc no valida\n" );
	}
}
void suma (int a, int b){
	printf("la suma de los numeros es: %d\n", a + b );
}
void resta (int a, int b){
	printf("la suma de los numeros es: %d\n", a + b );
}
void multi (int a, int b){
	printf("la suma de los numeros es: %d\n", a + b );
}
void divi (int a, int b){
	if (b != 0)
	{
		printf("la division de los numeros es: %d\n", a/b);
	}else {
		printf("la divsion entre cero no es valida ERROR\n");
	}
}
void SALIR(){
	printf("SALIENDO DEL PROGRAMAA\n");
}
