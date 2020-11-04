#include <stdio.h>

int checkPerfeito(int numero);

int main()
{
    int n;
    scanf("%d", &n);
    checkPerfeito(n);
    return 0;
}

int checkPerfeito(int numero)
{
    int x = 0, divisores[100], soma = 0, i ;
    for (i = 1; i <= numero / 2; i++)
    {
        if (numero % i == 0)
        {
            divisores[x] = i;
            soma += i;
            x++;
        }
    }

    if (soma == numero)
    {
        printf("%d = ", numero);
        for (i = 0; i < x; i++)
        {
            if (i != x - 1)
            {
                printf("%d + ",divisores[i]);
                continue;
            }
            printf("%d",divisores[i]);
        }

        return 1;
    }
    printf("%d nao eh perfeito\n", numero);
    return 0;
}
