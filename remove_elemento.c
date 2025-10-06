#include <stdio.h>

int remover_valor(int valores[], int n, int valor){
    int contador = 0;
    for(int i = 0; i < n; i++){
        if(valores[i] == valor){
            for(int j = i+1; j < n; j++){
                valores[j-1] = valores[j];
            }
            contador++;
        }
    }
    return contador;
}


int main(void){
    int valores [] = {1,2,1,4};
    printf("Quantidade de elementos removidos: %d", remover_valor(valores, 4, 1));
    return 0;
}