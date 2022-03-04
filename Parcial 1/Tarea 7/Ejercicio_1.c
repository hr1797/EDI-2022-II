#include <stdio.h>

#define MAX 100

void pedir_cadena(char cadena[MAX]);
void pedir_letra(char* letra);
int veces_letra_en_cadena(char cadena[MAX], char letra);

int main()
{
    int repeticiones;
    char cadena[MAX]; 
    char letra;
    pedir_cadena(cadena);
    pedir_letra(&letra);
    repeticiones = veces_letra_en_cadena(cadena, letra);
    printf("El número de veces que se repite esa letra es %i veces.", repeticiones);    
}

void pedir_cadena(char cadena[MAX])
{
    printf("Ingresa la cadena que se analizara:\n");
    scanf("%[^\n]", cadena);
    fflush(stdin);
}

void pedir_letra(char* letra)
{
    printf("Ingresa la letra que se usara:\n");
    scanf("%c", letra);
    fflush(stdin);
}

int veces_letra_en_cadena(char cadena[MAX], char letra)
{
    int contador = 0; 

    for(int i = 0 ; i < MAX && cadena[i] != '\0' ; i++){
        if(cadena[i] == letra) ++contador;
    }
    return contador;
}