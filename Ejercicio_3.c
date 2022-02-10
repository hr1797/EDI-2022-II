#include <stdio.h>

int main(){
    int dias, horas, minutos, seg;
    printf("Dame la cantidad total de segundos: \n");
    scanf("%i", &seg);
    dias = seg / 86400;
    seg = seg % 86400;
    horas = seg / 3600;
    seg = seg % 3600;
    minutos = seg / 60;
    seg = seg % 60;

    printf("El total de dias es %i\n", dias );
    printf("El total de horas es%i\n", horas);
    printf("El total de minutos es %i\n", minutos );
    printf("El total de segundos es %i", seg);

    return 0;
}