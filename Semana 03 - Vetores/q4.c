#include <stdio.h>

int main()
{
    int byte[8], x, n, ultimo;
    for (int i = 0; i < 8; i++)
    {
        scanf("%d", &x);
        byte[i] = x; // POPULA O BYTE
    }
    scanf(" %d",&n);
    for (int i = 0; i < n; i++)
    {
        ultimo =  byte[7];
        byte[7] = byte[6];
        byte[6] = byte[5];
        byte[5] = byte[4];
        byte[4] = byte[3];
        byte[3] = byte[2];
        byte[2] = byte[1];
        byte[1] = byte[0];
        byte[0] = ultimo;
    }
    for (int i = 0; i < 8; i++)
    {
        printf("%d ",byte[i]);
    }
    
    return 0;
}