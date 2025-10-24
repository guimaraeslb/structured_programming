#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int somar_diagonal_secundaria(int **matriz, unsigned linhas, unsigned colunas){
    int soma_diagonal_secundaria = 0;

    for(int i = 0; i < (int) linhas; i++){
        for(int j = 0; j < (int) colunas; j++){
            if((linhas - (i+j)) == (linhas-1)){
                soma_diagonal_secundaria = soma_diagonal_secundaria + matriz[i][j];
            }
        }
    }
    return soma_diagonal_secundaria;
}

int somar_diagonal_principal(int **matriz, unsigned linhas, unsigned colunas){
    int soma_diagonal_principal = 0;

    for(int i = 0; i < (int) linhas; i++){
        for(int j = 0; j < (int) colunas; j++){
            if(i == j){
                soma_diagonal_principal = soma_diagonal_principal + matriz[i][j];
            }
        }
    }
    return soma_diagonal_principal;
}

int verifica_soma_diagonais(int **matriz, unsigned linhas, unsigned colunas){
    int soma_diagonal_principal = somar_diagonal_principal(matriz, linhas, colunas);
    int soma_diagonal_secundaria = somar_diagonal_secundaria(matriz, linhas, colunas);

    if(soma_diagonal_principal != soma_diagonal_secundaria){
        return false;
    }
    return soma_diagonal_principal;
}

int verifica_soma_colunas(int **matriz, unsigned linhas, unsigned colunas){

    int soma_primeira_coluna = 0;
    int soma_temp = 0;

    for(int j = 0; j < (int) colunas; j++){
        soma_temp = 0;
        for(int i = 0; i < (int) linhas; i++){
            if(i == 0){
                soma_primeira_coluna = soma_primeira_coluna + matriz[i][j];
            }else{
                soma_temp = soma_temp + matriz[i][j];
            }   
        }
        if(j > 0 && soma_temp != soma_primeira_coluna){
            return false;
        }
    }
    return soma_primeira_coluna;
}

int verifica_soma_linhas(int **matriz, unsigned linhas, unsigned colunas){
    int soma_primeira_linha = 0;
    int soma_temp = 0;

    for(int i = 0; i < (int) linhas; i++){
        soma_temp = 0;
        for(int j = 0; j < (int) colunas; j++){
            if(i == 0){
                soma_primeira_linha = soma_primeira_linha + matriz[i][j];
            }else{
                soma_temp = soma_temp + matriz[i][j];
            }   
        }
        if(i > 0 && soma_temp != soma_primeira_linha){
            return false;
        }
    }
    return soma_primeira_linha;
}

int verifica_quadrado_magico(int **matriz, unsigned linhas, unsigned colunas){
    int soma_linhas = verifica_soma_linhas(matriz, linhas, colunas);
    int soma_colunas = verifica_soma_colunas(matriz, linhas, colunas);
    int soma_diagonais  = verifica_soma_diagonais(matriz, linhas, colunas);

    if(soma_linhas == soma_colunas == soma_diagonais){
        return true;
    }
    return false;
}

void ler_matriz(int **matriz, unsigned linhas, unsigned colunas){
    for(int i = 0; i < (int) linhas; i++){
        for(int j = 0; j < (int) colunas; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}

int** criar_matriz(unsigned linhas, unsigned colunas){
    int **matriz = (int**) malloc(sizeof(int*)*linhas);
    
    for(int i = 0; i < (int) linhas; i++){
        matriz[i] = (int*) malloc(sizeof(int)*colunas);
    }
    return matriz;
}

int main(void){
    unsigned linhas;

    scanf("%u", &linhas);

    int **matriz = criar_matriz(linhas, linhas);
    ler_matriz(matriz, linhas, linhas);
    bool eh_quadrado_magico = verifica_quadrado_magico(matriz, linhas, linhas);
    printf("%d\n", eh_quadrado_magico);

    return 0;
}