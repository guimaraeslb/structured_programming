#include <stdio.h>
#include <stdlib.h>

void ler_arranjo(double* arranjo, int n){
    for(int i = 0; i < n; i++){
        scanf("%lf", &arranjo[i]);
    }
}

void mostrar_arranjo(double* arranjo, int n){
    for(int j = 0; j < n; j++){
        printf("%f\n", arranjo[j]);
    }
}

double* criar_arranjo(int n){
    double *arranjo = (double*) malloc(sizeof(double)*n);
    ler_arranjo(arranjo, n);
    return arranjo;
}

int main(void){
    int n;
    scanf("%u", &n);
    double *ponteiro_arranjo = criar_arranjo(n);
    mostrar_arranjo(ponteiro_arranjo, n);
    return 0;
}