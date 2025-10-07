#include <stdio.h>

int somatorio_naturais_recursivo(int n){
    if(n == 1){
        return n;
    }

    return n + somatorio_naturais_recursivo(n-1);
}

int main(void){
    int n;
    scanf("%d", &n);
    printf("%d", somatorio_naturais_recursivo(n));
    return 0;
}