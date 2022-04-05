#include <stdio.h>
#include <math.h>

typedef struct punto {
    int coord_x;
    int coord_y;
} tipo_punto;

void solicitar_punto(tipo_punto *punto);
float calcular_dist(tipo_punto *punto_1, tipo_punto *punto_2);
void imprimir_puntos(tipo_punto *punto_1, tipo_punto *punto_2, float dist);

int main()
{
    tipo_punto punto_1;
    tipo_punto punto_2;
    float dist;

    printf("Para el primer punto:\n");
    solicitar_punto(&punto_1);
    printf("\nPara el segundo punto:\n");
    solicitar_punto(&punto_2);
    dist = calcular_dist(&punto_1, &punto_2);
    imprimir_puntos(&punto_1, &punto_2, dist);
}

void solicitar_punto(tipo_punto *punto)
{
    printf("Dime la coordenada x del punto:");
    scanf("%i", &(punto->coord_x));

    printf("Dime la coordenada y del punto:");
    scanf("%i", &(punto->coord_y));
}

float calcular_dist(tipo_punto *punto_1, tipo_punto *punto_2)
{
    return sqrt(pow((punto_2->coord_x - punto_1->coord_x), 2) + pow((punto_2->coord_y - punto_1->coord_y), 2));
}

void imprimir_puntos(tipo_punto *punto_1, tipo_punto *punto_2, float dist)
{
    printf("El primer punto es (%i,%i)\n",punto_1->coord_x, punto_1->coord_y);
    printf("El segundo punto es (%i,%i)\n",punto_2->coord_x, punto_2->coord_y);
    printf("La distancia entre ellos es %f", dist);
}