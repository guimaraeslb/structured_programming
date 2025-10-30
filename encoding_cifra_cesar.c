#include <stdio.h>
#include <string.h>

void troca_letra_palavra(char *palavra, unsigned tamanho_palavra, int n){
    for(int i = 0; i < (int) tamanho_palavra; i++){
        if(palavra[i] >= 'A' && palavra[i] <= 'Z'){
            if(palavra[i] + n > 'Z'){
                palavra[i] = ((palavra[i] - 26 )+ n);
            }else{
                palavra[i] = palavra[i] + n;
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

    troca_letra_palavra(palavra, strlen(palavra), n);
    puts(palavra);

    free(palavra);
    return 0;
}