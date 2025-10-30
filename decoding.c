#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decodifica_palavra(char *palavra, unsigned tamanho_palavra, int n){
    for(int i = 0; i < tamanho_palavra; i++){
        if(palavra[i] >= 'A' && palavra[i] <= 'Z'){
            if(palavra[i] - n < 'A'){
                palavra[i] = ((palavra[i] + 26) - n);
            }else{
                palavra[i] = palavra[i] - n;
            }
        }
    }
}

int main(void){

    char palavra[51];
    fgets(palavra, sizeof(palavra), stdin);

    palavra[strcspn(palavra, "\n")] = '\0';

    int n;
    scanf("%d", &n);

    decodifica_palavra(palavra, strlen(palavra), n);
    puts(palavra);
    return 0;
}