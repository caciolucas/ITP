#include <stdio.h>
#include <string.h>
#include <locale.h>
int ida = 0;
int volta;

int checaPalindromo(char *texto);

int main()
{
    char texto[101];
    setlocale(LC_ALL, "");
    gets(texto);
    // texto[strlen(texto)-2]='\0';
    volta = strlen(texto) - 1;
    if (checaPalindromo(texto))
    {
        printf("O texto %s é palíndromo\n", texto);
        // printf("O texto %s e palindromo\n", texto);
        return 0;
    }
    printf("O texto %s não é palíndromo\n", texto);
    // printf("O texto %s nao eh palindromo\n", texto);
}

int checaPalindromo(char *texto)
{
    // puts("===========================");
    // printf("Iniciando comparacao\n");
    if (texto[ida] == ' ')
    {
        ida++;
        // printf("espaco encontrado na ida pulando caractere\n");
    }
    if (texto[volta] == ' ')
    {
        volta--;
        // printf("espaco encontrado na volta pulando caractere\n");
    }
    // printf("%s[%d](%c) == %s[%d](%c) =>%d\n",texto,ida, texto[ida], texto,volta,texto[volta], texto[ida] == texto[volta]);
    if (texto[ida] == texto[volta])
    {
        if (ida == strlen(texto) / 2)
        {
            // printf("chegamos na metade\n");
            return 1;
        }
        ida++;
        volta--;
        return (checaPalindromo(texto));
    }

    return 0;
}