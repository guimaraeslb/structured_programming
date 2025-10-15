#define arranjos_h

void imprimir_arranjo(double valores[], int n);
double* preencher_arranjo(double arranjo[], int n);
int remover_valor(int valores[], int n, int valor);
bool verificar_inexistencia_valor_em_arranjo(double arranjo_ordernado[], int m, double valor);

void imprimir_arranjo(double valores[], int n){
    for(int i = 0; i < n; i++){
        printf("%f ", valores[i]);
    }
}

double* preencher_arranjo(double arranjo[], int n){
    for(int i = 0; i < n; i++){
        scanf("%lf", &arranjo[i]);
    }
    return arranjo;
}

bool verificar_inexistencia_valor_em_arranjo(double arranjo_ordernado[], int m, double valor){
    for(int i = 0; i < m; i++){
        if(arranjo_ordernado[i] == valor){
            return false;
        }
    }
    return true;
}


int remover_valor(int valores[], int n, int valor){
    int contador = 0;
    for(int i = 0; i < n; i++){
        if(valores[i] == valor){
            for(int j = i+1; j < n; j++){
                valores[j-1] = valores[j];
            }
            contador++;
        }
    }
    return contador;
}
