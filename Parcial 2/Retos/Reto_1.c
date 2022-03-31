#include <stdio.h>

#define MAX 5

void multiplicar_arreglo(int nums[], int res[]);
void multiplicar_arreglo_r(int nums[], int res[], int ind_int, int ind_ext);
void inicializar_arr(int nums[], int valor);

int main()
{
    int nums_1[MAX] = {1,2,3,4,5}; 
    int nums_2[MAX] = {-1,1,0,-3,3}; 
    int nums_3[MAX] = {-4,2,6,8,11}; 
    int res_1[MAX]; 
    int res_2[MAX]; 
    int res_3[MAX]; 
     
    inicializar_arr(res_1, 1);
    inicializar_arr(res_2, 1);
    inicializar_arr(res_3, 1);

    multiplicar_arreglo(nums_1, res_1);
    multiplicar_arreglo(nums_2, res_2);
    multiplicar_arreglo(nums_3, res_3);

    printf("La salida del arreglo 1 usando ciclos es: \n");
    for(int j = 0 ; j < MAX ; j++)
        printf(" %i ", res_1[j]);
    printf("\nLa salida del arreglo 2 usando ciclos es: \n");
    for(int j = 0 ; j < MAX ; j++)
        printf(" %i ", res_2[j]);
    printf("\nLa salida del arreglo 3 usando ciclos es: \n");
    for(int j = 0 ; j < MAX ; j++)
        printf(" %i ", res_3[j]);

    inicializar_arr(res_1, 1);
    inicializar_arr(res_2, 1);
    inicializar_arr(res_3, 1);

    multiplicar_arreglo_r(nums_1, res_1, 0, 0);
    multiplicar_arreglo_r(nums_2, res_2, 0, 0);
    multiplicar_arreglo_r(nums_3, res_3, 0, 0);

    printf("\nLa salida del arreglo 1 usando recursividad es: \n");
    for(int j = 0 ; j < MAX ; j++)
        printf(" %i ", res_1[j]);
    printf("\nLa salida del arreglo 2 usando recursividad es: \n");
    for(int j = 0 ; j < MAX ; j++)
        printf(" %i ", res_2[j]);
    printf("\nLa salida del arreglo 3 usando recursividad es: \n");
    for(int j = 0 ; j < MAX ; j++)
        printf(" %i ", res_3[j]);
}

void multiplicar_arreglo(int nums[], int res[])
{
    for(int i = 0 ; i < MAX ; i++)
        for(int j = 0 ; j < MAX ; j++)
            if(j != i)
                res[i] *= nums[j];
}

void multiplicar_arreglo_r(int nums[], int res[], int ind_int, int ind_ext)
{
    if(ind_int == MAX)
        multiplicar_arreglo_r(nums, res, 0, ind_ext + 1);
    if(ind_ext == MAX || ind_int >= MAX)
        return;
    if(ind_ext != ind_int)
        res[ind_ext] *= nums[ind_int];
    multiplicar_arreglo_r(nums, res, ind_int + 1, ind_ext);
}

void inicializar_arr(int nums[], int valor)
{
    for(int i = 0 ; i < MAX ; i++)
        nums[i] = valor;
}