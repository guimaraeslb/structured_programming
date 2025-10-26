#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void imprimir_string(char *palavra, int size){
    for(int i = 0; i < size; i++){
        printf("%c", palavra[i]);
    }
}

int eh_vogal(char letra){
    char vogais[] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'};

    for(int i = 0; i < 10; i++){
        if(letra == vogais[i]){
            return true;
        }
    }
    return false;
}

int eh_consoante(char letra){
    char vogais[] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'};

    for(int i = 0; i < 10; i++){
        if(letra == vogais[i]){
            return false;
        }
    }
    return true;
}


void separa(char *palavra, char* consoantes, char* vogais){
    unsigned size_palavra = strlen(palavra);
    int aux_indice_vogais = 0;
    int aux_indice_consoantes = 0;

    for(int i = 0; i < (int) size_palavra; i++){
        if(eh_vogal(palavra[i])){
            vogais[aux_indice_vogais] = palavra[i];
            aux_indice_vogais++;
        }else{
            consoantes[aux_indice_consoantes] = palavra[i];
            aux_indice_consoantes++;
        }   
    }
}

int contar_consoantes(char* str){
    unsigned size = strlen(str);
    int count = 0;

    for(int i = 0; i < (int) size; i++){
        if(eh_consoante(str[i])){
            count++;
        }
    }
    return count;
}  

int contar_vogais(char* palavra){
    unsigned size = strlen(palavra);
    int count = 0;

    for(int i = 0; i < (int) size; i++){
        if(eh_vogal(palavra[i])){
            count++;
        }
    }
    return count;
}

int main(void){
    char str[51];
    scanf("%50s", str);

    int qtd_consoantes = contar_consoantes(str);
    int qtd_vogais = contar_vogais(str);

    char *consoantes = malloc(sizeof(char)*qtd_consoantes);
    char *vogais = malloc(sizeof(char)*qtd_vogais);

    separa(str, consoantes, vogais);
    
    imprimir_string(vogais, qtd_vogais);
    printf("\n");
    imprimir_string(consoantes, qtd_consoantes);
}