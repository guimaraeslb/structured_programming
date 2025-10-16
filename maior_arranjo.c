#include <stdio.h>
#include <stdlib.h>

int* preencher_arranjo(int* arranjo, unsigned original_size, unsigned needed_size){
    int diferenca = needed_size - original_size;
    int *novo_arranjo = malloc(sizeof(int)*needed_size);

    for(int i = 0; i < diferenca; i++){
        novo_arranjo[i] = 0;
    }

    for(int j = diferenca; j < needed_size; j++){
        novo_arranjo[j] = arranjo[j-original_size];
    }
    return novo_arranjo;
}

int quem_eh_maior(int* primeiro_arranjo, unsigned m, int* segundo_arranjo, unsigned n){
    if(m != n){
        if(m > n){
            int *novo_segundo_arranjo = preencher_arranjo(segundo_arranjo, n, m);
            printf("%d", quem_eh_maior(primeiro_arranjo, m, novo_segundo_arranjo, m));
        }else{
            int *novo_primeiro_arranjo = preencher_arranjo(primeiro_arranjo, m, n);
            printf("%d", quem_eh_maior(novo_primeiro_arranjo, n, segundo_arranjo, n));
        }

    }else{
        int primeiro_arranjo_count = 0;
        int segundo_arranjo_count = 0;

        for(int i = 0; i < (int) m; i++){
            if(primeiro_arranjo[i] > segundo_arranjo[i]){
                primeiro_arranjo_count++;
            }else if(segundo_arranjo[i] > primeiro_arranjo[i]){
                segundo_arranjo_count++;
            }else{
                primeiro_arranjo_count++;
                segundo_arranjo_count++;
            }
        }
        
        if(primeiro_arranjo_count != segundo_arranjo_count){
            if(primeiro_arranjo_count > segundo_arranjo_count){
                return 1;
            }
            return -1;
        }else{
            return 0;
        }
    }
}

void ler_arranjo(int* arranjo, unsigned n){
    for(int i = 0; i < (int) n; i++){
        scanf("%d", &arranjo[i]);
    }
}

int main(void){
    unsigned m, n;

    scanf("%u", &m);
    int *primeiro_arranjo = malloc(sizeof(int)*m);
    ler_arranjo(primeiro_arranjo, m);

    scanf("%u", &n);
    int *segundo_arranjo = malloc(sizeof(int)*n);
    ler_arranjo(segundo_arranjo, m);

    printf("%d", quem_eh_maior(primeiro_arranjo, m, segundo_arranjo, n));
    return 0;
}