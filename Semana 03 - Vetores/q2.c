
#include <stdio.h>

int mergeAndSort(int vA[], int a, int vB[], int b, int result[])
{
    int j, tmp;
    // printf("Recebido a: %d\n", a);
    for (int i = 0; i < a; i++)
    {
        // printf("VetorA[%d]: %d\n", i, vA[i]);
        result[i] = vA[i];
    }
    for (int i = 0; i < b; i++)
    {
        // printf("VetorB[%d]: %d\n", i, vB[i]);
        result[a + i] = vB[i];
    }

    for (int i = 0; i < a+b; i++)
    {
        for (j = i + 1; j < a+b; j++)
        {
            if (result[j] < result[i])
            {
                tmp = result[i];
                result[i] = result[j];
                result[j] = tmp;
            }
        }
    }
}
int main()
{
    int a, b, vetorA[10], vetorB[10], vetorC[20], x;
    scanf("%d %d", &a, &b);
    // printf("vetor A terá %d elementos\n", a);
    // printf("vetor B terá %d elementos\n", b);
    for (int i = 0; i < a; i++)
    {
        scanf(" %d", &x);
        vetorA[i] = x;
    }
    // printf("vetor A populado\n");
    for (int i = 0; i < b; i++)
    {
        scanf(" %d", &x);
        vetorB[i] = x;
    }
    // printf("vetor B populado\n");

    mergeAndSort(vetorA, a, vetorB, b, vetorC);

    // printf("{");
    for (int i = 0; i < a + b; i++)
    {
        printf("%d ", vetorC[i]);
    }
    // printf("}");
    return 0;
}
