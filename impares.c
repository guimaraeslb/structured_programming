#include <stdio.h>
#include <stdlib.h>

int conta_impares(int* arranjo, unsigned n){
    if(n == 0){
        return 0;
    }

    if(arranjo[n-1] % 2 != 0){
        return 1 + conta_impares(arranjo, n-1);
    }else{
        return conta_impares(arranjo, n-1);
    }
}

void ler_arranjo(int* arranjo, unsigned n){
    for(int i = 0; i < n; i++){
        scanf("%d", &arranjo[i]);
    }
}

int main(void){
    unsigned n;
    scanf("%u", &n);

    int *arranjo = malloc(sizeof(int)*n);
    ler_arranjo(arranjo, n);

    int numeros_impares = conta_impares(arranjo, n);
    printf("%d", numeros_impares);
    return 0;
}