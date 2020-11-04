#include <stdio.h>
enum tipo
{
    vetor,
    matriz,
    invalido
};

struct vec_mat
{
    int v[20];
    int m[20][20];
    int tamanho_v;
    int linhas, colunas;
    int tipo;
};

void print(struct vec_mat item)
{
    if (item.tipo == invalido)
    {
        printf("Inválido");
    }
    else if (item.tipo == vetor)
    {
        for (int i = 0; i < item.tamanho_v; i++)
        {
            printf("%d ", item.v[i]);
        }
    }
    else if (item.tipo == matriz)
    {
        for (int i = 0; i < altura; i++)
        {
            for (int j = 0; j < largura; j++)
            {
                printf("%d ", matriz[i][j]);
            }
            puts("");
        }
    }
}

struct vec_mat mult(struct vec_mat item1, struct vec_mat item2){
    struct vec_mat res;
    // Calcula a multiplicação
    
    return res;
}

int main()
{

    char tipo, tipo2;

    struct vec_mat item, item2;
    puts("Tipo:");
    scanf("%c", &tipo);
    if (tipo == 'm')
    {
        item.tipo = matriz;
        puts("Linha e coluna:");
        scanf("%d %d", &item.linhas, &item.colunas);
        for (int i = 0; i < item.linhas; i++)
        {
            for (int j = 0; j < item.colunas; j++)
            {
                scanf("%d", &item.m[i][j]);
            }
        }
    }
    else if (tipo == 'v')
    {
        item.tipo = vetor;
        puts("tamanho");
        scanf("%d", &item.tamanho_v);
        int n = 0;
        for (int i = 0; i < item.tamanho_v; i++)
        {
            n++;
            printf("item %d\n", n);
            scanf("%d", &item.v[i]);
        }
    }
    else
    {
        item.tipo = invalido;
    }

    puts("Tipo:");
    scanf("%c", &tipo2);
    if (tipo2 == 'm')
    {
        item2.tipo = matriz;
        puts("Linha e coluna:");
        scanf("%d %d", &item2.linhas, &item2.colunas);
        for (int i = 0; i < item2.linhas; i++)
        {
            for (int j = 0; j < item2.colunas; j++)
            {
                scanf("%d", &item2.m[i][j]);
            }
        }
    }
    else if (tipo2 == 'v')
    {
        item2.tipo = vetor;
        puts("tamanho");
        scanf("%d", &item2.tamanho_v);
        int n = 0;
        for (int i = 0; i < item2.tamanho_v; i++)
        {
            n++;
            printf("item %d\n", n);
            scanf("%d", &item2.v[i]);
        }
    }
    else
    {
        item.tipo = invalido;
    }

    return 0;
}