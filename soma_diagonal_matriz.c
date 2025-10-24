#include <stdio.h>

#define N 2

void ler_matriz(int matriz[N][N], int n); 
int soma_diagonal_principal(int matriz[N][N], int n);
int soma_diagonal_secundaria(int matriz[N][N], int n);

int soma_diagonal_secundaria(int matriz[N][N], int n){
    int soma_diagonal_secundaria = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((n - (i+j)) == (n - 1)){
                soma_diagonal_secundaria = soma_diagonal_secundaria + matriz[i][j];
            }
        }
    }
    return soma_diagonal_secundaria;
}

int soma_diagonal_principal(int matriz[N][N], int n){
    int soma_diagonal_prinicipal = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                soma_diagonal_prinicipal = soma_diagonal_prinicipal + matriz[i][j];
            }
        }
    }
    return soma_diagonal_prinicipal;
}

void ler_matriz(int matriz[N][N], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}

int main(void){
    int matriz[N][N];
    ler_matriz(matriz, N);
    int soma1 = soma_diagonal_principal(matriz, N);
    int soma2 = soma_diagonal_secundaria(matriz, N);

    printf("%d\n", soma1);
    printf("%d\n", soma2);
    return 0;
}