#include <stdio.h>

// Declaración de funciones
void pedirDatos(int *N, float *sueldoBase);
float calcularComisiones();
void calcularTotalVendedor(int *N, float *sueldoBase);

int main() {
    int N;           // Número de vendedores
    float sueldoBase; // Sueldo base de cada vendedor

    // Pedir número de vendedores y sueldo base
    pedirDatos(&N, &sueldoBase);

    // Calcular comisiones y totales para cada vendedor
    calcularTotalVendedor(&N, &sueldoBase);

    return 0;
}

// Función para pedir el número de vendedores y el sueldo base
void pedirDatos(int *N, float *sueldoBase) {
    printf("Ingrese el numero de vendedores: ");
    scanf("%d", N);
    printf("Ingrese el sueldo base de cada vendedor: $");
    scanf("%f", sueldoBase);
}

// Función para calcular las comisiones de tres ventas (sin usar arreglos)
float calcularComisiones() {
    float venta1, venta2, venta3, comision;

    // Pedir montos de las tres ventas
    printf("  Ingrese el monto de la venta 1: $");
    scanf("%f", &venta1);
    printf("  Ingrese el monto de la venta 2: $");
    scanf("%f", &venta2);
    printf("  Ingrese el monto de la venta 3: $");
    scanf("%f", &venta3);

    // Calcular el 10% de comisión sobre cada venta
    comision = (venta1 + venta2 + venta3) * 0.10;

    return comision; // Devuelve la suma total de las comisiones
}

// Función para calcular y mostrar el total de cada vendedor
void calcularTotalVendedor(int *N, float *sueldoBase) {
    float comisiones, total;

    for (int i = 1; i <= *N; i++) { // Recorre cada vendedor
        printf("\nVendedor %d:\n", i);

        // Calcular comisiones de las 3 ventas
        comisiones = calcularComisiones();

        // Calcular total final (sueldo base + comisiones)
        total = *sueldoBase + comisiones;

        // Mostrar resultados
        printf("  Total de comisiones: $%.2f\n", comisiones);
        printf("  Total (sueldo base + comisiones): $%.2f\n", total);
    }
}
