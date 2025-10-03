#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

double get_soma(double notas[], int n);
double get_media(double soma, int n);
void get_notas(double notas[], int n);
void get_avaliacao(double notas[], int n, double media);

void get_avaliacao(double notas[], int n, double media){
    int qtd_acima = 0;
    int qtd_abaixo = 0;

    for(int i = 0; i < n; i++){
        if(notas[i] >= media){
            qtd_acima++;
        }else{
            qtd_abaixo++;
        }
    }
    printf("%d alunos acima da media\n", qtd_acima);
    printf("%d alunos abaixo da media\n", qtd_abaixo);
}

double get_soma(double notas[], int n){
    double soma = 0;
    for(int i = 0; i < n; i++){
        soma = soma + notas[i];
    }
    return soma;
}

double get_media(double soma, int n){
    double media = (double) soma/n;
    return media;
}  

void get_notas(double notas[], int n){
    for(int i = 0; i < n; i++){
        scanf("%lf", &notas[i]);
    }
    double soma = get_soma(notas, n);
    double media = get_media(soma, n);
    get_avaliacao(notas, n, media);
}



int main(void){
    int n;
    double *notas;
    scanf("%d", &n);
    notas = (double*) malloc(n*sizeof(int));
    get_notas(notas, n);
    return 0;
}