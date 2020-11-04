#include <stdio.h>

int main()
{
    float notas[10], n, media = 0, notasBaixas = 0;
    for (int i = 0; i < 10; i++)
    {
        scanf(" %f", &n);
        if (n < 3)
        {
            notasBaixas++; // NUMERO DE NOTAS MENORES QUE 3
        }

        notas[i] = n;
    }
    for (int i = 0; i < 10; i++)
    {
        media += notas[i]; // SOMA AS NOTAS
    }
    media /= 10; // CALCULA MEDIA

    // SITUAÇÕES POSSÍVEIS
    if (media >= 5 && !notasBaixas)
    {
        printf("Aprovado. Media = %.2f\n", media);
    }
    else if ((media >= 5 && notasBaixas) || (media >= 3 && media < 5))
    {
        printf("Reposicao. Media = %.2f\n", media);
    }
    else if (media < 3)
    {
        printf("Reprovado. Media = %.2f\n", media);
    }

    for (int i = 0; i < 10; i++)
    {
        if (notas[i] < 3)
        {
            printf("%.2f ",notas[i]);
        } /// PRINTA NOTAS MENORES QUE 3
    }
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        if (notas[i] > 5)
        {
            printf("%.2f ",notas[i]);
        }; /// PRINTA NOTAS MENORES QUE 5
    }
    return 0;
}