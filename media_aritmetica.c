#include <stdio.h>
int soma(int arranjo[], int n);
double media(int arranjo[], int n);

int soma(int arranjo[], int n){
    int soma = 0;
    for(int i = 0; i < n; i++){
        soma = soma + arranjo[i];
    }
    return soma;
}

double media(int arranjo[], int n){
    double media = (double) soma(arranjo, n) / n;
    return media;
}

void main(){
    int arranjo[] = {1,2,3,4,5,6,7,8,9,10};
    int n = 10;
    printf("%f", media(arranjo, n));
}