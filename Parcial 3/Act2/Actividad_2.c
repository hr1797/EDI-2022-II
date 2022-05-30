#include <stdio.h>
#include <string.h>

#define MAX 50

typedef struct {
    char name[50];
    char lastName[50];
    float average;
} Alumno;

int leerAlumnos(char archivo[MAX], Alumno alumnos[20]);
void ordenarAlumnos(Alumno alumnos[], int length);
void printAlumnos(Alumno alumnos[], int length);

int main()
{
    Alumno alumnos[20];
    char archivo[] = "./aprendizaje2.dat";
    int cantAlumnos = leerAlumnos(archivo, alumnos);

    printf("\nAntes de ordenar");
    printAlumnos(alumnos, cantAlumnos);
    ordenarAlumnos(alumnos, cantAlumnos);
    printf("\nDespues de ordenar");
    printAlumnos(alumnos, cantAlumnos);
}

int leerAlumnos(char archivo[MAX], Alumno alumnos[20])
{
    FILE *salida;
    salida = fopen(archivo, "rb");
    if(salida == NULL) 
    {
        printf("No se pudo abrir el archivo"); 
        return 0;
    }

    int i = 0;
    while(!feof(salida))
        fread(&alumnos[i++], sizeof(Alumno), 1, salida);
    fclose(salida);
    return --i;
}

void ordenarAlumnos(Alumno alumnos[], int length)
{
    for(int i = 0 ; i < length-1 ; i++) 
    {
        int minInd = i;
        for(int j = i+1 ; j < length ; j++)
        {
            int newInd = (int)alumnos[j].lastName[0];
            int currentInd = (int)alumnos[minInd].lastName[0];
            if(newInd < currentInd)
                minInd = j;
        }

        Alumno temp;
        strcpy(temp.name, alumnos[minInd].name);
        strcpy(temp.lastName, alumnos[minInd].lastName);
        temp.average = alumnos[minInd].average;

        strcpy(alumnos[minInd].name, alumnos[i].name);
        strcpy(alumnos[minInd].lastName, alumnos[i].lastName);
        alumnos[minInd].average = alumnos[i].average;

        strcpy(alumnos[i].name, temp.name);
        strcpy(alumnos[i].lastName, temp.lastName);
        alumnos[i].average = temp.average;
    }
}

void printAlumnos(Alumno alumnos[], int length)
{
    printf("\n   Apellidos\tNombre\tPromedio\n");
    for(int i = 0; i < length ; i++)
    {
        printf("%i  %s\t", i+1, alumnos[i].lastName);
        printf("%s\t", alumnos[i].name);
        printf("%.2f\n", alumnos[i].average);
    }
}