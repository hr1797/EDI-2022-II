#include <stdio.h>
#include <limits.h>

#define TOTAL_PRODUCTOS 4

int main () {
    int clave_mayor_precio = 0, mayor_precio = 0;
    int clave_menor_stock = 0, menor_stock = INT_MAX;
    float total_ventas = 0;

    int claves[TOTAL_PRODUCTOS], stocks[TOTAL_PRODUCTOS];
    float precios[TOTAL_PRODUCTOS];

    char clave[] = "id o clave";
    char precio[] = "precio"; 
    char stock[] = "stock";

    for(int fila = 0 ; fila < TOTAL_PRODUCTOS ; fila++)
    {
        for(int columna = 0 ; columna < 3; columna++)
        {
            switch (columna)
            {
                case 0:
                    printf("Indicame el %s del producto número %i\n", clave, fila + 1);
                    scanf("%i", &claves[fila]);
                    fflush(stdin);
                    break;
                case 1:
                    printf("Indicame el %s del producto número %i\n", precio, fila + 1);
                    scanf("%f", &precios[fila]);
                    fflush(stdin);
                    if(precios[fila] > mayor_precio){
                        mayor_precio = precios[fila];
                        clave_mayor_precio = claves[fila];
                    }
                    break;
                case 2:
                    printf("Indicame el %s del producto número %i\n", stock, fila + 1);
                    scanf("%i", &stocks[fila]);
                    fflush(stdin);
                    if(stocks[fila] < menor_stock){
                        menor_stock = stocks[fila];
                        clave_menor_stock = claves[fila];
                    }
                    total_ventas += precios[fila] * stocks[fila];            
                    break;
            }
        }
    }
    printf("Producto con mayor precio: %i\n", clave_mayor_precio);
    printf("Producto con menos stock: %i\n", clave_menor_stock);
    printf("Total de venta esperada: %f.2", total_ventas);

    return 0;
}