#include <stdio.h>
#include <math.h>

int digitoNaPosicao(int numero, int posicao);

int main()
{
    int p, x;
    scanf("%d", &x);
    scanf("%d", &p);

    printf("O digito na posicao solicitada e %d",digitoNaPosicao(x,p));
    return 0;
}

int digitoNaPosicao(int numero, int posicao)
{
    int r = numero / pow(10, posicao);
    return r % 10; ;
}
