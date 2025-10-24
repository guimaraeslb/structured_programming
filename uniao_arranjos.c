#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void imprimir_arranjo(int* arranjo, int n);
void preencher_arranjo_uniao(int* arranjo_uniao, int tamanho_arranjo_uniao, int* primeiro_arranjo, int m, int* segundo_arranjo, int n);
bool arranjo_contem_elemento(int* arranjo, int n, int valor);
bool arranjo_nao_contem_elemento(int* arranjo, int n, int valor);
int conta_elementos_repetidos_entre_arranjos(int* primeiro_arranjo, int m, int* segundo_arranjo, int n);
int conta_elementos_unicos_entre_arranjos(int* primeiro_arranjo, int m, int* segundo_arranjo, int n);
void ler_arranjo(int* arranjo, int n);

void imprimir_arranjo(int* arranjo, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arranjo[i]);
    }
}

void preencher_arranjo_uniao(int* arranjo_uniao, int tamanho_arranjo_uniao, int* primeiro_arranjo, int m, int* segundo_arranjo, int n){
    int aux_indice = 0;
    for(int i = 0; i < m; i++){
        if(arranjo_nao_contem_elemento(arranjo_uniao, tamanho_arranjo_uniao, primeiro_arranjo[i])){
            arranjo_uniao[aux_indice] = primeiro_arranjo[i];
            aux_indice++;
        }
    }

    for(int j = 0; j < n; j++){
        if(arranjo_nao_contem_elemento(arranjo_uniao, tamanho_arranjo_uniao, segundo_arranjo[j])){
            arranjo_uniao[aux_indice] = segundo_arranjo[j];
            aux_indice++;
        }
    }
}

bool arranjo_contem_elemento(int* arranjo, int n, int valor){
    for(int i = 0; i < n; i++){
        if(arranjo[i] == valor){
            return true;
        }
    }
    return false;
}

bool arranjo_nao_contem_elemento(int* arranjo, int n, int valor){
    for(int i = 0; i < n; i++){
        if(arranjo[i] == valor){
            return false;
        }
    }
    return true;
}

int conta_elementos_repetidos_entre_arranjos(int* primeiro_arranjo, int m, int* segundo_arranjo, int n){
    int contador = 0;
    for(int i = 0; i < m; i++){
        if(arranjo_contem_elemento(segundo_arranjo, n, primeiro_arranjo[i])){
            contador++;
        }
    }
    return contador;
}

int conta_elementos_unicos_entre_arranjos(int* primeiro_arranjo, int m, int* segundo_arranjo, int n){
    int contador = 0;
    for(int i = 0; i < m; i++){
        if(arranjo_nao_contem_elemento(segundo_arranjo, n, primeiro_arranjo[i])){
            contador++;
        }
    }
    return contador;
}

void ler_arranjo(int* arranjo, int n){
    for(int i = 0; i < n; i++){
        scanf("%d", &arranjo[i]);
    }
}

int main(void){
    int m, n;

    scanf("%d", &m);
    int *primeiro_arranjo = malloc(sizeof(int)*m);
    ler_arranjo(primeiro_arranjo, m);

    scanf("%d", &n);
    int *segundo_arranjo = malloc(sizeof(int)*n);
    ler_arranjo(segundo_arranjo, n);

    int elementos_unicos_primeiro_arranjo = conta_elementos_unicos_entre_arranjos(primeiro_arranjo, m, segundo_arranjo, n);
    int elementos_unicos_segundo_arranjo = conta_elementos_unicos_entre_arranjos(segundo_arranjo, n, primeiro_arranjo, m);
    int elementos_repetidos = conta_elementos_repetidos_entre_arranjos(primeiro_arranjo, m, segundo_arranjo, n);

    int tamanho_arranjo_uniao = elementos_unicos_primeiro_arranjo + elementos_unicos_segundo_arranjo + elementos_repetidos;
    int *arranjo_uniao = malloc(sizeof(int)*tamanho_arranjo_uniao);
    preencher_arranjo_uniao(arranjo_uniao, tamanho_arranjo_uniao, primeiro_arranjo, m, segundo_arranjo, n);
    imprimir_arranjo(arranjo_uniao, tamanho_arranjo_uniao);

    return 0;
}