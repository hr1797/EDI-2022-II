#include <stdio.h>
#include "../queue.h"
#include "../common.h"

void algoritmo_examen(Cola *c1, Cola *c2);
void imprime(Cola *c);

int main()
{
    Cola c1;
    Cola c2;
    inicializarCola(&c1);
    inicializarCola(&c2);

    insertarCola(&c1, 2);
    insertarCola(&c1, 3);
    insertarCola(&c1, 9);
    insertarCola(&c2, 1);
    insertarCola(&c2, 4);
    insertarCola(&c2, 8);
    insertarCola(&c2, 9);

    algoritmo_examen(&c1, &c2);
}

void algoritmo_examen(Cola *c1, Cola *c2)
{
    int valor1, valor2;
    int contador = 0;

    while(contador < 3)
    {
        if(eliminarCola(c1, &valor1) == 1)
        {
            if(valor1 % 2 == 0)
                insertarCola(c2, valor1);
            else 
                insertarCola(c1, valor1);
        }

        if(eliminarCola(c2, &valor2) == 1)
        {
            if(valor2 % 2 != 0)
                insertarCola(c1, valor2);
            else   
                insertarCola(c2, valor2);
        }

        contador++;
        printf("\n");
        imprime(c1);
        printf("\n");
        imprime(c2);
    }
}

void imprime(Cola *c)
{
    if(!colaVacia(*c))
    {
        int i = c->inicio;
        do 
        {
            printf("%i ", c->datos[i]);
            if(i == MAX)
                i = 0;
            else 
                ++i;
        } while(i != c->fin);
    }
}