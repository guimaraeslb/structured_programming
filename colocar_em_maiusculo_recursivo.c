#include <stdio.h>
#include <stdbool.h>
#include <string.h>


void colocar_em_caps_lock(char *str){
    unsigned size = strlen(str);
    
    if(size == 1){
        if(str[0] >= 97 && str[0] <= 122){
            str[0] = str[0] - 32;
        }
    }else{
        if(str[0] >= 97 && str[0] <= 122){
            str[0] = str[0] - 32;
            colocar_em_caps_lock(str+1);
        }else if(str[0] >= 65 && str[0] <= 90){
            colocar_em_caps_lock(str+1);
        }
    }
}

int main(void){
    char str[] = "Luccas";
    colocar_em_caps_lock(str);
    puts(str);
    return 0;
}