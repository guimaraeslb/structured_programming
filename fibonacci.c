#include <stdio.h>

int fibonacci(int termo){
    if(termo <= 2){
        return 1;
    }
    return (fibonacci(termo - 1) + fibonacci(termo - 2));
}

int main(void)
{
    int termo = 0;
    scanf("%d", &termo);
    printf("%d", fibonacci(termo));
    return 0;
}