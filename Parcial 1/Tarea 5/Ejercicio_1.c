#include <stdio.h>

int main(){
    int hora, minuto;
    printf("Necesito que me digas la hora con un formato de 0 a 24\n");
    scanf("%i",&hora);
    printf("Necesito que me digas los minutos\n");
    scanf("%i",&minuto);
    if(hora >= 0 && hora < 12 && minuto >= 0 && minuto < 60){
        printf("Hola buenos días");
    } else if(hora >= 12 && hora < 17 && minuto >= 0 && minuto < 50){
        printf("Hola buenas tardes");
    } else if(hora >= 18 && hora < 24 && minuto >= 0 && minuto < 60){
        printf("Hola buenas noches");
    } else {
        printf("La hora que proporcionaste no es valida");
    }
    return 0;
}