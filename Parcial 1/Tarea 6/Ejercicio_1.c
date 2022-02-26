#include <stdio.h>

int numeroPerfecto(int num){
    int suma = 0;
    for(int i = 1; i < num ; i++){
        if(num % i == 0) suma += i;
    }
    if(suma == num) return 1;
    return 0;
}

int main(){
    int numero, es_perfecto;
    printf("Necesito que me digas el número que quieres revisar\n");
    scanf("%i",&numero);
    es_perfecto = numeroPerfecto(numero);
    if(es_perfecto){
        printf("El número %i es perfecto", numero);
    } else {
        printf("El número %i no es perfecto", numero);
    }
}