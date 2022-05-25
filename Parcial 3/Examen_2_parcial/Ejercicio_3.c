#include <stdio.h>

#define ALUMNOS_CANT 4
#define MAX 7

void cambiar_float(float *a, float *b);
void cambiar_string(char nombres[][MAX], int indice_1, int indice_2);

int main()
{
    int min;
    char nombres[ALUMNOS_CANT][MAX] = {"Juan", "Pedro", "Sandra", "Paola"};
    float promedios[] = {6.5, 7.3, 5.2, 10.0};

    for(int i = 0 ; i < ALUMNOS_CANT ; i++)
    {
        min = i;
        for(int j = i + 1 ; j < ALUMNOS_CANT ; j++)
            if(promedios[j] < promedios[min])
                min = j;
        cambiar_float(&promedios[min], &promedios[i]);
        cambiar_string(nombres, min, i);
        printf("El alumno %s tiene el promedio de %.2f\n", nombres[i], promedios[i]);
    }
}

void cambiar_float(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

// void cambiar_string(char (*nombres)[MAX], int indice_1, int indice_2)
// {
//     int ind_1_local = indice_1;
//     int ind_2_local = indice_2;
//     char *temp = nombres[ind_1_local];
//     nombres[ind_1_local] = nombres[ind_2_local];
//     nombres[ind_2_local] = &temp;
// }

void cambiar_string(char (*nombres)[MAX], int indice_1, int indice_2)
{
    char temp;
    for(int i = 0 ; i < MAX ; i++)
    {
        temp = nombres[indice_1][i];
        nombres[indice_1][i] = nombres[indice_2][i];
        nombres[indice_2][i] = temp;
    }
}