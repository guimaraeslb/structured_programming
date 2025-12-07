#include <stdio.h>
#include <stdlib.h>

void mostra_arranjo(int *arranjo, int n){
    for(int j = 0; j < n; j++){
        printf("%d ", arranjo[j]);
    }
}

void ordenar(int *arranjo, int n, int valor){
    int i = n - 2;
    while(arranjo[i] >= valor && i >= 0){
        arranjo[i+1] = arranjo[i];
        i--;
    }
    arranjo[i+1] = valor;
}

void insertion_sort(int *arranjo, int n){
    for(int i = 1; i < n; i++){
        ordenar(arranjo, i+1, arranjo[i]);
    }
}

void ler_arranjo(int *arranjo, int n){
    for(int i = 0; i < n; i++){
        scanf("%d", arranjo+i);
    }
}

int main(void){

    int n;
    scanf("%d", &n);

    int *arranjo = malloc(sizeof(int)*(size_t)n);
    ler_arranjo(arranjo, n);

    insertion_sort(arranjo, n);
    mostra_arranjo(arranjo, n);

    return 0;
}