#include <stdio.h>
#include "../queue.h"

int main()
{
    int n, k;
    Cola cola_1;
    Cola cola_2;
    inicializarCola(&cola_1);

    printf("Dime la cantidad de personas que jugaran, el maximo posible son %i:\n", MAX);
    scanf("%i", &n);
    printf("Dime el número para los saltos:\n");
    scanf("%i", &k);

    for(int i = 1 ; i <= n ; i++)
        insertarCola(&cola_1, i);

    for(int i = 0 ; i < n - 1 ; i++)
    {
        inicializarCola(&cola_2);
        int totalElementosCola_1 = totalElementosCola(&cola_1);
        int indiceFuera = (k % totalElementosCola_1) - 1;

        if(indiceFuera == -1)
            indiceFuera = totalElementosCola_1 - 1;

        int ind = indiceSiguiente(&cola_1, indiceFuera);

        for(int j = 0 ; j < totalElementosCola_1 - 1 ; j++)
        {
            insertarCola(&cola_2, cola_1.datos[ind]);
            ind = indiceSiguiente(&cola_1, ind);
        }

        inicializarCola(&cola_1);
        int totalElementosCola_2 = totalElementosCola_1 - 1;
        for(int j = 0 ; j < totalElementosCola_2 ; j++)
            insertarCola(&cola_1, cola_2.datos[j]);
    }

    int ganador = cola_1.datos[0];
    printf("El jugador ganador es el jugador %i", ganador);

    return 0;
}