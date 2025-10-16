#include <stdio.h>
#include <stdlib.h>

void separa(int* arranjo, unsigned n, int* numeros_pares, unsigned m, int* numeros_impares, unsigned o){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(arranjo[j] % 2 == 0 && is_not_in_arranjo(numeros pares)){
                numeros_pares[i] = arranjo[j];
                break;
            }
        }
    }
}

int conta_pares(int *arranjo, unsigned n){
    int contador = 0;
    for(int j = 0; j < n; j++){
        if(arranjo[j] % 2 == 0){
            contador++;
        }
    }
    return contador;
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
    
    unsigned numero_pares = conta_pares(arranjo, n);
    unsigned numero_impares = n - numero_pares;

    return 0;
}