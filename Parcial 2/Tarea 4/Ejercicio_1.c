#include <stdio.h>
#include <string.h>

#define MAX_NOMBRE_MES 10

typedef struct fecha{
    int dia;
    char mes[MAX_NOMBRE_MES];
    int annio;
} tipo_fecha;

void solicitar_fecha(tipo_fecha *fecha);
void imprimir_fecha(tipo_fecha *fecha);

int main ()
{
    tipo_fecha fecha_hoy;
    solicitar_fecha(&fecha_hoy);
    imprimir_fecha(&fecha_hoy);
    return 0;
}

void solicitar_fecha(tipo_fecha *fecha)
{
    printf("Dime en número que día es hoy:");
    scanf("%i", &(fecha->dia));
    fflush(stdin);

    printf("Dime el nombre del mes:");
    scanf("%[^\n]", &(fecha->mes));

    printf("Dime el año:");
    scanf("%i", &(fecha->annio));
}

void imprimir_fecha(tipo_fecha *fecha)
{
    if((int)fecha->mes[0] < 123 && (int)fecha->mes[0] > 96)
        fecha->mes[0] = (char)((int)fecha->mes[0] - 32);
    printf("La fecha de hoy es %i/%s/%i", fecha->dia, fecha->mes, fecha->annio);
}