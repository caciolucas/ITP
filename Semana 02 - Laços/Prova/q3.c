#include <stdio.h>

int main()
{
    int a, b, min, max, x;
    scanf("%d %d", &a, &b);
    max = (a > b) ? a : b;
    min = (a < b) ? a : b;
    if (a != b && max-min>1)
    {
        x = min;
        x += 1;
        while (x < max)
        {
            printf("%d ", x);
            x += 1;
        }
    }
    else
    {
        printf("intervalo vazio");
    }
}