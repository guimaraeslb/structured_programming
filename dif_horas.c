#include <stdlib.h>
#include <stdio.h>

typedef struct horario{
    unsigned horas;
    unsigned minutos;
    unsigned segundos;
}horario;

void calcular_diferenca_entre_horarios(horario *primeiro_horairo, horario *segundo_horario){
    unsigned primeira_quantidade_segundos = (unsigned) ((*primeiro_horairo).horas * 3600 + (*primeiro_horairo).minutos * 60 + (*primeiro_horairo).segundos);
    unsigned segunda_quantidade_segundos = (unsigned) ((*segundo_horario).horas * 3600 + (*segundo_horario).minutos * 60 + (*segundo_horario).segundos);
    unsigned diferenca_em_segundos;
    
    if(primeira_quantidade_segundos >= segunda_quantidade_segundos){
        diferenca_em_segundos = (unsigned) primeira_quantidade_segundos - segunda_quantidade_segundos;
    }else{
        diferenca_em_segundos = (unsigned) segunda_quantidade_segundos - primeira_quantidade_segundos;
    }

    horario novo_horario;
    novo_horario.horas = (unsigned) diferenca_em_segundos / 3600;
    novo_horario.minutos = (unsigned) (diferenca_em_segundos % 3600)/60;
    novo_horario.segundos = (unsigned) (diferenca_em_segundos % 3600)%60;

    printf("Horas: %u\n", novo_horario.horas);
    printf("Minutos: %u\n", novo_horario.minutos);
    printf("Segundos: %u\n", novo_horario.segundos);
}

void ler_horario(horario *horario){
    scanf("%u", &(*horario).horas);
    scanf("%u", &(*horario).minutos);
    scanf("%u", &(*horario).segundos);
    printf("Horário lido com sucesso!\n");
}

int main(void){
    horario primeiro_horario;
    horario segundo_horario;

    ler_horario(&primeiro_horario);
    ler_horario(&segundo_horario);

    calcular_diferenca_entre_horarios(&primeiro_horario, &segundo_horario);
    return 0;
}