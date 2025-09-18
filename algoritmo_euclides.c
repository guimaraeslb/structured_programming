#include <stdio.h>

int main(void)
{
    int a, b, temp;
    scanf("%d %d", &a, &b);

    while(1){
        if(a % b == 0){
            printf("O MDC entre %d e %d é: %d\n", a, b, b);
            break;
        }
        temp = a;
        a = b;
        b = (temp % b);
    }
    return 0;
}
