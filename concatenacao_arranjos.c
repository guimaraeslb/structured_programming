#include <stdio.h>
#include <stdlib.h>

void mostrar_arranjo(int* arranjo, unsigned size){
    for(int k = 0; k < size; k++){
        printf("%d ", arranjo[k]);
    }
}

int* concantenar_arranjos(int* primeiro_arranjo, unsigned n, int* segundo_arranjo, unsigned m){
    int *arranjo_concatenado = malloc(sizeof(int)*(n+m));

    for(int i = 0; i < (int) n; i++){
        arranjo_concatenado[i] = primeiro_arranjo[i];
    }

    for(int j = 0; j < (int) m; j++){
        arranjo_concatenado[n+j] = segundo_arranjo[j];
    }
    return arranjo_concatenado;
}

void ler_arranjo(int *arranjo, int size){
    for(int i = 0; i < size; i++){
        scanf("%d", &arranjo[i]);
    }
}

int main(void){
    unsigned n, m;

    scanf("%u", &n);
    int *primeiro_arranjo = malloc(sizeof(int)*n);
    ler_arranjo(primeiro_arranjo, n);

    scanf("%u", &m);
    int *segundo_arranjo = malloc(sizeof(int)*n);
    ler_arranjo(segundo_arranjo, m);

    int *arranjo_concatenado = concantenar_arranjos(primeiro_arranjo, n, segundo_arranjo, m);
    mostrar_arranjo(arranjo_concatenado, n+m);

    return 0;
}