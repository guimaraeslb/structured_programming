#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void mostrar_arranjo(int* arranjo, unsigned n){
    for(int i = 0; i < n; i++){
        printf("%d ", arranjo[i]);
    }
}

bool nao_esta_no_arranjo(int *arranjo, unsigned n, int valor)
{
    for (int i = 0; i < n; i++)
    {
        if (arranjo[i] == valor)
        {
            return false;
        }
    }
    return true;
}

bool esta_no_arranjo(int *arranjo, unsigned n, int valor)
{
    for (int i = 0; i < n; i++)
    {
        if (arranjo[i] == valor)
        {
            return true;
        }
    }
    return false;
}

void preencher_arranjo(int *first_set, unsigned size_of_first_set, int *second_set, unsigned size_of_second_set, int *intersection_set, unsigned size_of_intersection)
{
    for (int i = 0; i < size_of_intersection; i++)
    {
        for (int j = 0; j < size_of_first_set; j++)
        {
            if (esta_no_arranjo(second_set, size_of_second_set, first_set[j]) && nao_esta_no_arranjo(intersection_set, size_of_intersection, first_set[j]))
            {
                intersection_set[i] = first_set[j];
                break;
            }
        }
    }
}

unsigned tamanho_interseccao(int *first_set, unsigned size_of_first_set, int *second_set, unsigned size_of_second_set)
{
    unsigned contador = 0;
    for (int i = 0; i < size_of_first_set; i++)
    {
        if (esta_no_arranjo(second_set, size_of_second_set, first_set[i]))
        {
            contador++;
        }
    }
    return contador;
}

void ler_arranjo(int *arranjo, unsigned n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arranjo[i]);
    }
}

int main(void)
{
    unsigned size_of_first_set, size_of_second_set;

    scanf("%u", &size_of_first_set);
    int *first_set = malloc(sizeof(int) * size_of_first_set);
    ler_arranjo(first_set, size_of_first_set);

    scanf("%u", &size_of_second_set);
    int *second_set = malloc(sizeof(int) * size_of_second_set);
    ler_arranjo(second_set, size_of_second_set);

    unsigned size_of_intersection = tamanho_interseccao(first_set, size_of_first_set, second_set, size_of_second_set);
    int *intersection_set = malloc(sizeof(int) * size_of_intersection);

    preencher_arranjo(first_set, size_of_first_set, second_set, size_of_second_set, intersection_set, size_of_intersection);
    mostrar_arranjo(intersection_set, size_of_intersection);

    return 0;
}