#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

unsigned conta_tamanho_palavra(char *palavra){
    unsigned tamanho_palavra = 0;
    int aux = 0;

    while(true){
        if(palavra[aux] == '\0'){
            break;
        }else if(palavra[aux] != ' '){
            tamanho_palavra++;
        }
        aux++;
    }
    return tamanho_palavra;
}

void eh_palindromo(char *palavra, unsigned tamanho_palavra){
    bool eh_palindromo = true;
    int qtd_letras = conta_tamanho_palavra(palavra);
    int *palavra_em_ascii = (int*) malloc(sizeof(int)*(size_t)qtd_letras);
    int aux = 0;

    for(int i = 0; i < (int) tamanho_palavra; i++){
        if(palavra[i] != ' '){
            palavra_em_ascii[aux] = palavra[i];
            aux++;
        }
    }
    
    aux = 0;

    for(int j = 0; j < tamanho_palavra; j++){
        if(palavra[j] != ' ' && palavra[j] != palavra_em_ascii[aux]){
            printf("NAO EH PALINDROMO");
            eh_palindromo = false;
            break;
        }else if(palavra[j] != ' '){
            aux++;
        }
    }
    if(eh_palindromo){
        printf("PALINDROMO");
    }
}

int main(void){
    char palavra[51];
    fgets(palavra, sizeof(palavra), stdin);

    palavra[strcspn(palavra, "\n")] = '\0';

    unsigned tamanho_palavra = strlen(palavra);
    eh_palindromo(palavra, tamanho_palavra);

    return 0;
}