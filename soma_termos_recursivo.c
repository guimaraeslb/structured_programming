#include <stdio.h>

int soma_termos_recursivo(int arranjo[], int n){
    if(n == 1){
        return arranjo[n-1];
    }
    return arranjo[n-1] + soma_termos_recursivo(arranjo, n-1);
}

int main(void){
    int arranjo[] = {1,2,3,5};
    printf("%d", soma_termos_recursivo(arranjo, 4));
    return 0;
}