#include <stdio.h>

int soma_v(int i, int v[], int t_v);
int max_v(int max, int i, int v[], int t_v);

int main()
{
    int n, vetor[10];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }
    printf("max v %d\n", max_v(vetor[0], 0, vetor, n));
    printf("soma v %d\n", soma_v(0, vetor, n));
    return 0;
}
int soma_v(int i, int v[], int t_v)
{
    if (i == t_v - 1)
    {
        return v[i];
    }
    return (v[i] + soma_v(i + 1, v, t_v));
}
int max_v(int max, int i, int v[], int t_v)
{
    if (i == t_v - 1)
    {
        // puts("ultimo elemento, retornando max");
        return max;
    }
    if (v[i] > max)
    {
        // printf("%d > %d\nnovo maximo setado\n",v[i],max);
        max = v[i];
    }
    // printf("passando max=%d i=%d\n",max, i+1);
    return (max_v(max, i + 1, v, t_v));
}