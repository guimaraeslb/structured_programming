#include <stdio.h>
#include <stdlib.h>

void imprimir_matriz(double **matriz, unsigned linhas, unsigned colunas){ 
    for(int i = 0; i < (int) linhas; i++){
        for(int j = 0; j < (int) colunas; j++){
            printf("%f ", matriz[i][j]);
        }
        printf("\n");
    }
}

void ler_matriz(double **matriz, unsigned linhas, unsigned colunas){
    for(int i = 0; i < (int) linhas; i++){
        for(int j = 0; j < (int) colunas; j++){
            scanf("%lf", &matriz[i][j]);
        }
    }
}

double** criar_matriz(unsigned linhas, unsigned colunas){
    double **matriz = (double**) malloc(sizeof(double*)* (int) linhas);

    for(int i = 0; i < (int) linhas; i++){
        matriz[i] = (double*) malloc(sizeof(double)* (int) colunas);
    }

    return matriz;
}

int main(void){
    unsigned linhas, colunas;

    scanf("%u", &linhas);
    scanf("%u", &colunas);
    
    double **matriz = criar_matriz(linhas, colunas);
    ler_matriz(matriz, linhas,  colunas);
    imprimir_matriz(matriz, linhas, colunas);


    return 0;
}