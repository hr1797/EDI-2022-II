#include <stdio.h>

int main(){
    int dias, horas, minutos, total_segundos;
    printf("Dame la cantidad de días: \n");
    scanf("%i", &dias);
    printf("Dame la cantidad de horas: \n");
    scanf("%i", &horas);
    printf("Dame la cantidad de minutos: \n");
    scanf("%i", &minutos);
    total_segundos = dias * 86400 + horas * 3600 + minutos* 60;
    printf("La cantidad de segundos son %i\n", total_segundos);
    return 0;
}