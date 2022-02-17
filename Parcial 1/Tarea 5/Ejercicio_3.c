#include <stdio.h>

int main(){
    float lado_1, lado_2, lado_3;
    printf("Dime la longitud del primer lado del triangulo\n");
    scanf("%f",&lado_1);
    printf("Dime la longitud del segundo lado del triangulo\n");
    scanf("%f",&lado_2);
    printf("Dime la longitud del tercer lado del triangulo\n");
    scanf("%f",&lado_3);
    if(lado_1 == lado_2 && lado_2 == lado_3){
        printf("El triangulo es equilátero\n");
    } else if(lado_1 == lado_2 || lado_2 == lado_3 || lado_1 == lado_3){
        printf("El triangulo es isóceles\n");
    } else {
        printf("El triangulo es escaleno\n");
    }
}