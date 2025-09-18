#include <stdio.h>

int main(void)
{
    int valor = 0;
    int soma_quadrado = 0;
    int soma = 0;
    int quadrado_soma = 0;

    while (1)
    {
        scanf("%d", &valor);

        if (valor < 0)
        {
            quadrado_soma = soma * soma;
            printf("%d", (soma_quadrado - quadrado_soma));
            break;
        }

        soma = soma + valor;
        soma_quadrado = soma_quadrado + (valor * valor);
    }
    return 0;
}
