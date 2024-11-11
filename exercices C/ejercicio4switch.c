#include <stdio.h>

void Entrada(int *);
void proceso(int *, int *);
void Salida(int *);

void main(){
    int monto, res;
    Entrada(&monto);
    proceso(&monto, &res);
    Salida(&res);
}
void Entrada(int * monto){
    printf("ingresa el monto\n" );
    scanf("%d", monto);
}
void proceso(int * monto, int * res){
    if (*monto > 1000)
    {
        *res = *monto * 0.8;      /* code */
    }else {
        *res = *monto;
    }
}
void Salida(int * res){
    printf("la cantidad q pagara sera: %d\n", *res);

}
