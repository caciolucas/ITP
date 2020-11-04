#include <stdio.h>
#include <string.h>

int main()
{
    char frase[31], trecho[31];
    int i, j, encontrou;

    gets(trecho);
    gets(frase);
    for (i = 0; i <= strlen(frase) - strlen(trecho); i++)
    {
        encontrou = 1;
        for (j = 0; j < strlen(trecho); j++)
        {
            if (frase[i + j] != trecho[j])
            {
                encontrou = 0;
                break;
            }
        }
        if (encontrou)
        {
            printf("%d\n", i + 1);
            return 0;
        }
    }
    printf("0\n");

    return 0;
}