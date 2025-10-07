#include <stdio.h>

int multiplicacao_em_soma(int a, int b){
    if(b == 1){
        return a;
    }
    return a + multiplicacao_em_soma(a,b-1);
}

int main(void){
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    printf("%d", multiplicacao_em_soma(a, b));
    return 0;
}