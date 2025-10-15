#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void stats(int *a, unsigned n, double *media, double *var, double *amp);

double calculo_menor_valor(int* a, unsigned n){
    double menor_valor = a[0];
    for(int m = 1; m < n; m++){
        if(a[m] < menor_valor){
            menor_valor = a[m];
        }
    }
    return menor_valor;
}

double calculo_maior_valor(int* a, unsigned n){
    double maior_valor = a[0];
    for(int l = 1; l < n; l++){
        if(a[l] > maior_valor){
            maior_valor = a[l];
        }
    }
    return maior_valor;
}

double calculo_amplitude(int* a, unsigned n){
    double maior_valor = calculo_maior_valor(a, n);
    double menor_valor = calculo_menor_valor(a, n);
    return maior_valor - menor_valor;
}

double calculo_variancia(int* a, unsigned n, double media){
    double soma_quadrado_diferenca = 0;
    double variancia;
    for(int k = 0; k < n; k++){
        soma_quadrado_diferenca = soma_quadrado_diferenca + (pow(a[k] - media, 2));
    }
    variancia = (double) soma_quadrado_diferenca/(n-1);
    return variancia;
}

double soma_arranjo(int* a, unsigned n){
    double soma = 0;
    for(int j = 0; j < n; j++){
        soma = soma + a[j];
    }
    return soma;
}

void ler_arranjo(int* a, unsigned n){
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
}

void stats(int *a, unsigned n, double *media, double *var, double *amp){
    *media = (double) soma_arranjo(a,n)/n;
    *var = calculo_variancia(a, n, *media);
    *amp = calculo_amplitude(a, n);
}

int main(void){
    double media, var, amp;
    unsigned n;
    scanf("%u", &n);

    int *a = malloc(sizeof(int)*n);
    ler_arranjo(a, n);

    stats(a, n, &media, &var, &amp);
    printf("%f %f %f", media, var, amp);
    return 0;
}