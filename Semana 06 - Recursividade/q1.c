#include <stdio.h>
#include <math.h>

double seriesTaylor(int i, int x);
double fat(int n);

int x, n;
int main()
{
    scanf("%d %d", &x, &n);
    printf("%f\n",seriesTaylor(n,x));
    printf("%f",exp(x));
    return 0;
}

double seriesTaylor(int i, int x)
{
    if (i <= 0)
    {
        return 1;
    }
    else
    {
        return (pow(x, i) / fat(i)) + seriesTaylor(i-1,x);
    }
}

double fat(int n)
{
    int result;
    if (n <= 1)
        return 1;
    else
        return n * fat(n - 1);
}
