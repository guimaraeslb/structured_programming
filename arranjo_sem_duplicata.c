#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void imprimir_arranjo(int* arranjo, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arranjo[i]);
    }
}

void prencher_arranjo_sem_duplicata(int* arranjo, int n, int* novo_arranjo, int novo_tamanho){
    int indice_aux = 0;

    for(int i = 0; i < n; i++){
        if(nao_esta_no_arranjo(novo_arranjo, novo_tamanho, arranjo[i])){
            novo_arranjo[indice_aux] = arranjo[i];
            indice_aux++;
        }
    }
}

int nao_esta_no_arranjo(int* arranjo, int n, int valor){
    for(int i = 0; i < n; i++){
        if(arranjo[i] == valor){
            return false;
        }
    }
    return true;
}

int contar_numeros_unicos(int* arranjo, int n){
    int count = 0;
    for(int i = 0; i < n; i++){
        if(nao_esta_no_arranjo(arranjo+1+i, n-1-i, arranjo[i])){
            count++;
        }
    }
    return count;
}

void ler_arranjo(int* arranjo, int n){
    for(int i = 0; i < n; i++){
        scanf("%d", &arranjo[i]);
    }
}

int main(void){
    int n;
    scanf("%d", &n);

    int *arranjo = (int*) malloc(sizeof(int)*n);
    ler_arranjo(arranjo, n);

    int qtd_numeros_unicos = contar_numeros_unicos(arranjo, n);
    int *novo_arranjo = (int*) malloc(sizeof(int)*qtd_numeros_unicos);
    prencher_arranjo_sem_duplicata(arranjo, n, novo_arranjo, qtd_numeros_unicos);
    imprimir_arranjo(novo_arranjo, qtd_numeros_unicos);
    return 0;
}