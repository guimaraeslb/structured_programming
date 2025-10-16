#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool esta_no_arranjo(int* arranjo, unsigned n, int valor){
    for(int i = 0; i < (int) n; i++){
        if(arranjo[i] == valor){
            return true;
        }
    }  
    return false;
}

bool eh_permutacao(int* first_set, unsigned m, int* second_set, unsigned n){
    int contador = 0;
    for(int i = 0; i < (int) m; i++){
        if(esta_no_arranjo(second_set, n, first_set[i])){
            contador++;
        }
    }

    if(contador == (int) m){
        return true;
    }
    return false;
}

void ler_arranjo(int* arranjo, unsigned n){
    for(int i = 0; i < (int) n; i++){
        scanf("%d", &arranjo[i]);
    }
}

int main(void){
    unsigned m, n;

    scanf("%u", &m);
    int *first_set = malloc(sizeof(int)*m);
    ler_arranjo(first_set, m);

    scanf("%u", &n);
    int *second_set = malloc(sizeof(int)*n);
    ler_arranjo(second_set, n);

    printf("%d", eh_permutacao(first_set, m, second_set, n));

    return 0;
}