#include <stdio.h>

int verificaPrimo(int n);

int main()
{
    int n, x;
    scanf("%d", &x);
    while (x)
    {
        scanf(" %d", &n);
        if (verificaPrimo(n))
        {
            printf("%d eh primo\n", n);
            x--;
            continue;
        }
        x--;
        printf("%d nao eh primo\n", n);
    }

    return 0;
}

int verificaPrimo(int n)
{
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }

    return 1;
}