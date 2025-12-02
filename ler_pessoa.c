#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa{
    char nome[50];
    int idade;
}pessoa;

pessoa* ler_pessoa(){
    pessoa *p = malloc(sizeof(pessoa));

    printf("Insira o nome da pessoa:\n");
    scanf("%49s", (*p).nome);

    printf("Insira a idade da pessoa:\n");
    scanf("%d", &((*p).idade));

    return p;
}

int main(void){
    FILE * file = fopen("pessoas.bin", "wb");
    pessoa *p = ler_pessoa();


    fwrite(p, sizeof(pessoa), 1, file);

    free(p);
    fclose(file);
    return 0;
}