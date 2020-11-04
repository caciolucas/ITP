#include <stdio.h>

int main()
{
    int n, res;
    float  x, y;
    scanf("%d", &n);
    // printf("N recebido: %d\n", n);
    scanf(" %f", &x);
    // printf("X recebido: %f\n", x);
    n -= 1;
    // printf("%d números restantes\n", n);
    scanf(" %f", &y);
    // printf("Y recebido: %f\n", y);
    n -= 1;
    // printf("%d números restantes\n", n);
    res = (y > x) ? 1 : -1;
    if(x==y){res=0;}
    x = y;
    // printf("X atualizado: %f\n", x);
    // printf("Saída: %d\n", res);
    while (n)
    {
        scanf(" %f", &y);
        // printf("Y recebido: %f\n", y);
        switch (res)
        {
        case 1:
            if (y > x)
            {
                // printf("y>x %f>%f\n", y, x);
                x = y;
                // printf("X atualizado: %f\n", x);
            }
            else
            {
                // printf("y<x %f<%f\n", y, x);
                res = 0;
                // printf("Saída: %d\n", x);
                // printf("Saíndo");
                break;
            }
            break;
        case -1:
            if (y < x)
            {
                // printf("y<x %d<%d\n", y, x);
                x = y;
                // printf("X atualizado: %d\n", x);
            }
            else
            {
                // printf("y>x %d>%d\n", y, x);
                res = 0;
                // printf("Saída: %d\n", x);
                // printf("Saíndo");
                break;
            }
            break;
        }
        n--;
        // printf("%d números restantes:\n", n);
    }
    printf("%d", res);
}