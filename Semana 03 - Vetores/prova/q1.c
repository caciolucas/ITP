#include <stdio.h>
#include <math.h>


int main()
{
    int size, produtoEscalar = 0, vetorA[10], vetorB[10], x;
    scanf("%d", &size);
    for (int i = 0; i < size; i++) //POPULA VETOR A
    {
        scanf(" %d", &x);
        vetorA[i] = x;
    }
    for (int i = 0; i < size; i++) //POPULA VETOR B
    {
        scanf(" %d", &x);
        vetorB[i] = x;
    }
    for (int i = 0; i < size; i++) //CALCULA PRODUTO ESCALAR
    {
        // printf("%d*%d=%d\n", vetorA[i], vetorB[i], vetorA[i] * vetorB[i]);
        produtoEscalar += vetorA[i] * vetorB[i];
    }
    int somaA = 0, somaB = 0;

    for (int i = 0; i < size; i++) //CALCULO COMPRIMENTO VETOR A
    {
        somaA+=pow(vetorA[i],2);
        somaB+=pow(vetorB[i],2);
    }

    printf("%d %.2f %.2f", produtoEscalar,sqrt(somaA),sqrt(somaB));
    return 0;
}