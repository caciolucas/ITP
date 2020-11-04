#include <stdio.h>
#include <string.h>

void multiplexador(char *A, char *B);

int main()
{
    char A[41], B[51];
    gets(A);
    gets(B);
    multiplexador(A, B);
    return 0;
}

void multiplexador(char *A, char *B)
{
    // Recupera os tamanhos das strings passadas
    int sizeA = strlen(A), sizeB = strlen(B), i;
    // Pra nao usar ABS e pegar o valor modular da diferença, usei esse ternario.
    for (i = 0; A[i] != 0 && B[i] != 0; i++) 
    {
        printf("%c", A[i]);
        printf("%c", B[i]);
    }
    // Se a string B for maior
    if (sizeB > sizeA)
    {
        // vão ser printados os valores que estão desde a posição do ultimo
        // elemento de A até o que o i atinja o tamanho de B e todos sejam
        // impressos.
        for (; i < sizeB; i++)
        {
            printf("%c",B[i]);
        }
                
    }
}
