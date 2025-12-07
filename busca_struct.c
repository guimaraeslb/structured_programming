#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa{
    char nome[50];
    int altura;
    int idade;
}pessoa;

int comparar_por_ano(pessoa *p, int idade){
    return (*p).idade - idade;
}

int comparar_por_altura(pessoa *p, int altura){
    return (*p).altura - altura;
}

int busca_linear(pessoa *pessoas, int n, int valor, int *comparar(pessoa*, int)){
    for(int i = 0; i < n; i++){
        if(comparar(pessoas+i, valor) == 0){
            return 0;
        }
    }
    return -1;
}


int main(void){

    pessoa pessoas[] = {{"Luccas", 182, 21}, {"Eduardo", 160, 14}};
    printf("%d\n", busca_linear(pessoas, 2, 14, comparar_por_ano));
    printf("%d\n", busca_linear(pessoas, 2, 182, comparar_por_altura));
    return 0;
}