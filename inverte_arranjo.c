#include <stdio.h>
void imprime_arranjo(int arranjo[], int n);
void inverte_arranjo(int arranjo[], int n);

void imprime_arranjo(int arranjo[], int n){
    for(int i = 0; i < n; i++){
        printf("%d,", arranjo[i]);
    }
}

void inverte_arranjo(int arranjo[], int n){
    for(int i = 0; i < 5; i++){
        int temp = arranjo[i];
        arranjo[i] = arranjo[n-1-i];
        arranjo[n-1-i] = temp;
    }
    imprime_arranjo(arranjo, n);
}

void main(void){
    int arranjo[] = {1, 2, 3, 4, 5};
    int n = 5;
    inverte_arranjo(arranjo, n);
}