#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa{
    char nome[50];
    int idade;
}pessoa;

void alterar_nome(){
    FILE *file = fopen("pessoas.bin", "r+b");
    char nome_antigo[50];
    char nome_novo[50];
    int count = 0;

    printf("Insira o nome que deve ser substituido:\n");
    scanf("%49s", nome_antigo);

    printf("Insira o novo nome:\n");
    scanf("%49s", nome_novo);

    pessoa *p = malloc(sizeof(pessoa));

    while(fread(p, sizeof(pessoa), 1, file) != NULL){
        if(strcmp((*p).nome, nome_antigo) == 0){
            fseek(file, count * sizeof(pessoa), SEEK_SET);
            fread(p, sizeof(pessoa), 1, file);
            strcpy((*p).nome, nome_novo);
            fseek(file, count * sizeof(pessoa), SEEK_SET);
            fwrite(p, sizeof(pessoa), 1, file);
        }
        count++;
    }

    
}

void inserir_pessoa(){
    FILE *file = fopen("pessoas.bin", "a+b");
    pessoa *p = malloc(sizeof(pessoa));

    printf("Insira o nome da nova pessoa:\n");
    scanf("%49s", (*p).nome);

    printf("Insira a idade da nova pessoa:\n");
    scanf("%d", &((*p).idade));

    fwrite(p, sizeof(pessoa), 1, file);
    free(p);
    fclose(file);
}

void exibir_pessoas(){
    FILE *file = fopen("pessoas.bin", "rb");
    pessoa *p = malloc(sizeof(pessoa));

    while(fread(p, sizeof(pessoa), 1, file) != NULL){
        printf("Nome: %s\n", (*p).nome);
        printf("Idade: %d\n", (*p).idade);
    }
    free(p);
    fclose(file);
}

int main(void){
    int opc = 0;

    while(opc != -1){   
        printf("[1] Ler pessoas, [2] Inserir nova pessoa ou [3] Mudar nome de uma pessoa\n");
        scanf("%d", &opc);

        if(opc == -1){
            break;
        }

        switch(opc){
            case 1:
                exibir_pessoas();
                break;
            case 2:
                inserir_pessoa();
                break;
            case 3:
                alterar_nome();
                break;
            default:
                exibir_pessoas();
                break;
        }
    }
    return 0;
}