#include <stdio.h> 

int indObjetivo(int nums[], int obj, int length);

int main()
{
    int nums_1[] = {1,3,5,6};
    int nums_2[] = {1,3,5};
    int nums_3[] = {1,3,5,6};
    int obj_1 = 5;
    int obj_2 = 2;
    int obj_3 = 7;

    printf("El indice donde debería de estar el valor objetivo 1 es %i\n", indObjetivo(nums_1, obj_1, 4));
    printf("El indice donde debería de estar el valor objetivo 2 es %i\n", indObjetivo(nums_2, obj_2, 3));
    printf("El indice donde debería de estar el valor objetivo 3 es %i\n", indObjetivo(nums_3, obj_3, 4));
}

int indObjetivo(int nums[], int obj, int length)
{
    for(int i = 0 ; i < length ; i++)
        if(obj <= nums[i])
            return i;
    return length;
}