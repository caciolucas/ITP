#include <stdio.h>

int main()
{
    int a, b, v;
    printf("Entre com os operandos:\n");
    scanf("%d %d", &a, &b);
    if (a > 0 && b < 0)
    {
        v = a * b;
        printf("Valor de V=%.1f", (float)v);
    }
    else
    {
        if (a > 0)
        {
            v = a / b;
            printf("Valor de V=%.1f", (float)v);
        }
        else
        {
            v = a + b;
            printf("Valor de V=%.1f", (float)v);
        }
    }
}
