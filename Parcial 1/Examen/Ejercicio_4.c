#include <stdio.h>

void mod_valores(int* a, int* b, int* c);

int main(){
    int a, b, c;
    printf("Dame el valor de a:\n");
    scanf("%i", &a);
    printf("Dame el valor de b:\n");
    scanf("%i", &b);
    printf("Dame el valor de c:\n");
    scanf("%i", &c);
    mod_valores(&a, &b, &c);
    printf("Valores:\na = %i\nb = %i\nc = %i", a, b, c);
}

void mod_valores(int *a, int *b, int *c)
{
    int a_copia = *a, b_copia = *b, c_copia = *c;
    if(a_copia > b_copia) *b = *b * 2;
    if(a_copia < b_copia) *c = *c - *a;
    if(c_copia < 0) *c *= -1;
}