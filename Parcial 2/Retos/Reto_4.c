#include <stdio.h>

#define MAX 200

void join_arrays_c(int res_arr[],int nums_1[], int nums_2[], int m, int n);
void join_arrays_r(int res_arr[], int nums_1[], int nums_2[], int m, int n, int final_length, int cont_1, int cont_2, int cont_3);
void print_arr(int arr[], int length);

int main()
{
    int res_arr[MAX];
    int nums_1[] = {1, 2, 3};
    int nums_2[] = {2, 5, 6};
    int nums_3[] = {1};
    int nums_4[] = {};
    int nums_5[] = {1, 6, 9, 18};
    int nums_6[] = {2, 5, 6, 10, 15, 16};

    printf("Using cycles\n");
    printf("Array 1 & 2");
    join_arrays_c(res_arr, nums_1, nums_2, 3, 3);
    print_arr(res_arr, 6);

    printf("Array 3 & 4");
    join_arrays_c(res_arr, nums_3, nums_4, 1, 0);
    print_arr(res_arr, 1);

    printf("Array 5 & 6");
    join_arrays_c(res_arr, nums_5, nums_6, 4, 6);
    print_arr(res_arr, 10);

    printf("\nUsing recursion\n");
    printf("Array 1 & 2");
    join_arrays_r(res_arr, nums_1, nums_2, 3, 3, 6, 0, 0, 0);
    print_arr(res_arr, 6);

    printf("Array 3 & 4");
    join_arrays_r(res_arr, nums_3, nums_4, 1, 0, 1, 0, 0, 0);
    print_arr(res_arr, 1);

    printf("Array 5 & 6");
    join_arrays_r(res_arr, nums_5, nums_6, 4, 6, 10, 0, 0, 0);
    print_arr(res_arr, 10);
}

void join_arrays_c(int res_arr[], int nums_1[], int nums_2[], int m, int n)
{
    int final_lenght = m + n;
    int cont_1 = 0, cont_2 = 0, cont_3 = 0;

    while(cont_3 < final_lenght)
        if(cont_1 == m)
            res_arr[cont_3++] = nums_2[cont_2++];
        else if(cont_2 == n)
            res_arr[cont_3++] = nums_1[cont_1++];
        else if(nums_1[cont_1] < nums_2[cont_2])
            res_arr[cont_3++] = nums_1[cont_1++];
        else
            res_arr[cont_3++] = nums_2[cont_2++];
}

void join_arrays_r(int res_arr[], int nums_1[], int nums_2[], int m, int n, int final_length, int cont_1, int cont_2, int cont_3)
{
    if(cont_3 > final_length) 
        return;
    if(cont_1 == m)
        res_arr[cont_3++] = nums_2[cont_2++];
    else if(cont_2 == n)
        res_arr[cont_3++] = nums_1[cont_1++];
    else if(nums_1[cont_1] < nums_2[cont_2])
        res_arr[cont_3++] = nums_1[cont_1++];
    else
        res_arr[cont_3++] = nums_2[cont_2++];

    join_arrays_r(res_arr, nums_1, nums_2, m, n, final_length, cont_1, cont_2, cont_3);
}

void print_arr(int arr[], int length)
{
    printf("\n[");
    for(int i = 0 ; i < length ; i++)
        printf(" %i ", arr[i]);
    printf("]\n");
}