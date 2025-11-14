#include <stdio.h>
#include <stdlib.h>

void imprime_arranjo(int *arranjo, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arranjo[i]);
    }
}

void busca_linear(int *arranjo, int n, int valor, int **indices){
    int indice_aux = 0;
    for(int i = 0; i < n; i++){
        if(arranjo[i] == valor){
            (*indices)[indice_aux] = i;
            indice_aux++;
        }
    }
}

int aparicoes_no_arranjo(int *arranjo, int n, int valor){
    int count = 0;
    
    for(int i = 0; i < n; i++){
        if(arranjo[i] == valor){
            count++;
        }
    }
    return count;
}

void ler_arranjo(int *arranjo, int n){
    for(int i = 0; i < n; i++){
        scanf("%d", &arranjo[i]);
    }
}

int main(void){
    int n;
    printf("Insira o tamanho do arranjo: ");
    scanf("%d", &n);

    int *arranjo = malloc(sizeof(int)*(size_t)n);
    ler_arranjo(arranjo, n);
    
    int valor;
    printf("Insira o valor desejado: ");
    scanf("%d", &valor);

    int qtd_valor_arranjo = aparicoes_no_arranjo(arranjo, n, valor);
    int *indices = malloc(sizeof(int)*(size_t)qtd_valor_arranjo);
    busca_linear(arranjo, n, valor, &indices);
    imprime_arranjo(indices, qtd_valor_arranjo);
    return 0;
}