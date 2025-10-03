#include <stdio.h>
#include "arranjos.h"

void trocar_valores(int valores[], int n, int idxi, int idxf){
    int aux = valores[idxi];
    valores[idxi] = valores[idxf];
    valores[idxf] = aux;
    imprimir_arranjo(valores, n);
}

int main(void){
    int valores[] = {1,3,5,7,9};
    trocar_valores(valores, 5, 2, 4);
    return 0;
}