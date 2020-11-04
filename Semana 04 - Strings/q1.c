#include <stdio.h>
#include <string.h>

int main()
{
    char frase[101];
    int r = 1;

    gets(frase);
    // a r a r a
    // 0 1 2 3 4

    // p a l a v r a
    // 0 1 2 3 4 5 6

    for (int i = 0; i < strlen(frase); i++)
    {
        if (frase[i] != frase[strlen(frase) - i - 1])
        // frase[0](a) == frase[5 - 0 - 1 = 4](a)
        // frase[1](r) == frase[5 - 1 - 1 = 3](a)
        // ...

        // frase[0](p) != frase[7 - 0 - 1 = 6](a) Ja entra no if e diz q a respsota sera 0 (false)
        // frase[1](a) != frase[7 - 1 - 1 = 5](r)
        {
            r = 0;
            break;
        }
    }

    if (r)
    {
        printf("%s é um palíndromo", frase);
    }
    else
    {
        printf("%s não é um  palíndromo", frase);
    }
    return 0;
}