#include <stdio.h>

int main()
{
    int x, y, res=0;
    scanf("%d %d", &x, &y);
    while (y >= x)
    {
        res += y;
        y--;
    }
    printf("%d", res);
}