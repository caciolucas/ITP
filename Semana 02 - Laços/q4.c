#include <stdio.h>

int main()
{
    int t = 0, n = 6, a;

    while (n)
    {
        scanf("%d", &a);
        if (a>=18)
        {
            t++;
        }
        
        n--;
    }
    printf("%d",t);
    return 0;
}