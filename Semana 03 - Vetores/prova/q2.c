#include <stdio.h>

int main()
{
    int fibonacci[12] = {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, x;
    scanf(" %d", &x);
    // printf("%d caracteres\n", x);
    for (int i = 2; i < x; i++)
    {
        // printf("f[%d](%d = fibonacci[%d](%d)+fibonacci[%d](%d)\n",i,fibonacci[i-1]+fibonacci[i-2],i-1,fibonacci[i-1],i-2,fibonacci[i-2]);
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
    printf("%d",fibonacci[x-1]);
    return 0;
}
