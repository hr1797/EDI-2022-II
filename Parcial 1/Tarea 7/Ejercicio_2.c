#include <stdio.h>

#define MAX 10
#define LIMITE 100

int suma_valores_posiciones_pares(int enteros_a_sumar[MAX]);
int suma_valores_pares(int enteros_a_sumar[MAX]);
int suma_valores_sin_pasar_100(int enteros_a_sumar[MAX], int *elementos_sumados);

int main()
{
    int enteros[MAX], suma_sin_pasar, elementos_sumados;
    for(int i = 0 ; i < MAX ; i++){
        printf("Dime el elemento número %i entre 1 y %i:\n", i + 1, LIMITE);
        scanf("%i",&enteros[i]);
        fflush(stdin);
    }

    printf("La suma de los valores de las posiciones pares del arreglo es %i\n", 
        suma_valores_posiciones_pares(enteros));

    printf("La suma de los valores pares del arreglo es %i\n", suma_valores_pares(enteros));

    suma_sin_pasar = suma_valores_sin_pasar_100(enteros, &elementos_sumados);

    printf("La suma de los todos los valores sin pasar de 100 es %i y la cantidad de datos sumados es %i\n", 
        suma_sin_pasar, elementos_sumados);

    return 0;
}

int suma_valores_posiciones_pares(int enteros_a_sumar[MAX])
{
    int total = 0;
    for(int i = 0 ; i < MAX ; i += 2){
        total += enteros_a_sumar[i];
    }
    return total;
}

int suma_valores_pares(int enteros_a_sumar[MAX])
{
    int total = 0;
    for(int i = 0 ; i < MAX ; i++){
        if(enteros_a_sumar[i] % 2 == 0) total += enteros_a_sumar[i];
    }
    return total;
}

int suma_valores_sin_pasar_100(int enteros_a_sumar[MAX], int *elementos_sumados) 
{
    int total = 0;
    int i;
    for(i = 0 ; i < MAX ; i++){
        if(total + enteros_a_sumar[i] < LIMITE){
            total += enteros_a_sumar[i];
        } else {
            *elementos_sumados = i + 1;
            return total;
        } 
    }
    printf("%i", i);
    *elementos_sumados = i;
    return total;
}