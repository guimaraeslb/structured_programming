#include <stdio.h>
#include <stdlib.h>

void imprime_arranjo(int *arranjo, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arranjo[i]);
    }
}

int menor_elemento(int *arranjo, int n, int idx){
    int indice_menor_elemento = 0;
    
    for(int i = 0; i < n; i++){
        if(arranjo[i] < arranjo[indice_menor_elemento]){
            indice_menor_elemento = i;
        }
    }
    return indice_menor_elemento+idx;
}

void selection_sort(int *arranjo, int n){
    for(int i = 0; i < n; i++){
        int aux = arranjo[i];
        int indice_menor_elemento = menor_elemento(arranjo+i, n-i, i);
        arranjo[i] = arranjo[indice_menor_elemento];
        arranjo[indice_menor_elemento] = aux;
    }
}

void ler_arranjo(int *arranjo, int n){
    for(int i = 0; i < n; i++){
        scanf("%d", &arranjo[i]);
    }
}

int main(void){
    int n;
    printf("Insira o tamanho do arranjo: ");
    scanf("%d", &n);

    int *arranjo = malloc(sizeof(int)*(size_t)n);
    ler_arranjo(arranjo, n);

    selection_sort(arranjo, n);
    imprime_arranjo(arranjo, n);

    return 0;
}