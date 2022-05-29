#include "common.h"

typedef struct {
    int data[MAX];
    int top;
} Stack;

void setup(Stack *s);
int isEmpty(Stack stack);
int isFull(Stack stack);
int push(Stack *s, int value);
int pop(Stack *s, int *v);
int findIndex(Stack stack, int value);

void setup(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack stack)
{
    return (stack.top == -1) ? 1 : 0;
}

int isFull(Stack stack)
{
    return (stack.top == MAX - 1) ? 1 : 0;
}

int push(Stack *s, int value)
{
    if(!isFull(*s))
    {
        s->data[++s->top] = value;
        return 1;
    }
    return 0;
}

int pop(Stack *s, int *v)
{
    if(!isEmpty(*s))
    {
        *v = s->data[s->top--];
        return 1;
    }
    return 0;
}

int findIndex(Stack stack, int value)
{
    for(int i = 0 ; i <= stack.top ; i++)
        if(stack.data[i] == value)
            return i;
    return -1;
}