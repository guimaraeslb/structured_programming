#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arranjos.h"

double* combinar_arranjos(double arranjo[], int n, double valor){
    int m = n+1;
    double *arranjo_ordernado = malloc(sizeof(double)*m);

    for(int i = 0; i < m; i++){
        if(i < n && arranjo[i] < valor){
            arranjo_ordernado[i] = arranjo[i];
        }else if(i < n && valor < arranjo[i]){
            arranjo_ordernado[i] = valor;
            for(int j = i+1; j < m; j++){
                arranjo_ordernado[j] = arranjo[j-1];
            }
            break;
        }else if(i >= n && verificar_inexistencia_valor_em_arranjo(arranjo_ordernado, m, valor)){
            arranjo_ordernado[i] = valor;
        }
    }
    return arranjo_ordernado;
}

double* ordenar_arranjo(double arranjo[], int n){
    if(n == 1){
        return arranjo;
    }
    double* arranjo_menor_ordenado = ordenar_arranjo(arranjo, n-1);
    double *arranjo_ordenado = combinar_arranjos(arranjo_menor_ordenado, n-1, arranjo[n-1]);
    return arranjo_ordenado;
}

int main(void){
    int n;
    double *arranjo;
    scanf("%d", &n);
    arranjo = malloc(sizeof(double)*n);
    arranjo = preencher_arranjo(arranjo, n);
    arranjo = ordenar_arranjo(arranjo, n);
    imprimir_arranjo(arranjo, n);
    return 0;
}