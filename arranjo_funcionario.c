#include <stdlib.h>
#include <stdio.h>

typedef struct data{
    unsigned dia, mes, ano;
}data;

typedef struct funcionario{
    char nome[51];
    char cargo[21];
    float salario;
    data data_admissao;
}funcionario;

unsigned funcionario_tempo_casa_aceito(funcionario *funcionario, data data_atual){
    unsigned tempo_casa;

    if(data_atual.ano == (*funcionario).data_admissao.ano   ){
        return 0;
    }else if((*funcionario).data_admissao.mes > data_atual.mes){
        tempo_casa = data_atual.ano - (*funcionario).data_admissao.ano - 1;
        return tempo_casa;
    }else{
        tempo_casa = data_atual.ano - (*funcionario).data_admissao.ano;
        return tempo_casa;
    }
}

void funcionario_aumentar_salario(funcionario *funcionario, unsigned percentual_aumento_salario){
    (*funcionario).salario = ((*funcionario).salario + ((*funcionario).salario * ((float) percentual_aumento_salario/100)));
}

void data_imprimir(data *data){
    printf("Dia de admissao: %u\n", (*data).dia);
    printf("Mes de admissao: %u\n", (*data).mes);
    printf("Ano de admissao: %u\n", (*data).ano);
}

void funcionario_imprimir(funcionario *funcionario){
    printf("Nome: %s\n", (*funcionario).nome);
    printf("Cargo: %s\n", (*funcionario).cargo);
    printf("Salario: %f\n", (*funcionario).salario);
    data_imprimir(&((*funcionario).data_admissao));
}

void data_admissao_ler(funcionario *funcionario){
    printf("Insira o seu dia de admissao: ");
    scanf("%u", &(*funcionario).data_admissao.dia);


    printf("Insira o seu mes de admissao: ");
    scanf("%u", &(*funcionario).data_admissao.mes);


    printf("Insira o seu ano de admissao: ");
    scanf("%u", &(*funcionario).data_admissao.ano);

}

void funcionario_ler(funcionario *funcionario){
    scanf("%50s", (*funcionario).nome);
    scanf("%20s", (*funcionario).cargo);
    scanf("%f", &(*funcionario).salario);
}

int main(void){
    funcionario *funcionarios = malloc(sizeof(funcionario)*3);
    data data_atual = {10, 11, 2025};

    //Lendo funcionários
    for(int i = 0; i < 3; i++){
        funcionario funcionario;
        funcionario_ler(&funcionario);
        data_admissao_ler(&funcionario);
        funcionarios[i] = funcionario;
    }

    //Imprimindo funcionários
    for(int i = 0; i < 3; i++){
        funcionario_imprimir(funcionarios+i);
    }

    //Verifica aumento de salario
    for(int i = 0; i < 3; i++){
        unsigned tempo_casa = funcionario_tempo_casa_aceito(funcionarios+i, data_atual);
        if(tempo_casa > 5){
            unsigned percentual_aumento_salario;
            printf("Insira o percental de aumento de salario desse funcionario: ");
            scanf("%u", &percentual_aumento_salario);
            funcionario_aumentar_salario(funcionarios+i, percentual_aumento_salario);
        }
    }

    //Imprimindo funcionários
    for(int i = 0; i < 3; i++){
        funcionario_imprimir(funcionarios+i);
    }

    return 0;
}