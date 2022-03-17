#include <stdio.h>

int fibonacci_recursivo(int n, int anterior, int actual, int pos);

int main()
{
    int n, res;
    printf("Dime el número fibonacci a calcular\n");
    scanf("%i", &n);
    res = fibonacci_recursivo(n, 0, 1, 0);
    printf("El valor final es %i", res);
}

int fibonacci_recursivo(int n, int anterior, int actual, int pos)
{
    if(n == 0 || n == 1) return n; 
    if(pos == n) return anterior; 
    fibonacci_recursivo(n, actual, anterior + actual, ++pos);
}