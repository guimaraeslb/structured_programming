#include <stdio.h>
#include <stdlib.h>

void mostrar_soma_elementos_matriz(int **matriz, int linhas, int colunas){
    int soma = 0;
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            soma = soma + matriz[i][j];
        }
    }
    printf("%d", soma);
}

void ler_arranjo(int *arranjo, int size){
    for(int i = 0; i < size; i++){
        scanf("%d", &arranjo[i]);
    }
}

int main(void){
    int **matriz = malloc(sizeof(int*)*2);
    matriz[0] =  malloc(sizeof(int)*2);
    matriz[1] =  malloc(sizeof(int)*2);

    ler_arranjo(matriz[0], 2);
    ler_arranjo(matriz[1], 2);

    mostrar_soma_elementos_matriz(matriz, 2, 2);
    return 0;
}