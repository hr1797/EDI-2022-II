#include <stdio.h>

int main(){
    float precio, descuento;
    
    printf("Indicame el precio del producto\n");
    scanf("%f", &precio);
    printf("Con valores de entre 0 a 100, indicame el descuento del producto\n");
    scanf("%f", &descuento);
    precio = precio - precio * (descuento / 100);
    printf("Precio con descuento = %.2f\n", precio);

    return 0;
}