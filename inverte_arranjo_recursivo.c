#include <stdio.h>
#include <stdlib.h>

int* preencher_arranjo(int arranjo_semi_invertido[], int n, int valor){
    int *arranjo_invertido;
    arranjo_invertido = malloc(sizeof(int)*(n+1));
    arranjo_invertido[n] = valor;
    for(int i = 0; i < n; i++){
        arranjo_invertido[i] = arranjo_semi_invertido[i];
    }
    return arranjo_invertido;
}

int* inverte_arranjo_recursivo(int arranjo[], int n){
    if(n == 1){
        return arranjo;
    }
    int *arranjo_menor_invertido = inverte_arranjo_recursivo(arranjo+1, n-1);
    int *arranjo_invertido = preencher_arranjo(arranjo_menor_invertido, n-1, arranjo[0]);
    return arranjo_invertido;
}

int* ler_valores_arranjo(int arranjo[], int n){
    for(int i = 0; i < n; i++){
        scanf("%d", &arranjo[i]);
    }
    return arranjo;
}

int main(void){
    int n;
    scanf("%d", &n);
    int *arranjo = malloc(sizeof(int)*n);
    arranjo = ler_valores_arranjo(arranjo, n);
    int *arranjo_invertido = inverte_arranjo_recursivo(arranjo, n);
    for(int j = 0; j < n; j++){
        printf("%d", arranjo_invertido[j]);
    }
    return 0;
}