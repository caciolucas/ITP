#include <stdio.h>

int main()
{

    // MATRIZ A
    // VARIAVEIS
    int Al, Ac, A[20][20];
    // PREENCHE MATRIZ
    scanf("%d %d", &Al, &Ac);
    for (int i = 0; i < Al; i++)
    {
        for (int j = 0; j < Ac; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    // MATRIZ b
    // VARIAVEIS
    int Bl, Bc, B[20][20];
    // PREENCHE MATRIZ
    scanf("%d %d", &Bl, &Bc);
    for (int i = 0; i < Bl; i++)
    {
        for (int j = 0; j < Bc; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }
    // MATRIZ C (resultado)
    int C[20][20];

    // CALCULO DA MULTIPLICAÇÃO
    int soma;
    for (int i = 0; i < Al; i++)
    {
        for (int j = 0; j < Bc; j++)
        {
            soma = 0;
            for (int k = 0; k < Ac; k++)
            {
                soma += A[i][k] * B[k][j];
            }
            C[i][j] = soma;
        }
    }
    for (int i = 0; i < Al; i++)
    {
        for (int j = 0; j < Bc; j++)
        {
            printf("%d ", C[i][j]);
        }
        puts("");
    }
    return 0;
}