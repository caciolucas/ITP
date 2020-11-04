#include <stdio.h>
#include <math.h>

float makePI(int i, int p, float pi_1)
{
    // puts("funcao chamada=======================================================");
    // printf("i=%d\n",i);
    // printf("pi anterior=%f\n",pi_1);
    // printf("p=%d\n",p);
    float pi = pi_1 + (4.0 / (2.0 * i + 1.0) * pow(-1.0, i));
    // printf("pi calculado: %f\n",pi);
    // printf("(pi * pow(10, p)) - (pi_1 * pow(10, p)) == 0 \n");
    // printf("(%f * %f) - (%f * (%f)) = %f\n",pi,pow(10,p),pi_1,pow(10,p),((pi * pow(10, p)) - (pi_1 * pow(10, p))));
    // printf("(%f) - (%f) = %f\n",pi,pow(10,p),pi_1,pow(10,p),((pi * pow(10, p)) - (pi_1 * pow(10, p))));
    if (i >= 10000)
    {
        // printf("condicao de parada atingida i=%d\n", i);
        return -1;
    }
    if (floor(pi * pow(10, p)) - floor(pi_1 * pow(10, p)) == 0)
    {
        // printf("condicao de parada atingida i=%d\n", i);
        return pi;
    }
    else
    {
        // printf("chamando a funcao de novo com i=%d\n",i+1);
        return (makePI(i + 1, p, pi)); // Retorna o pi atual + o calculado na proxima iteração
    }
}

int main()
{
    int p;
    char format[20];
    scanf("%d", &p);
    // printf("%f\n", makePI(0, p, 0));
    sprintf(format, "Valor de pi %%.%dlf\n", p);
    printf(format, makePI(0,p,0));
    return 0;
}
