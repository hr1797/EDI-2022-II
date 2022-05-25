#include <string.h>
#include "../common.h"

#define MAX_NOMBRE 10

typedef struct {
    char nombre[MAX_NOMBRE];
    int sandwich;
} Estudiante;

typedef struct {
    Estudiante estudiantes[MAX + 1];
    int inicio;
    int fin;
} ColaEstudiantes;

void inicializarCola(ColaEstudiantes *c);
int colaVacia(ColaEstudiantes cola); 
int colaLlena(ColaEstudiantes cola);
int insertarCola(ColaEstudiantes *c, char nombre[MAX_NOMBRE], int valor);
int eliminarCola(ColaEstudiantes *c, int *v);
int totalElementosCola(ColaEstudiantes *c);
int indiceSiguienteJugador(ColaEstudiantes *c, int indiceAnterior);

void inicializarCola(ColaEstudiantes *c)
{
    c->inicio = 0;
    c->fin = 0;
}

int colaVacia(ColaEstudiantes cola)
{
    if(cola.inicio == cola.fin)
        return 1;
    return 0;
} 

int colaLlena(ColaEstudiantes cola)
{
    if(cola.fin == cola.inicio - 1 || (cola.inicio == 0 && cola.fin == MAX))
        return 1;
    return 0;
}

int insertarCola(ColaEstudiantes *c, char nombre[MAX_NOMBRE], int valor)
{
    if(!colaLlena(*c))
    {
        Estudiante temp;
        strcpy(temp.nombre, nombre);
        temp.sandwich = valor;
        c->estudiantes[c->fin] = temp;
        c->fin = (c->fin + 1) % (MAX + 1);
        return 1;
    }
    return 0;
}

int eliminarCola(ColaEstudiantes *c, char nombre[], int *sandwich)
{
    if(!colaVacia(*c))
    {
        strcpy(nombre, c->estudiantes[c->inicio].nombre);
        *sandwich = c->estudiantes[c->inicio].sandwich;
        c->inicio = (c->inicio + 1) % (MAX + 1);
        return 1;
    }
    return 0;
}

int totalElementosCola(ColaEstudiantes *c)
{
    if(colaLlena(*c))
        return MAX;
    if(c->fin < c->inicio)
        return (MAX - c->inicio + 2 + c->fin);
    return c->fin - c->inicio;
}

int indiceSiguienteJugador(ColaEstudiantes *c, int indiceAnterior)
{
    if(indiceAnterior == c->fin - 1)
        return c->inicio;
    return ++indiceAnterior;
}