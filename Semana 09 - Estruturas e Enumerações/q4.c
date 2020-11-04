#include <stdio.h>
#include <string.h>
struct res
{
    char str[20];
    int pos_l, pos_c;
};

struct res menorString(char matriz[10][10][21], int largura, int altura){
    struct res menor;
    strcpy(menor.str,matriz[0][0]);


    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            if (strlen(menor.str)>strlen(matriz[i][j]))
            {
               strcpy(menor.str,matriz[i][j]);
               menor.pos_l=i;
               menor.pos_c=j;
            }            
        }
    }
    return menor;
}
int main()
{
    int altura, largura;
    char matriz[10][10][21];
    struct res resposta;
    // int n=0;
    // puts("Altura e largura");
    scanf("%d %d", &altura, &largura);
    // puts("Insira as palavras");
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            // n++;
            // printf("Palavra %d\n",n);
            scanf("%s", &matriz[i][j]);
        }
    }

    resposta = menorString(matriz,largura,altura);
    printf("%d %d\n%s",resposta.pos_l,resposta.pos_c,resposta.str);
    return 0;
}