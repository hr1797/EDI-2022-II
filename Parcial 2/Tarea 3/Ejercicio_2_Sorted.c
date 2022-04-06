#include <stdio.h>

#define MAX 100

int valor_mas_repetido(int nums[], int length);
void insertion_sort(int arr[], int length);

int main ()
{
    int nums_1[] = {3,2,3};
    int nums_2[] = {2,2,1,1,1,2,2};
    int nums_3[] = {1,3,1,4,3,2,1,3,2,1};

    insertion_sort(nums_1, 3);
    insertion_sort(nums_2, 7);
    insertion_sort(nums_3, 10);

    printf("El valor mas repetido es: %i\n", valor_mas_repetido(nums_1, 3));
    printf("El valor mas repetido es: %i\n", valor_mas_repetido(nums_2, 7));
    printf("El valor mas repetido es: %i\n", valor_mas_repetido(nums_3, 10));
}

int valor_mas_repetido(int nums[], int length)
{
    int conteo_max = 0, valor_max = nums[0];
    for(int i = 0 ; i < length ; i++)
    {
        int j = i, conteo_max_temp = 0;        
        while(nums[i] == nums[j] && j < length)
        {
            conteo_max_temp++;
            if(conteo_max <= conteo_max_temp)
            {
                conteo_max = conteo_max_temp;
                valor_max = nums[j];
            }
            j++;
        }
    }
    return valor_max;
}

void insertion_sort(int arr[], int length) 
{
  for (int step = 1; step < length; step++) {
    int key = arr[step];
    int j = step - 1;

    while (j >= 0 && key < arr[j]) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
  }
}