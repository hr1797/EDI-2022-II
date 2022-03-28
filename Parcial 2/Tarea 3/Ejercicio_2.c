#include <stdio.h>

#define MAX 100

int valor_mas_repetido(int nums[]);
void inicializar_array(int arr[]);
void limitar_array(int arr[]);

int main ()
{
    int nums_1[] = {3,2,3};
    int nums_2[] = {2,2,1,1,1,2,2};
    int nums_3[] = {1,3,1,4,3,2,1,3,2,1};
    limitar_array(nums_1);
    limitar_array(nums_2);
    limitar_array(nums_3);
    printf("El valor mas repetido es: %i\n", valor_mas_repetido(nums_1));
    printf("El valor mas repetido es: %i\n", valor_mas_repetido(nums_2));
    printf("El valor mas repetido es: %i\n", valor_mas_repetido(nums_3));
}

int valor_mas_repetido(int nums[])
{
    int conteos[MAX];
    inicializar_array(conteos);
    for(int i = 0 ; nums[i] != -1 ; i++)
        ++conteos[nums[i]];

    int indice_mas_repetido = 0;
    for(int i = 1 ; i < MAX ; i++)
        if(conteos[indice_mas_repetido] < conteos[i]) 
            indice_mas_repetido = i;
    return indice_mas_repetido;
}

void inicializar_array(int arr[])
{
    for(int i = 0 ; i < MAX ; i++)
        arr[i] = 0;
}

void limitar_array(int arr[])
{
    for(int i = 0 ; i < MAX ; i++)
        if(arr[i] > MAX)
        {
            arr[i] = -1;
            break;
        }
}