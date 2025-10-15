#include <stdio.h>

void troca(int* pa, int* pb){
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

int main(void){
    int a = 10, b = 20;
    troca(&a, &b);
    printf("%d %d\n", a, b);
    return 0;
}