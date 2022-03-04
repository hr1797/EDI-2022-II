#include <stdio.h>

#define FILAS_MAX 4
#define COLUMNAS_MAX 3

void capturar_matriz_bid(int mat[FILAS_MAX][COLUMNAS_MAX]);
void suma_matrices
    (
        int mat_1[FILAS_MAX][COLUMNAS_MAX],
        int mat_2[FILAS_MAX][COLUMNAS_MAX], 
        int resultado[FILAS_MAX][COLUMNAS_MAX]
    );
void promedio_filas(int mat[FILAS_MAX][COLUMNAS_MAX], int promedios[FILAS_MAX]);
void promedio_columnas(int mat[FILAS_MAX][COLUMNAS_MAX], int promedios[COLUMNAS_MAX]);
void imp_mat_1(int mat[FILAS_MAX][COLUMNAS_MAX]);
void imp_mat_2(int mat[FILAS_MAX]);
void imp_mat_3(int mat[COLUMNAS_MAX]);

int main()
{
    int matriz_1[FILAS_MAX][COLUMNAS_MAX];
    int matriz_2[FILAS_MAX][COLUMNAS_MAX];
    int resultado_suma[FILAS_MAX][COLUMNAS_MAX];
    int resultado_promedios_filas[FILAS_MAX];
    int resultado_promedios_columnas[COLUMNAS_MAX];

    printf("Vamos a capturar la primer matriz\n");
    capturar_matriz_bid(matriz_1);    
    printf("Vamos a capturar la segunda matriz\n");
    capturar_matriz_bid(matriz_2);    

    suma_matrices(matriz_1, matriz_2, resultado_suma);
    printf("Resultados de la suma de las matrices\n");
    imp_mat_1(resultado_suma);

    promedio_filas(resultado_suma, resultado_promedios_filas);
    printf("Resultados de los promedios de las filas de la matriz\n");
    imp_mat_2(resultado_promedios_filas);

    promedio_columnas(resultado_suma, resultado_promedios_columnas);
    printf("Resultados de los promedios de las columnas de la matriz\n");
    imp_mat_3(resultado_promedios_columnas);
}

void capturar_matriz_bid(int mat[FILAS_MAX][COLUMNAS_MAX])
{
    for(int fila = 0 ; fila < FILAS_MAX ; fila++)
    {
        for(int columna = 0 ; columna < COLUMNAS_MAX ; columna++)
        {
            printf("Dame el elemento %i x %i: ", fila +1 , columna + 1);
            scanf("%i", &mat[fila][columna]);
        }        
    }
}

void suma_matrices
    (
        int mat_1[FILAS_MAX][COLUMNAS_MAX],
        int mat_2[FILAS_MAX][COLUMNAS_MAX], 
        int resultado[FILAS_MAX][COLUMNAS_MAX]
    )
{
    for(int fila = 0 ; fila < FILAS_MAX ; fila++)
    {
        for(int columna = 0 ; columna < COLUMNAS_MAX ; columna++)
        {
            resultado[fila][columna] = mat_1[fila][columna] + mat_2[fila][columna];
        }
    }
}

void promedio_filas(int mat[FILAS_MAX][COLUMNAS_MAX], int promedios[FILAS_MAX])
{
    int contador_fila = 0;
    for(int fila = 0 ; fila < FILAS_MAX ; fila++)
    {
        for(int columna = 0 ; columna < COLUMNAS_MAX ; columna++)
        {
            contador_fila += mat[fila][columna];            
        }
        promedios[fila] = contador_fila / COLUMNAS_MAX;
        contador_fila = 0;
    }
}

void promedio_columnas(int mat[FILAS_MAX][COLUMNAS_MAX], int promedios[COLUMNAS_MAX])
{
    int contador_fila = 0;
    for(int columna = 0 ; columna < COLUMNAS_MAX; columna++)
    {
        for(int fila = 0 ; fila < FILAS_MAX ; fila++)
        {
            contador_fila += mat[fila][columna];            
        }
        promedios[columna] = contador_fila / FILAS_MAX;
        contador_fila = 0;
    }
}

void imp_mat_1(int mat[FILAS_MAX][COLUMNAS_MAX])
{
    for(int fila = 0 ; fila < FILAS_MAX ; fila++)
    {
        for(int columna = 0 ; columna < COLUMNAS_MAX ; columna++)
        {
            printf(" %i ", mat[fila][columna]);
        }
        printf("\n");
    }
}

void imp_mat_2(int mat[FILAS_MAX])
{
    for(int fila = 0 ; fila < FILAS_MAX ; fila++)
    {
        printf(" %i ", mat[fila]);
    }
    printf("\n");
}

void imp_mat_3(int mat[COLUMNAS_MAX])
{
    for(int columna = 0 ; columna < COLUMNAS_MAX; columna++)
    {
        printf(" %i ", mat[columna]);
    }
    printf("\n");
}
