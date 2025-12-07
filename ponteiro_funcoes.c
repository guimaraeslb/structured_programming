#include <stdio.h>
#include <stdlib.h>


int multiplicacao(int x, int y){
    return x*y;
}

int subtracao(int x, int y){
    return x-y;
}

int soma(int x, int y){
    return x+y;
}

void calcular(int x, int y, int *operacao(int, int)){
     printf("%d\n", operacao(x, y));
}

int main(void){
    int x, y, opc;

    printf("Insira o priimeiro valor: ");
    scanf("%d", &x);

    printf("Insira o segundo valor:" );
    scanf("%d", &y);

    printf("Escolha a operacao: [1] Soma, [2] Subtracao ou [3] Multiplicacao: ");
    scanf("%d", &opc);

    switch(opc){
        case 1:
            calcular(x,y,soma);
            break;
        case 2:
            calcular(x,y, subtracao);
            break;
        case 3:
            calcular(x,y,multiplicacao);
            break;
        default:
            printf("Erro");
            break;
    }

    return 0;
}