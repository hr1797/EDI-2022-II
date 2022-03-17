#include <stdio.h>

#define MAX 100

void conv_cadena(char* cadena);

int main()
{
    char cadena[MAX];
    printf("Dime la cadena de menos de %i caracteres:\n", MAX);
    scanf("%[^\n]", cadena);
    conv_cadena(cadena);
    printf("%s",cadena);
}

void conv_cadena(char* cadena)
{
    for(int i = 0 ; i < MAX ; i++)
    {
        switch (cadena[i])
        {
        case 'a':
            cadena[i] = 'A';
            break;
        case 'e':
            cadena[i] = 'E';
            break;
        case 'i':
            cadena[i] = 'I';
            break;
        case 'o':
            cadena[i] = 'O';
            break;
        case 'u':
            cadena[i] = 'U';
            break;
        case 'A':
            cadena[i] = 'a';
            break;
        case 'E':
            cadena[i] = 'e';
            break;
        case 'I':
            cadena[i] = 'i';
            break;
        case 'O':
            cadena[i] = 'o';
            break;
        case 'U':
            cadena[i] = 'u';
            break;
        }
    }
}