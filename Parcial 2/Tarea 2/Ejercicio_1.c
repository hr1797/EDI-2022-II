#include <stdio.h>
#define MAX 100

void pedir_nombres(char nombres[MAX][MAX], int cant_nombres);
int buscar_nombre(char nombres[MAX][MAX], char nombre[MAX], int cant_nombres);

int main()
{
    char nombres[MAX][MAX];
    char nombre[MAX];
    int cant_nombres, ind_nombre;

    printf("¿Cuántos nombres te gustaría agregar?\n");
    scanf("%i", &cant_nombres);
    fflush(stdin);

    pedir_nombres(nombres, cant_nombres);
    printf("¿Cuál es el nombre que te gustaría buscar en la lista?\n");
    scanf("%[^\n]", &nombre);
    fflush(stdin);

    ind_nombre = buscar_nombre(nombres, nombre, cant_nombres);
    if(ind_nombre != -1)
        printf("El nombre buscado esta en la posición %i", ind_nombre);
    else 
        printf("No se encontro el nombre");
}

void pedir_nombres(char nombres[MAX][MAX], int cant_nombres)
{
    for(int ind_nombres = 0 ; ind_nombres < cant_nombres ; ++ind_nombres)
    {
        printf("Nombre %i: ", ind_nombres + 1);
        scanf("%[^\n]", &nombres[ind_nombres]);
        fflush(stdin);
    }
}

int buscar_nombre(char nombres[MAX][MAX], char nombre[MAX], int cant_nombres)
{
    for(int ind_nombres = 0 ; ind_nombres < cant_nombres ; ++ind_nombres)
    {
        for(int letra = 0 ; letra < MAX && nombre[letra] != '\0' ; ++letra)
        {
            if(nombres[ind_nombres][letra] != nombre[letra]) 
                break;
            if(nombres[ind_nombres][letra + 1] == '\0' && nombre[letra + 1] == '\0') 
                return ind_nombres;
        }
    }
    return -1;
}