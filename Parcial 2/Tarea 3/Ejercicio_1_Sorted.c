#include <stdio.h>

int valores_dobles(int nums[], int length);
void insertion_sort(int arr[], int length);

int main ()
{
    int nums_1[] = {1,2,3,1};
    int nums_2[] = {1,4,3,2};
    int nums_3[] = {1,3,1,4,3,2,1,3,2};

    insertion_sort(nums_1, 4);
    insertion_sort(nums_2, 4);
    insertion_sort(nums_3, 9);

    printf("%i\n", valores_dobles(nums_1, 4));
    printf("%i\n", valores_dobles(nums_2, 4));
    printf("%i\n", valores_dobles(nums_3, 9));
}

int valores_dobles(int nums[], int length)
{
    for(int i = 0 ; i < length ; i++)
        if(i < length - 1 && nums[i] == nums[i + 1])
            return 1;
    return 0;
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