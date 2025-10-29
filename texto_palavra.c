#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void verifica_se_eh_palavra(char *texto, int i, char *palavra, unsigned tamanho_palavra){
    int aux = 0;
    bool eh_igual = true;
    
    for(int j = i; j < i + (int) tamanho_palavra; j++){
        if(texto[j] != palavra[aux]){
            eh_igual = false;
            break;
        }
        aux = aux + 1;
    }

    if(eh_igual){
        printf("%d ", i);
    }   
}


void verifica_indices(char *texto, unsigned tamanho_texto, char *palavra, unsigned tamanho_palavra){
    for(int i = 0; i < (int) tamanho_texto; i++){
        if(texto[i] == palavra[0]){
            verifica_se_eh_palavra(texto, i, palavra, tamanho_palavra);
        }
    }
}

int main(void){
    char texto[51];
    char palavra[11];

    fgets(texto, sizeof(texto), stdin);
    fgets(palavra, sizeof(palavra), stdin);

    texto[strcspn(texto, "\n")] = '\0';
    palavra[strcspn(palavra, "\n")] = '\0';

    unsigned tamanho_texto = strlen(texto);
    unsigned tamanho_palavra = strlen(palavra);
    verifica_indices(texto, tamanho_texto, palavra, tamanho_palavra);

    return 0;
}