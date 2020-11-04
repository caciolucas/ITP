#include <stdio.h>

int a = 0;
int b = 1;
int next;
int fiboArray(int array[], int n1, int n2, int indice)
{
    next = a + b;
    a = b;
    b = next;
    if (b > n2)
    {
        return 0;
    }
    if (b >= n1 && b < n2)
    {
        array[indice] = b;
        fiboArray(array, n1, n2, indice + 1);
        return 0;
    }
    fiboArray(array, n1, n2, indice);
}

int fibnotArray(int *fibonacci, int n, int n2, int fibnot[], int indice)
{
    int achou = 0;
    if (n == n2)
    {
        return 0;
    }
    for (int i = 0; fibonacci[i] > 0; i++)
    {
        if (fibonacci[i] == n)
        {
            achou = 1;
        }
    }
    if (achou)
    {
        fibnotArray(fibonacci, n + 1, n2, fibnot, indice);
    }
    else
    {
        fibnot[indice] = n;
        fibnotArray(fibonacci, n + 1, n2, fibnot, indice + 1);
    }
}
int main()
{
    int fibonacci[30], fibnot[100], n1, n2;
    for (int i = 0; i < 30; i++)
    {
        fibonacci[i] = -1;
    }
    for (int i = 0; i < 100; i++)
    {
        fibnot[i] = -1;
    }
    scanf("%d %d",&n1,&n2);
    fiboArray(fibonacci, n1, n2, 0);
    fibnotArray(fibonacci, n1+1, n2, fibnot, 0);
    for (int i = 0; fibnot[i]>0; i++) {
      printf("%d ", fibnot[i]);
    }
}
