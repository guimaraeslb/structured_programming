#include <stdio.h>

int menor_valor(int valores[], int n, int idx){
    int menor_valor = valores[idx];
    for(int i = (n-1); i <  n; i++){
        if(valores[i] < menor_valor){
            menor_valor = valores[i];
        }
    }
    return menor_valor;
}

int main(void){
    int valores[] = {1,2,5,7,4};
    printf("%d", menor_valor(valores, 5, 4));
    return 0;
}