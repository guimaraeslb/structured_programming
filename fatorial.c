#include <stdio.h>

int fatorial(int num){
    if(num <= 0){
        return 1;
    }
    return (num * fatorial(num - 1));
}

int main(void)
{
    int num = 0;
    scanf("%d", &num);
    printf("%d", fatorial(num));
    return 0;
}
