#include <stdlib.h>


void separa(int *a, int n, int **pares, int *np, int **impares, int *ni);
void preencher_pares(int* a, int n, int* np);
void preencher_impares(int* a, int n, int* ni);
int conta_pares(int* a, int n);

void preencher_pares(int* a, int n, int* np){
    int aux = 0;
    
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            np[aux] = a[i];
            aux++;
        }
    }
}

void preencher_impares(int* a, int n, int* ni){
    int aux = 0;
    
    for(int i = 0; i < n; i++){
        if(a[i] % 2 != 0){
            ni[aux] = a[i];
            aux++;
        }
    }
}

int conta_pares(int* a, int n){
    int count = 0;
    
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            count++;
        }
    }
    return count;
}

void separa(int *a, int n, int **pares, int *np, int **impares, int *ni){
    int qtd_pares = conta_pares(a,n);
    int qtd_impares = n - qtd_pares;
    np = (int*) malloc(sizeof(int)*(size_t)qtd_pares);
    ni = (int*) malloc(sizeof(int)*(size_t)qtd_impares);
    *pares = np;
    *impares = ni;
    preencher_impares(a,n,ni);
    preencher_pares(a,n,np);
}

int main(void){
    int a[] = {1,2,3,4,5};
    int** impares;
    int** pares;
    int* ni;
    int* np;
    separa(a, 5, pares, np, impares, ni);
    return 0;
}