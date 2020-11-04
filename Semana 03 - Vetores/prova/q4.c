#include <stdio.h>

int main()
{
    int vetor[100], n, nDuplicados = 0, duplicados[50];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %d", &vetor[i]);
    }



    for (int i = 0; i < n; i++)
    {
        int verificado = vetor[i];
        // printf("Verificando[%d] %d\n",i,verificado);
        
        for (int j = 0; j < n; j++)
        {
            if (j==i)
            {
                break;
            }
            
            int checado = vetor[j];
            // printf("Checando[%d] %d\n",j,vetor[j]);
            if (verificado == checado)
            {
                for (int k = 0; i < 50; i++)
                {
                    if (vetor[i] == duplicados[k])
                    {
                        break;
                    }
                }
                // printf("Duplicata encontrada\n");
                nDuplicados++;
                break;
            }
        }
    }

    printf("%d", nDuplicados);
    return 0;
}