#include <stdio.h>

int main()
{
    char frase[31];
    gets(frase);
    int maisculas = 0, minusculas = 0;
    for (int i = 0; frase[i] != 0; i++)
    {
        if (frase[i] >= 65 && frase[i] <= 90){maisculas++;}
        else if (frase[i] >= 97 && frase[i] <= 122){minusculas++;}
    }
    printf("%d %d\n", maisculas, minusculas);
    return 0;
}