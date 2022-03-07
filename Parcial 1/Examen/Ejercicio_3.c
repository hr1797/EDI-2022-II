#include <stdio.h>

#define FILAS 3
#define COLUMNAS 4

void leer_mat(int mat[FILAS][COLUMNAS]);
void imp_mat(int mat[FILAS][COLUMNAS]);
void suma_mat(int mat[FILAS][COLUMNAS], int mat2[FILAS][COLUMNAS]);

int main()
{
    int mat[FILAS][COLUMNAS];
    int mat2[FILAS][COLUMNAS];
    leer_mat(mat);
    suma_mat(mat, mat2);
    imp_mat(mat2);
}

void leer_mat(int mat[FILAS][COLUMNAS])
{
    for(int f = 0 ; f < FILAS ; f++){
        for(int c = 0 ; c < COLUMNAS ; c++){
            printf("Dime el elemnto %i x %i:\n", f, c);
            scanf("%i", &mat[f][c]);
        }
    }
}

void imp_mat(int mat[FILAS][COLUMNAS])
{
    for(int f = 0 ; f < FILAS ; f++){
        for(int c = 0 ; c < COLUMNAS ; c++){
            printf(" %i \t", mat[f][c]);
        }
        printf("\n");
    }
}

void suma_mat(int mat[FILAS][COLUMNAS], int mat2[FILAS][COLUMNAS])
{
    for(int f = 0 ; f < FILAS ; f++){
        for(int c = 0 ; c < COLUMNAS ; c++){
            if(f == 0 && c == 0){
                mat2[f][c] = mat[f][c] + mat[f][c+1] + mat[f+1][c];
            } else if(f == 0 && c == COLUMNAS-1) {
                mat2[f][c] = mat[f][c] + mat[f][c-1] + mat[f+1][c];
            } else if(f == FILAS-1 && c == 0) {
                mat2[f][c] = mat[f][c] + mat[f-1][c] + mat[f][c+1];
            } else if(f == FILAS-1 && c == COLUMNAS-1) {
                mat2[f][c] = mat[f][c] + mat[f][c-1] + mat[f-1][c];
            } else if(f == 0) {
                mat2[f][c] = mat[f][c] + mat[f][c+1] + mat[f+1][c] + mat[f][c-1];
            } else if(c == 0) {
                mat2[f][c] = mat[f][c] + mat[f][c+1] + mat[f+1][c] + mat[f-1][c];
            } else if(c == COLUMNAS-1) {
                mat2[f][c] = mat[f][c] + mat[f][c-1] + mat[f-1][c] + mat[f+1][c];
            } else if(f == FILAS-1) {
                mat2[f][c] = mat[f][c] + mat[f][c+1] + mat[f][c-1] + mat[f-1][c];
            } else {
                mat2[f][c] = mat[f][c] + mat[f][c+1] + mat[f][c-1] + mat[f+1][c] + mat[f-1][c];
            }
        }
    }    
}