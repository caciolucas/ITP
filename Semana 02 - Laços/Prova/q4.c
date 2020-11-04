#include <stdio.h>
int main()
{
    int R, G, B;
    while (1)
    {
        scanf("%d %d %d", &R, &G, &B);
        if (R < 0 || G < 0 || B < 0)
        {
            break;
        }
        else
        {
            printf("%02X%02X%02X\n", R, G, B);
        }
    }
    return 0;
}