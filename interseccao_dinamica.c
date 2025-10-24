#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void mostrar_arranjo(int* arranjo, int n);
int* verifica_interseccao(int* primeiro_arranjo, int m, int* segundo_arranjo, int n, int tamanho_interseccao);
int esta_no_arranjo(int *arranjo, int n, int valor);
int verifica_tamanho_interseccao(int* primeiro_arranjo, int m, int* segundo_arranjo, int n);
void ler_arranjo(int* arranjo, int n);

void mostrar_arranjo(int* arranjo, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arranjo[i]);
    }
}

int* verifica_interseccao(int* primeiro_arranjo, int m, int* segundo_arranjo, int n, int tamanho_interseccao){
    int* interseccao = (int*) malloc(sizeof(int)*tamanho_interseccao);
    int indice_interseccao = 0;
    for(int i = 0; i < m; i++){
        if(esta_no_arranjo(segundo_arranjo, m, primeiro_arranjo[i])){
            interseccao[indice_interseccao] = primeiro_arranjo[i];
            indice_interseccao++;
        }
    }
    return interseccao;
}

int esta_no_arranjo(int *arranjo, int n, int valor){
    for(int i = 0; i < n; i++){
        if(arranjo[i] == valor){
            return true;
        }
    }
    return false;
}

int verifica_tamanho_interseccao(int* primeiro_arranjo, int m, int* segundo_arranjo, int n){
    int contador = 0;
    for(int i = 0; i < m; i++){
        if(esta_no_arranjo(segundo_arranjo, n, primeiro_arranjo[i])){
            contador++;
        }
    }
    return contador;
}

void ler_arranjo(int* arranjo, int n){
    for(int i = 0; i < n; i++){
        scanf("%d", &arranjo[i]);
    }
}

int main(void)
{
    int m, n;

    scanf("%d", &m);
    int *primeiro_arranjo = malloc(sizeof(int)*m);
    ler_arranjo(primeiro_arranjo, m);

    scanf("%d", &n);
    int *segundo_arranjo = malloc(sizeof(int)*n);
    ler_arranjo(segundo_arranjo, m);

    int tamanho_interseccao = verifica_tamanho_interseccao(primeiro_arranjo, m, segundo_arranjo, n);
    int *interseccao = verifica_interseccao(primeiro_arranjo, m, segundo_arranjo, n, tamanho_interseccao);
    mostrar_arranjo(interseccao, tamanho_interseccao);

    return 0;
}