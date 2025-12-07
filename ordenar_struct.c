#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa{
    char nome[50];
    int idade;
}pessoa;


void mostrar_pessoas(pessoa *pessoas, int n){
    for(int i = 0; i < n; i++){
        printf("%s\n", pessoas[i].nome);
        printf("%d\n", pessoas[i].idade);
    }
}

int encontrar_indice_menor_valor(pessoa *pessoas, int n, int aux){
    int idx = 0;

    for(int i = 0; i < n; i++){
        if(pessoas[i].idade < pessoas[idx].idade){
            idx = i;
        }
    }
    return idx+aux;
}

void selection_sort(pessoa *pessoas, int n){
    pessoa valor_auxiliar;
    int idx_menor_valor;
    
    for(int i = 0; i < n; i++){
        valor_auxiliar = pessoas[i];
        idx_menor_valor = encontrar_indice_menor_valor(pessoas+i, n - i, i);
        pessoas[i] = pessoas[idx_menor_valor];
        pessoas[idx_menor_valor] = valor_auxiliar;
    }
}

void ler_pessoas(pessoa *pessoas, int n){
    for(int i = 0; i < n; i++){
        scanf("%49s", pessoas[i].nome);
        scanf("%d", &(pessoas[i].idade));
    }
}

int main(void){
    int n;
    scanf("%d", &n);

    pessoa *pessoas = malloc(sizeof(pessoa)*(size_t)n);
    ler_pessoas(pessoas, n);

    selection_sort(pessoas, n);
    mostrar_pessoas(pessoas, n);

    return 0;
}