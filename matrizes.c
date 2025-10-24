#include <stdio.h>

void mostrar_soma_matriz(int **matriz, int linhas, int colunas){
    int soma = 0;
    
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; ){

        }
    }
}

void mostrar_matriz(int **matriz, int linhas, int colunas){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void prencher_matriz(int **matriz, int linhas, int colunas){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}

int** criar_matriz(int linhas, int colunas){
    int **matriz = (int**) malloc(sizeof(int*)*linhas);

    for(int i = 0; i < linhas; i++){
        matriz[i] = (int*) malloc(sizeof(int)*colunas);
    }
    return matriz;
}

int main(void){
    int linhas, colunas;

    scanf("%d", &linhas);
    scanf("%d", &colunas);

    int **matriz = criar_matriz(linhas, colunas);
    preencher_matriz(matriz, linhas, colunas);
    mostrar_matriz(matriz, linhas, colunas);
    mostrar_soma_matriz(matriz, linhas, colunas);
    
    return 0;
}