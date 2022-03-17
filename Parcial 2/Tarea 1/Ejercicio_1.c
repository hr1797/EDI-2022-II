#include <stdio.h>
#include <math.h>
#define MAX 100

int palindromo_recursivo(char pal[], int length, int pos);
int palindromo_ciclos(char pal[], int length);
int string_length(char string[]);
void string_trim(char string[], char finalString[]);

int main()
{
    int palindromo_1, palindromo_2, length;
    char cadena[MAX];
    char cadena_trim[MAX];

    printf("Ingresa la cadena que se analizara:\n");
    scanf("%[^\n]", cadena);
    string_trim(cadena, cadena_trim);
    length = string_length(cadena_trim);
    palindromo_1 = palindromo_ciclos(cadena_trim, length);
    palindromo_2 = palindromo_recursivo(cadena_trim, length, 0);

    if(palindromo_1)
        printf("La cadena ingresada es un palindromo usando un metodo de ciclos\n");
    else 
        printf("La cadena ingresada no es un palindromo usando un metodo de ciclos\n");

    if(palindromo_2)
        printf("La cadena ingresada es un palindromo usando un metodo recursivo\n");
    else 
        printf("La cadena ingresada no es un palindromo usando un metodo recursivo\n");
}

int palindromo_recursivo(char pal[], int length, int pos)
{
    int half = floor(length / 2);
    if(pal[pos] != pal[length - pos]) return 0;
    if(pos > half) return 1;
    palindromo_recursivo(pal, length, ++pos);
}

int palindromo_ciclos(char pal[], int length)
{
    int half = floor(length / 2);
    for(int i = 0 ; i < half ; i++)
        if(pal[i] != pal[length - i])
            return 0;
    return 1;
}

int string_length(char string[])
{
    int i = 0;
    while(string[i] != '\0' && i < MAX)
        i++;
    return --i;
}

void string_trim(char string[], char finalString[])
{
    int i = 0, j = 0;
    while(string[i] != '\0' && i < MAX)
    {
        if(string[i] != ' ')
        {
            finalString[j++] = string[i];
        }
        ++i;
    }
    finalString[j] = '\0';    
}