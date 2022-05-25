#include <stdio.h>
#include "Estudiantes.h"
#include "../stack.h"

void imprimirCola(ColaEstudiantes c);
void imprimirStack(Stack s);

int main()
{
    ColaEstudiantes estudiantes_1; 
    Stack sandwiches_1; 

    inicializarCola(&estudiantes_1);
    setup(&sandwiches_1);

    char n1[] = "Juan";
    char n2[] = "Ale";
    char n3[] = "Luis";
    char n4[] = "Sofi";

    insertarCola(&estudiantes_1, n1, 1);
    insertarCola(&estudiantes_1, n2, 1);
    insertarCola(&estudiantes_1, n3, 0);
    insertarCola(&estudiantes_1, n4, 0);

    push(&sandwiches_1, 0);
    push(&sandwiches_1, 1);
    push(&sandwiches_1, 0);
    push(&sandwiches_1, 1);

    int temp_sandwich, temp_estudiante_num;
    char temp_nombre[MAX_NOMBRE];
    while(!isEmpty(sandwiches_1))
    // for(int i = 0 ; i < MAX ; i++)
    {
        imprimirCola(estudiantes_1);
        imprimirStack(sandwiches_1);

        eliminarCola(&estudiantes_1, temp_nombre, &temp_estudiante_num);
        pop(&sandwiches_1, &temp_sandwich);
        if(temp_estudiante_num != temp_sandwich)
        {
            insertarCola(&estudiantes_1, temp_nombre, temp_estudiante_num);
            push(&sandwiches_1, temp_sandwich);
        }
        printf("\n");
    }
}

void imprimirCola(ColaEstudiantes c)
{
    int i = c.inicio;
    printf("Estudiantes ");
    while(i != c.fin)
    {
        printf("\t%s-%i", c.estudiantes[i].nombre, c.estudiantes[i].sandwich);
        i = (++i) % (MAX + 1);
    }
    printf("\n");
}

void imprimirStack(Stack s)
{
    int i = 0;
    printf("Sandwiches  ");
    while(i <= s.top)
        printf("\t%i ", s.data[i++]);
    printf("\n");
}