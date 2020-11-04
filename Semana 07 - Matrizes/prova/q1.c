#include <stdio.h>

int main()
{
    int tabuleiro[15][15];
    int ganhouPreto = 0;
    int ganhouBranco = 0;
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            scanf("%d", &tabuleiro[i][j]);
        }
    }
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (ganhouPreto)
            {
                puts("1");
                return 0;
            }
            if (ganhouBranco)
            {
                puts("2");
                return 0;
            }

            if (tabuleiro[i][j] == 1)
            {
                int achoudiferente = 0;
                for (int k = 1; k < 5; k++)
                {
                    if (tabuleiro[i][j + k] != 1)
                    {
                        achoudiferente = 1;
                    }
                    if (k == 4 && !achoudiferente)
                    {
                        ganhouPreto = 1;
                    }
                }
                achoudiferente = 0;
                for (int k = 1; k < 5; k++)
                {
                    if (tabuleiro[i + k][j] != 1)
                    {
                        achoudiferente = 1;
                    }
                    if (k == 4 && !achoudiferente)
                    {
                        ganhouPreto = 1;
                    }
                }
                achoudiferente = 0;
                for (int k = 1; k < 5; k++)
                {
                    if (tabuleiro[i + k][j + k] != 1)
                    {
                        achoudiferente = 1;
                    }
                    if (k == 4 && !achoudiferente)
                    {
                        ganhouPreto = 1;
                    }
                }
                achoudiferente = 0;
                for (int k = 1; k < 5; k++)
                {
                    if (tabuleiro[i + k][j - k] != 1)
                    {
                        achoudiferente = 1;
                    }
                    if (k == 4 && !achoudiferente)
                    {
                        ganhouPreto = 1;
                    }
                }
            }
            if (tabuleiro[i][j] == 2)
            {
                int achoudiferente = 0;
                for (int k = 1; k < 5; k++)
                {
                    if (tabuleiro[i][j + k] != 2)
                    {
                        achoudiferente = 1;
                    }
                    if (k == 4 && !achoudiferente)
                    {
                        ganhouBranco = 1;
                    }
                }
                achoudiferente = 0;
                for (int k = 1; k < 5; k++)
                {
                    if (tabuleiro[i + k][j] != 2)
                    {
                        achoudiferente = 1;
                    }
                    if (k == 4 && !achoudiferente)
                    {
                        ganhouBranco = 1;
                    }
                }
                achoudiferente = 0;
                for (int k = 1; k < 5; k++)
                {
                    if (tabuleiro[i + k][j + k] != 2)
                    {
                        achoudiferente = 1;
                    }
                    if (k == 4 && !achoudiferente)
                    {
                        ganhouBranco = 1;
                    }
                }
                achoudiferente = 0;
                for (int k = 1; k < 5; k++)
                {
                    if (tabuleiro[i + k][j - k] != 2)
                    {
                        achoudiferente = 1;
                    }
                    if (k == 4 && !achoudiferente)
                    {
                        ganhouBranco = 1;
                    }
                }
            }
        }
    }
    puts("0");
    return 0;
}