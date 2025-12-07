#include <stdio.h>
#include <stdlib.h>

typedef struct carro{
    char marca[20];
    int ano;
}carro;

int comparar_por_ano(carro *c, int ano){
    return (*c).ano - ano;
}

int busca_binaria(carro *carros, int n, int ano, int *comparar(carro*, int)){

    if(n == 1){
        if(carros[0].ano == ano){
            return 0;
        }else{
            return -1;
        }
    }else{
        int meio = n / 2;
        
        if(carros[meio].ano == ano){
            return 0;
        }else if(carros[meio].ano > ano){
            busca_binaria(carros, n - meio, ano, comparar);
        }else{
            busca_binaria(carros+meio, n - meio, ano, comparar);
        }
    }   
}

int main(void){
    carro carros[] = {{"Audi", 2020}, {"BMW", 2022}, {"GM", 2025}};
    printf("%d\n", busca_binaria(carros, 3, 2024, comparar_por_ano));

    return 0;
}