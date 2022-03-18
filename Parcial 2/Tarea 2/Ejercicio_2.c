#include <stdio.h>
#define MAX 8

int buscar_indice(int arr[MAX], int ind_inicio, int ind_final, int obj);

int main()
{
    int arr[] = {6, 8, 10, 11, 13, 33, 55, 102};
    int obj;
    printf("Dime el número objetivo que quieres buscar: \n");
    scanf("%i", &obj);
    buscar_indice(arr, 0, MAX - 1, obj);
}

int buscar_indice(int arr[MAX], int ind_inicio, int ind_final, int obj)
{
    if(arr[ind_inicio] == obj)
    {
        printf("El valor buscado se encuentra en el indice %i\n", ind_inicio);
        return 0;
    }

    if(arr[ind_final] == obj)
    {
        printf("El valor buscado se encuentra en el indice %i\n", ind_final);
        return 0;
    }

    if(obj > arr[ind_final])
    {
        printf("El valor buscado no se encuentra en el arreglo, pero debería estar en  el indice %i\n", ind_final + 1);
        return 0;
    }

    if(obj < arr[ind_inicio])
    {
        printf("El valor buscado no se encuentra en el arreglo, pero debería estar en  el indice %i\n", ind_inicio - 1);
        return 0;
    }

    if(ind_inicio + 1 == ind_final)
    {
        printf("El valor buscado no se encuentra en el arreglo, pero debería estar en  el indice %i\n", ind_inicio + 1);
        return 0;
    }

    int mitad = ((ind_final - ind_inicio) / 2) + ind_inicio;
    if(obj < arr[mitad])
        buscar_indice(arr, ind_inicio, mitad, obj);
    else 
        buscar_indice(arr, mitad, ind_final, obj);
}