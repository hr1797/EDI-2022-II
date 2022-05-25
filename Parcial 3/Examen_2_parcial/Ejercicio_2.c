#include <stdio.h>
#include <math.h>

void invertirCadena(char cadena[], int actual, int largo);
int largoCadena(char cadena[]);

int main()
{
    char cadena_1[] = "hello";
    int largo_1 = largoCadena(cadena_1);
    char cadena_2[] = "Estructuras";
    int largo_2 = largoCadena(cadena_2);
    char cadena_3[] = "Hola Mundo";
    int largo_3 = largoCadena(cadena_3);

    invertirCadena(cadena_1, 0, largo_1);
    printf("%s\n",cadena_1);

    invertirCadena(cadena_2, 0, largo_2);
    printf("%s\n",cadena_2);

    invertirCadena(cadena_3, 0, largo_3);
    printf("%s\n",cadena_3);
}

void invertirCadena(char cadena[], int actual, int largo)
{
    if(actual == floor(largo / 2))
        return;
    char temp = cadena[actual];
    int r = largo - 1 - actual;
    cadena[actual] = cadena[r];
    cadena[r] = temp;
    invertirCadena(cadena, ++actual, largo);
}

int largoCadena(char cadena[])
{
    int largo = 0;
    while(cadena[largo++])
        ;
    return --largo;
}