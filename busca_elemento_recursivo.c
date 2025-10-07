#include <stdio.h>

int busca_elemento_recursivo(int arranjo[], int n, int valor){
    if(arranjo[n-1] == valor){
        return n-1;
    }

    if(n == 1 && arranjo[n-1] != valor){
        return -1;
    }

    return busca_elemento_recursivo(arranjo, n-1, valor);
}

int main(void){
    int arranjo[] = {1,4,6,7};
    printf("%d", busca_elemento_recursivo(arranjo, 4,7));
    return 0;
}