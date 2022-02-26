#include <stdio.h>

#define CANTIDAD_NUMEROS_1 10
#define CANTIDAD_NUMEROS_2 15
#define CANTIDAD_NUMEROS_3 20

int main(){
    int num, menor = 0, mayor = 0;
    for(int i = 1 ; i <= CANTIDAD_NUMEROS_1 ; i++){
        printf("Dime el número %i\n", i);
        scanf("%i",&num);
        if(num <= menor) menor = num;
        if(num >= mayor) mayor = num;
    }
    printf("El número mayor es %i\n", mayor);
    printf("El número menor es %i\n", menor);

    for(int i = 1 ; i <= CANTIDAD_NUMEROS_2 ; i++){
        printf("Dime el número %i\n", i);
        scanf("%i",&num);
        if(num <= menor) menor = num;
        if(num >= mayor) mayor = num;
    }
    printf("El número mayor es %i\n", mayor);
    printf("El número menor es %i\n", menor);

    for(int i = 1 ; i <= CANTIDAD_NUMEROS_3 ; i++){
        printf("Dime el número %i\n", i);
        scanf("%i",&num);
        if(num <= menor) menor = num;
        if(num >= mayor) mayor = num;
    }
    printf("El número mayor es %i\n", mayor);
    printf("El número menor es %i\n", menor);
}