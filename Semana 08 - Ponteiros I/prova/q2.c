#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void imprimePalavra(char *c, int salto, int tam)
{
    if (c == NULL)
    {
        printf("Palavra nao encontrada\n");
        return;
    }
    for (int i = 0; i < tam; i++)
    {
        printf("%c", *c);
        c += salto;
    }
    printf(", salto:%d\n", salto);
}

int localizaPalavra(char palavra[], char tabuleiro[10][10], char **primeiraLetra, int *salto)
{
    int tamanho = strlen(palavra);
    int i, j;

    // Novo tabuleiro e palavra todos/toda minusculo(a)
    char lowerTabuleiro[10][10];
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            lowerTabuleiro[i][j] = tolower(tabuleiro[i][j]);
        }
    }
    char lowerPalavra[10];
    for (i = 0; i < 10; i++)
    {
        lowerPalavra[i] = tolower(palavra[i]);
    }

    // Booleans conditions

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            bool achouLetra = false;
            // printf("Verificando %d %d (%c) \n", i, j, tabuleiro[i][j]);
            if (lowerTabuleiro[i][j] == lowerPalavra[0])
            {
                *primeiraLetra = &tabuleiro[i][j];
                // printf("Achou a primeira letra em %d %d\n", i, j);
                bool direita = (j + tamanho <= 10) ? true : false;
                bool esquerda = (j >= tamanho - 1) ? true : false;
                bool baixo = (i + tamanho <= 10) ? true : false;
                bool cima = (i >= tamanho - 1) ? true : false;
                // Verifica a Direita
                if (direita)
                {
                    bool achou = false;
                    // puts("Direita");
                    for (int x = 1; x < tamanho; x++)
                    {
                        // // printf("Verificando %d %d (%c) == %c \n", i, j + x, tabuleiro[i][j + x], palavra[x]);
                        if (lowerTabuleiro[i][j + x] != lowerPalavra[x])
                        {
                            // printf("eh, achou\n");
                            achou = true;
                            break;
                        }
                    }
                    if (!achou)
                    {
                        // puts("como nao achou, fim");
                        *salto = 1;
                        return 0;
                    }
                }
                // Verifica a Esquerda
                if (esquerda)
                {
                    bool achou = false;
                    // puts("Esquerda");
                    for (int x = 1; x < tamanho; x++)
                    {
                        // printf("Verificando %d %d (%c) == %c \n", i, j - x, tabuleiro[i][j - x], palavra[x]);
                        if (lowerTabuleiro[i][j - x] != lowerPalavra[x])
                        {
                            // printf("eh, achou\n");
                            achou = true;
                            break;
                        }
                    }
                    if (!achou)
                    {
                        // puts("como nao achou, fim");
                        *salto = -1;
                        return 0;
                    }
                }
                // Verificando em cima
                if (cima)
                {
                    bool achou = false;
                    // puts("Cima");
                    for (int x = 1; x < tamanho; x++)
                    {
                        // printf("Verificando %d %d (%c) == %c \n", i - x, j, tabuleiro[i - x][j], palavra[x]);
                        if (lowerTabuleiro[i - x][j] != lowerPalavra[x])
                        {
                            // printf("eh, achou\n");
                            achou = true;
                            break;
                        }
                    }
                    if (!achou)
                    {
                        // puts("como nao achou, fim");
                        *salto = -10;
                        return 0;
                    }
                }
                // Verificando Baixo
                if (baixo)
                {
                    bool achou = false;
                    // puts("Baixo");
                    for (int x = 1; x < tamanho; x++)
                    {
                        // printf("Verificando %d %d (%c) == %c \n", i + x, j, tabuleiro[i + x][j], palavra[x]);
                        if (lowerTabuleiro[i + x][j] != lowerPalavra[x])
                        {
                            // printf("eh, achou\n");
                            achou = true;
                            break;
                        }
                    }
                    if (!achou)
                    {
                        // puts("como nao achou, fim");
                        *salto = 10;
                        return 0;
                    }
                }
                // Verifica  "/" cima->baixo
                if (baixo && esquerda)
                {
                    bool achou = false;
                    // puts("Diagonal 1 \"/\" cima->baixo");
                    for (int x = 1; x < tamanho; x++)
                    {
                        // printf("Verificando %d %d (%c) == %c \n", i + x, j - x, tabuleiro[i + x][j - x], palavra[x]);
                        if (lowerTabuleiro[i + x][j - x] != lowerPalavra[x])
                        {
                            // printf("eh, achou\n");
                            achou = true;
                            break;
                        }
                    }
                    if (!achou)
                    {
                        // puts("como nao achou, fim");
                        *salto = 9;
                        return 0;
                    }
                }
                // Verifica Diagonal 2 "\" cima->baixo
                if (baixo && direita)
                {
                    bool achou = false;
                    // puts("Diagonal 2 \"\\\" cima->baixo");
                    for (int x = 1; x < tamanho; x++)
                    {
                        // printf("Verificando %d %d (%c) == %c \n", i + x, j + x, tabuleiro[i + x][j + x], palavra[x]);
                        if (lowerTabuleiro[i + x][j + x] != lowerPalavra[x])
                        {
                            // printf("eh, achou\n");
                            achou = true;
                            break;
                        }
                    }
                    if (!achou)
                    {
                        // puts("como nao achou, fim");
                        *salto = 11;
                        return 0;
                    }
                }
                // Verifica Diagonal 3 "/" baixo->cima
                if (cima && direita)
                {
                    bool achou = false;
                    // puts("Diagonal 3 \"/\" baixo->cima");
                    for (int x = 1; x < tamanho; x++)
                    {
                        // printf("Verificando %d %d (%c) == %c \n", i - x, j + x, tabuleiro[i - x][j + x], palavra[x]);
                        if (lowerTabuleiro[i - x][j + x] != lowerPalavra[x])
                        {
                            // printf("eh, achou\n");
                            achou = true;
                            break;
                        }
                    }
                    if (!achou)
                    {
                        // puts("como nao achou, fim");
                        *salto = -9;
                        return 0;
                    }
                }
                // Verifica Diagonal 4 "\" baixo->cima
                if (cima && esquerda)
                {
                    bool achou = false;
                    // puts("Diagonal 4 \"\\\" baixo->cima");
                    for (int x = 1; x < tamanho; x++)
                    {
                        // printf("Verificando %d %d (%c) == %c \n", i - x, j - x, tabuleiro[i - x][j - x], palavra[x]);
                        if (lowerTabuleiro[i - x][j - x] != lowerPalavra[x])
                        {
                            // printf("eh, achou\n");
                            achou = true;
                            break;
                        }
                    }
                    if (!achou)
                    {
                        // puts("como nao achou, fim");
                        *salto = -11;
                        return 0;
                    }
                }
            }
        }
    }
    *primeiraLetra = NULL;
}

int main()
{
    // Palavras a serem buscadas
    char palavras[5][11];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &palavras[i]);
    }
    // Preenche o Caça-Palavras
    char tabuleiro[10][10];
    for (int i = 0; i < 10; i++)
    {
        char linha[11];

        scanf("%s", &linha);
        for (int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = linha[j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        int salto;
        char *primeiraletra = NULL;
        localizaPalavra(palavras[i], tabuleiro, &primeiraletra, &salto);
        imprimePalavra(primeiraletra, salto, strlen(palavras[i]));
    }

    return 0;
}