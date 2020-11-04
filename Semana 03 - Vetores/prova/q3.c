#include <stdio.h>
#include <math.h>

int main()
{
    float notas[10], n, media = 0, desvioPadrao = 0, s = 0;

    for (int i = 0; i < 10; i++)
    {
        scanf(" %f", &n);
        media += n;
        notas[i] = n;
    }
    media/=10;
    printf("%.2f ", media);
    for (int i = 0; i < 10; ++i)
        desvioPadrao += pow(notas[i] - media, 2);

    desvioPadrao = sqrt(desvioPadrao/9);
    printf("%.2f", desvioPadrao);

    return 0;
}