#include <stdio.h>

int main(){
    float kg_manzanas, precio_final, precio_kg;
    printf("Dime la cantidad de kilogramos de manzanas que compraras\n");
    scanf("%f",&kg_manzanas);
    printf("Dime el precio por kilogramo de manzanas\n");
    scanf("%f",&precio_kg);
    if(kg_manzanas <= 2){
        precio_final = kg_manzanas * precio_kg;
    } else if(kg_manzanas <= 5){
        precio_final = kg_manzanas * precio_kg * 0.9;
    } else if(kg_manzanas <= 10){
        precio_final = kg_manzanas * precio_kg * 0.85;
    } else {
        precio_final = kg_manzanas * precio_kg * 0.8;
    }
    printf("El precio final de las manzanas es %f", precio_final);
}