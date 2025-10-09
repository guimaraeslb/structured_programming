#include <stdio.h>
#include <stdlib.h>

int qtd_pares(int arranjo[], int n){
    if(n == 0){
        return 0;
    }
    if(arranjo[n-1] % 2 == 0){
        return 1 + qtd_pares(arranjo, n-1);
    }else{
        return qtd_pares(arranjo, n-1);
    }
}

int* preencher_arranjo(int arranjo[], int n){
    for(int i = 0; i < n; i++){
        scanf("%d", &arranjo[i]);
    }
    return arranjo;
}

int main(void){
    int n;
    int *arranjo;
    scanf("%d", &n);
    arranjo = malloc(sizeof(int)*n);
    arranjo = preencher_arranjo(arranjo, n);
    printf("%d", qtd_pares(arranjo, n));
    return 0;
}