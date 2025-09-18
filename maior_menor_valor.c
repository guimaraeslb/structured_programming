#include <stdio.h>

int main(void)
{
    int n = 0;
    scanf("%d", &n);

    int contador = 1;
    int valor = 0;
    int maior_valor = 0;
    int menor_valor = 0;
    int num_impares = 0;
    int num_pares = 0;

    while (contador <= n)
    {
        scanf("%d", &valor);

        if (contador == 1)
        {
            maior_valor = valor;
            menor_valor = valor;
        }
        else
        {
            if (valor > maior_valor)
            {
                maior_valor = valor;
            }
            else if (valor < menor_valor)
            {
                menor_valor = valor;
            }
        }

        if (valor % 2 == 0)
        {
            num_pares++;
        }
        else
        {
            num_impares++;
        }
        contador++;
    }
    printf("Maior valor inserido: %d", maior_valor);
    printf("\nMenor valor inserido: %d", menor_valor);
    printf("\nQuantidade de números ímpares: %d", num_impares);
    printf("\nQuantidade de números pares: %d", num_pares);
}