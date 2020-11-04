#include <stdio.h>

int ordenaVetor(int *vetor, int sz);

int main()
{
    int nVetores, szVetores[10] = {0}, sz;
    scanf("%d", &nVetores);
    for (int i = 0; i < nVetores; i++)
    {
        scanf(" %d", &szVetores[i]);
    }

    // int n;

    for (int i = 0; i < nVetores; i++)
    {
        int vetor[20] = {0}, sz = szVetores[i];
        for (int i = 0; i < sz; i++)
        {
            scanf("%d", &vetor[i]);
        }
        ordenaVetor(vetor, sz);
    }

    return 0;
}

int ordenaVetor(int *vetor, int sz)
{
    int tmp, i, j;
    for (i = 0; i < sz; i++)
    {
        for (j = i + 1; j < sz; j++)
        {
            if (vetor[j] < vetor[i])
            {
                tmp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = tmp;
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        if (vetor[i] != 0)
        {
            printf("%d ", vetor[i]);
        }
    }
    puts("");
}