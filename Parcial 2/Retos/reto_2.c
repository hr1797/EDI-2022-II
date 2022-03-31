#include <stdio.h>

#define MAX 20

void decimal_hex_c(int num, char cad_final[], int* letters_count);
void turn_string_c(char string[], int letters_count);
void decimal_hex_r(int num, char final_string[], int* letters_count, int iterator);
void turn_string_r(char string[], char temp_string[], int letters_count, int iterator, int direction);

int main ()
{
    int letters_count = 0;
    char final_string_1[MAX];
    char final_string_2[MAX];
    char temp_string[MAX];

    decimal_hex_c(65029, final_string_1, &letters_count);
    turn_string_c(final_string_1, letters_count - 1);
    printf("Hexadecimal usando ciclos = %s\n", final_string_1);
    letters_count = 0;

    decimal_hex_r(65029, final_string_2, &letters_count, 0);
    turn_string_r(final_string_2, temp_string, letters_count - 1, 0, 1);
    printf("Hexadecimal usando recursividad = %s\n", final_string_2);
}

void decimal_hex_c(int num, char final_string[], int* letters_count)
{
    int i = 0;
    int residue;
    do{
        residue = num % 16;
        if(residue > 9)
           residue += 55; 
        else
            residue += 48;
        final_string[i++] = (char)residue;
        num = num / 16;
        *letters_count += 1;
    } while(num);
}

void turn_string_c(char string[], int letters_count)
{
    char temp_string[MAX];
    for(int i = letters_count , j = 0; i >= 0 ; i--)
        temp_string[j++] = string[i];
    for(int i = 0 ; string[i] != '\0'; i++)
        string[i] = temp_string[i];
}

void decimal_hex_r(int num, char final_string[], int* letters_count, int iterator)
{
    int residue = num % 16;
    if(residue > 9)
        residue += 55; 
    else
        residue += 48;
    if(!num) return;
    final_string[iterator] = (char)residue;
    *letters_count += 1;
    decimal_hex_r(num / 16, final_string, letters_count, ++iterator);
}

void turn_string_r(char string[], char temp_string[], int letters_count, int iterator, int direction)
{
    if(direction)
        temp_string[iterator++] = string[letters_count--];
    else
    {
        string[iterator++] = temp_string[iterator];
        if(iterator == letters_count) 
            return;
    }
    if(letters_count == -1)
        turn_string_r(string, temp_string, iterator, 0, 0);
    else 
        turn_string_r(string, temp_string, letters_count, iterator, direction);
}