#include <stdio.h>

void imprime_indireto(int **A_indireto, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", **(A_indireto + i));
}
void imprime(int A[], int n)
{
    for (int i = 0; i < n; i++) {
      printf("%d ", A[i]);
    }
    puts("");
}
void ordena_indireto(int **A_indireto, int n)
{
    int i, j, *swap;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (*A_indireto[j] > *A_indireto[j + 1])
            {
                swap = A_indireto[j];
                A_indireto[j] = A_indireto[j + 1];
                A_indireto[j + 1] = swap;
            }
        }
    }
}

int main()
{
    int n, A[100], *A_indireto[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < n; i++)
    {
        A_indireto[i] = &A[i];
    }
    ordena_indireto(A_indireto, n);
    imprime_indireto(A_indireto, n);
    puts("");
    imprime(A,n);

    return 0;
}