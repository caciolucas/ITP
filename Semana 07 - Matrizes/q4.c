#include <stdio.h>

int main()
{
    int C, L, A[20][20], B[20][20], resultado[20][20];
    scanf("%d %d", &L, &C);
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < C; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < C; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < C; j++)
        {
            resultado[i][j] = A[i][j] + B[i][j];
        }
    }
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < C; j++)
        {
            printf("%d ", resultado[i][j]);
        }
        puts("");
    }
    return 0;
}
