#include <stdio.h>
#include <stdlib.h>

int busca_linear(int *arranjo, int n, int valor){
    for(int i = 0; i < n; i++){
        if(arranjo[i] == valor){
            return 1;
        }
    }
    return -1;
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

    int valor;
    printf("Insira o valor desejado: ");
    scanf("%d", &valor);

    printf("%d\n", busca_linear(arranjo, n, valor));
    return 0;
}