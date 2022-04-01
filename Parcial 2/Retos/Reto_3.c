#include <stdio.h>

char smallest_letter_c(char letters_arr[], char letter, int length);
char smallest_letter_r(char letters_arr[], char letter, int length, int start, int half, int end);

int main()
{
    char letters_1[] = {'a', 'b'};
    char letters_2[] = {'c', 'f', 'j'};
    char letters_3[] = {'c', 'g', 'j', 'm'};
    char letters_4[] = {'c', 'g', 'j', 'm', 'w'};
    printf("Using cycles\n");
    printf("%c\n", smallest_letter_c(letters_1, 'c', 1));
    printf("%c\n", smallest_letter_c(letters_2, 'f', 2));
    printf("%c\n", smallest_letter_c(letters_3, 'z', 3));
    printf("%c\n", smallest_letter_c(letters_4, 'o', 4));

    printf("\nUsing recursion\n");
    printf("%c\n", smallest_letter_r(letters_1, 'c', 1, 0, 0, 1));
    printf("%c\n", smallest_letter_r(letters_2, 'f', 2, 0, 0, 2));
    printf("%c\n", smallest_letter_r(letters_3, 'z', 3, 0, 0, 3));
    printf("%c\n", smallest_letter_r(letters_4, 'o', 4, 0, 0, 4));
}

char smallest_letter_c(char letters_arr[], char letter, int length)
{
    // Value out of array or is the last value
    if(letter < letters_arr[0] || letters_arr[length] <= letter)                
        return letters_arr[0];

    int half, start = 0, end = length;
    while(start <= end)
    {
        half = (start + end) / 2;
        // Value found
        if(letters_arr[half] == letter)
            return letters_arr[half + 1];
        // Value not found but inside the array
        if(start == end)
            return letters_arr[half];

        if(letters_arr[half] < letter)
            start = half + 1;
        else 
            end = half - 1;
    }
}

char smallest_letter_r(char letters_arr[], char letter, int length, int start, int half, int end)
{
    // Value out of array or is the last value
    if(
        letter < letters_arr[0] ||
        letters_arr[length] <= letter ||
        start > end
    )                
        return letters_arr[0];
    
    half = (start + end) / 2; 
    if(letters_arr[half] == letter)
        return letters_arr[half + 1];
    if(start == end)
        return letters_arr[half];

    if(letters_arr[half] < letter)
        smallest_letter_r(letters_arr, letter, length, half + 1, 0, end);
    else 
        smallest_letter_r(letters_arr, letter, length, start, 0, half + 1);
}