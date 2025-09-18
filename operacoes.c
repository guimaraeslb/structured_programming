#include <stdio.h>

int main(void){

    int op;
    int a, b, c;

    while(1){
        scanf("%d", &op);
        if(op == 0){
            break;
        }

        switch(op){
            case 1:
                scanf("%d %d", &a, &b);
                printf("%d\n", a+b);
                break;
            case 2:
                scanf("%d %d %d", &a, &b, &c);
                printf("%d\n", a+b+c);
                break;
            case 3:
                scanf("%d %d", &a, &b);
                printf("%d\n", a*b);
                break;
            default:
                printf("Operação Inválida!\n");
                break;
        }
    }
    return 0;
}