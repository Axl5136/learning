#include <stdio.h>

void leerNumero(int *numero);
int sumarDigitos(int numero);
void mostrarResultado(int suma);

int main() {
    int numero, suma;

    leerNumero(&numero);

    suma = sumarDigitos(numero);

    mostrarResultado(suma);

    return 0;
}

void leerNumero(int *numero) {
    printf("Introduce un número entero: ");
    scanf("%d", numero);
}

int sumarDigitos(int numero) {
    int suma = 0;

    while (numero != 0) {
        suma += numero % 10; // Extraer el último dígito y sumarlo
        numero /= 10;        // Eliminar el último dígito
    }

    return suma;
}

void mostrarResultado(int suma) {
    printf("La suma de los dígitos es: %d\n", suma);
}