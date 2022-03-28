#include <stdio.h>

int valores_dobles(int nums[]);

int main ()
{
    int nums_1[] = {1,2,3,1};
    int nums_2[] = {1,4,3,2};
    int nums_3[] = {1,3,1,4,3,2,1,3,2};
    printf("%i\n", valores_dobles(nums_1));
    printf("%i\n", valores_dobles(nums_2));
    printf("%i\n", valores_dobles(nums_3));
}

int valores_dobles(int nums[])
{
    for(int i = 0 ; nums[i] != '\0' ; i++)
    {
        for(int j = i + 1 ; nums[j] != '\0' ; j++)
        {
            if(nums[i] == nums[j]) return 1;
        }
    }
    return 0;
}