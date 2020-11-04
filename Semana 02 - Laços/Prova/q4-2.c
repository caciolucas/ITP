#include <stdio.h>

void printa_irmao(int n)
{
    if (n < 10)
    {
        n = '0' + n;
    }
    else if (n >= 10)
    {
        n -= 10;
        n = 'a' + n;
    }
    // printf("%c", n);
}

int main()
{
    // Bora ver para todos os valores possíveis
    int i = 200;
    printa_irmao(i / 16);
    printf("%d\n",i/16);
    printa_irmao(i % 16);
    printf("%d\n",i%16);
    puts("");
}