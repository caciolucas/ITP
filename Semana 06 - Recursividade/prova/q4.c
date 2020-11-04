#include <stdio.h>

int maiorParticao(int *vetor, int N, int K, int indice, int parteRecebida[], int final[])
{
    // puts("chamada============================");
    int szParteRecebida = 0;
    for (int i = 0; parteRecebida[i] != -1; i++)
    {
        szParteRecebida++;
    }
    if (indice == N)
    {
        for (int i = 0; i < 100; i++)
        {
            if (i < szParteRecebida)
            {
                final[i] = parteRecebida[i];
            }
            else
            {
                final[i] = -1;
            }
        }

        return 0;
    }

    int maior_parte[100];
    for (int i = 0; i < 100; i++)
    {
        if (i < szParteRecebida)
        {
            maior_parte[i] = parteRecebida[i];
        }
        else
        {
            maior_parte[i] = -1;
        }
    }


    int j = 1, soma = vetor[indice];

    while (j < N - indice)
    {
        if (soma > K)
        {
            break;
        }
        soma += vetor[indice + j];
        j++;
    }
    int szParteVerificada = j-1;
    int parteVerificada[100];
    for (int i = 0; i < 100; i++)
    {
        if (i < szParteVerificada)
        {
            parteVerificada[i] = vetor[indice + i];
        }
        else
        {
            parteVerificada[i] = -1;
        }
    }
    if (szParteVerificada > szParteRecebida)
    {
        for (int i = 0; i < 100; i++)
        {
            if (i < szParteVerificada)
            {
                maior_parte[i] = parteVerificada[i];
            }
            else
            {
                maior_parte[i] = -1;
            }
        }
    }

    maiorParticao(vetor, N, K, indice + 1, maior_parte, final);
}

int main()
{

    int vetor[100], N, K, final[100], p[100];
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &vetor[i]);
        final[i] = -1;
        p[i] = -1;
    }

    maiorParticao(vetor, N, K, 0, p, final);
    for (int i = 0; final[i] >= 0; i++)
    {
        printf("%d ", final[i]);
    }
    if (final[0] == -1)
        printf("Partição Vazia");
    return 0;
}