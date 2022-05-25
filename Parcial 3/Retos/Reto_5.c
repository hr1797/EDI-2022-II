#include <stdio.h>
#include "../stack.h"

void stringToStack(Stack *s, char string[]);
int sameStacks(Stack *s1, Stack *s2);

int main()
{
    Stack stack_1;
    Stack stack_2;
    setup(&stack_1);
    setup(&stack_2);
    char string[MAX];

    printf("Dime la primer cadena de %i caracteres o menos:\n", MAX);
    scanf("%[^\n]", string);
    stringToStack(&stack_1, string);
    fflush(stdin);

    printf("Dime la segunda cadena de %i caracteres o menos:\n", MAX);
    scanf("%[^\n]", string);
    stringToStack(&stack_2, string);

    if(sameStacks(&stack_1, &stack_2))
        printf("Ambas cadenas son iguales");
    else 
        printf("Las cadenas son diferentes");
}

void stringToStack(Stack *s, char string[])
{
    int value;
    for(int i = 0 ; i < MAX && string[i] != 0 ; i++)
    {
        if(string[i] == 35)
            pop(s, &value);
        else if(string[i] != 35)
            push(s, string[i]);
    }
}

int sameStacks(Stack *s1, Stack *s2)
{
    for(int i = 0 ; i < MAX && i <= s1->top ; i++)
        if(s1->data[i] != s2->data[i])
            return 0;
    return 1;
}