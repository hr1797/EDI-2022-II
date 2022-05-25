#include "common.h"

typedef struct {
    int datos[MAX + 1];
    int inicio;
    int fin;
} Cola;

void inicializarCola(Cola *c);
int colaVacia(Cola cola); 
int colaLlena(Cola cola);
int insertarCola(Cola *c, int valor);
int eliminarCola(Cola *c, int *v);
int totalElementosCola(Cola *c);
int indiceSiguienteJugador(Cola *c, int indiceAnterior);

void inicializarCola(Cola *c)
{
    c->inicio = 0;
    c->fin = 0;
}

int colaVacia(Cola cola)
{
    if(cola.inicio == cola.fin)
        return 1;
    return 0;
} 

int colaLlena(Cola cola)
{
    if(cola.fin == cola.inicio - 1 || (cola.inicio == 0 && cola.fin == MAX))
        return 1;
    return 0;
}

int insertarCola(Cola *c, int valor)
{
    if(!colaLlena(*c))
    {
        c->datos[c->fin] = valor;
        c->fin = (c->fin + 1) % (MAX + 1);
        return 1;
    }
    return 0;
}

int eliminarCola(Cola *c, int *v)
{
    if(!colaVacia(*c))
    {
        *v = c->datos[c->inicio];
        c->inicio = (c->inicio + 1) % (MAX + 1);
        return 1;
    }
    return 0;
}

int totalElementosCola(Cola *c)
{
    if(colaLlena(*c))
        return MAX;
    if(c->fin < c->inicio)
        return (MAX - c->inicio + 2 + c->fin);
    return c->fin - c->inicio;
}

int indiceSiguienteJugador(Cola *c, int indiceAnterior)
{
    if(indiceAnterior == c->fin - 1)
        return c->inicio;
    return ++indiceAnterior;
}