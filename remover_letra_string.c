#include <stdio.h>
#include <string.h>

void remover_letra(char *palavra, char letra_a_ser_removida)
{
    unsigned size = strlen(palavra);

    for (int i = 0; i < (int)size; i++)
    {
        if (((letra_a_ser_removida >= 65 && letra_a_ser_removida <= 90) && (palavra[i] - 32 == letra_a_ser_removida) || letra_a_ser_removida == palavra[i]))
        {
            for (int j = i; j < (int)size - 1; j++)
            {
                palavra[j] = palavra[j + 1];
            }
            palavra[size - 1] = 127;
        }
        else if (((letra_a_ser_removida >= 97 && letra_a_ser_removida <= 122) && palavra[i]+32)|| letra_a_ser_removida == palavra[i])
        {
            for (int j = i; j < (int)size - 1; j++)
            {
                palavra[j] = palavra[j + 1];
            }
            palavra[size - 1] = 127;
        }
    }
}

int main(void)
{
    char palavra[] = "A cidade de Santo Andre";
    char letra_a_ser_removida = 'a';
    remover_letra(palavra, letra_a_ser_removida);
    puts(palavra);
    return 0;
}