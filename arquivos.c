#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa{
    char nome[21];
    unsigned idade;
}pessoa;

int salvar_pessoa(pessoa *pessoa, FILE *file){
    fprintf(file, "O nome da pessoa é %s\n", (*pessoa).nome);
    fprintf(file, "A idade da pessoa é %u\n", (*pessoa).idade);
}

void mostrar_pessoa(pessoa* pessoa){
    printf("O nome da pessoa é %s\n", (*pessoa).nome);
    printf("A idade da pessoa é %u\n", (*pessoa).idade);
}

void ler_pessoa(pessoa* pessoa){
    printf("Insira seu nome:\n");
    scanf("%20s", &((*pessoa).nome));

    printf("Insira sua idade:\n");
    scanf("%u", &((*pessoa).idade));
}

int main(void){

    FILE *file = fopen("file.txt", "a+");

    pessoa *pessoa = malloc(sizeof(pessoa)*1);
    ler_pessoa(pessoa);
    mostrar_pessoa(pessoa);

    salvar_pessoa(pessoa, file);
    fclose(file);

    return 0;
}