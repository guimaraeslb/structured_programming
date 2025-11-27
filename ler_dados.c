#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa{
    char nome[21];
}pessoa;

void mostrar_pessoas(pessoa *pessoas, unsigned n){
    for(int i = 0; i < (int) n; i++){
        printf("%s\n", pessoas[i].nome);
    }
}

void ler_pessoas(FILE *file, pessoa *pessoas, unsigned n){
    rewind(file);

    for(int i = 0; i < (int) n; i++){
        fgets(pessoas[i].nome, sizeof(pessoas[i].nome), file);
    }
}

unsigned contar_registros(FILE *file){

    unsigned count = 0;
    char nome[21];

    while(fgets(nome, sizeof(nome), file) != NULL){
        count++;
    }
    return count;
}

int main(void){

    FILE *file = fopen("dados.txt", "r");
    unsigned qtd_dados = contar_registros(file);

    pessoa *pessoas = malloc(sizeof(pessoa)*(size_t)qtd_dados);
    ler_pessoas(file, pessoas, qtd_dados);
    mostrar_pessoas(pessoas, qtd_dados);
    return 0;
}