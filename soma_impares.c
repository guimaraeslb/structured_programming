#include <stdio.h>

int soma_impares(int n){
    if(n == 1){
        return (2*(n-1)+1);
    }
    return ((2*(n-1)+1) + soma_impares(n-1));
}

int main(void){
    int n;
    scanf("%d", &n);
    printf("%d", soma_impares(n));
    return 0;
}