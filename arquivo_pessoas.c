#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa{
    char nome[21];
    unsigned idade;
}pessoa;

int salvar_pessoas(FILE *file, pessoa *pessoas, unsigned n){
    for(int i = 0; i < (int) n; i++){
        fprintf(file, "Nome: %s; Idade: %u\n", pessoas[i].nome, pessoas[i].idade);
    }
}

void mostrar_pessoas(pessoa *pessoas, unsigned n){
    for(int i = 0; i < (int) n; i++){
        printf("O nome da %d pessoa é %s\n", i+1, pessoas[i].nome);
        printf("A idade da %d pessoa é %u\n", i+1, pessoas[i].idade);
    }
}

void ler_pessoas(pessoa *pessoas, unsigned n){
    for(int i = 0; i < (int) n; i++){
        scanf("%20s", &(pessoas[i].nome));
        scanf("%u", &(pessoas[i].idade));
    }
}

int main(void){

    FILE *file = fopen("pessoas.txt", "a+");
    unsigned n;
    printf("Insira a qunatidade de pessoas que deseja salvar:\n");
    scanf("%u", &n);

    pessoa *pessoas = malloc(sizeof(pessoa)*(size_t)n);
    ler_pessoas(pessoas, n);
    mostrar_pessoas(pessoas, n);

    salvar_pessoas(file, pessoas, n);

    return 0;
}