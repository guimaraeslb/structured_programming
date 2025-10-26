#include <stdio.h>

void converter_para_binario(int numero){
    if(numero == 0){
        printf("");
    }else if(numero == 1){
        printf("1");
    }else{
        converter_para_binario((int) numero / 2);
        printf("%d", numero%2);
    }
}

int main(void){
    int num;
    scanf("%d", &num);

    converter_para_binario(num);
    return 0;
}