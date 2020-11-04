#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

struct Pessoa
{
    char nome[21];
    int idade;
    int sexo;
};

struct Pessoa criar(char nome[21], int idade, int sexo)
{
    struct Pessoa pessoa;
    strcpy(pessoa.nome, nome);
    pessoa.idade = idade;
    pessoa.sexo = toupper(sexo);
    return pessoa;
};

void inserir(struct Pessoa pessoa, struct Pessoa pessoas[20])
{
    int i;
    for (i = 0; i < 20; i++)
    {
        if (pessoas[i].idade < 0)
        {
            pessoas[i] = pessoa;
            break;
        }
    }

    return;
}
void deletar(struct Pessoa pessoa, struct Pessoa pessoas[20])
{
    struct Pessoa vazio;
    vazio.idade = -1;
    int i, j;
    for (i = 0; i < 20; i++)
    {
        if (strcmp(pessoas[i].nome, pessoa.nome) == 0 &&
            pessoas[i].idade == pessoa.idade &&
            pessoas[i].sexo == pessoa.sexo)
        {

            for (j = i; j < 20; j++)
            {
                if (j == 19)
                {
                    pessoas[j] = vazio;
                }
                else
                {
                    pessoas[j] = pessoas[j + 1];
                }
            }
            break;
        }
    }

    return;
}
void imprimir(struct Pessoa listaPessoas[20])
{
    int i;
    for (i = 0; i < 20; i++)
    {
        if (listaPessoas[i].idade < 0)
        {
            break;
        }
        printf("%s,%d,%c\n", listaPessoas[i].nome,
               listaPessoas[i].idade,
               listaPessoas[i].sexo);
    }
    return;
}

int main()
{
    struct Pessoa listaPessoas[20];
    int i;
    for (i = 0; i < 20; i++)
    {
        listaPessoas[i].idade = -1;
    }

    while (true)
    {
        char operacao[21];
        scanf("%[^\n]%*c", operacao);

        if (strcmp(operacao, "inserir") == 0)
        {
            // puts("Dados:");
            char dados[40];
            scanf("%[^\n]%*c", dados);

            char nome[21];
            int idade;
            char sexo;
            // printf("Dados: \"%s\"",dados);
            sscanf(dados, "%[^,],%d,%c", nome, &idade, &sexo);

            struct Pessoa pessoa = criar(nome, idade, sexo);
            inserir(pessoa, listaPessoas);
        }
        else if (strcmp(operacao, "deletar") == 0)
        {
            char dados[40];
            scanf("%[^\n]%*c", dados);

            char nome[21];
            int idade;
            char sexo;
            sscanf(dados, "%[^,],%d,%c", nome, &idade, &sexo);
            // if (dados[0] != '-') {
                
            // } else {
            //     sscanf(&dados[1], "%[^,],%d,%c", nome, &idade, &sexo);
            // }

            struct Pessoa pessoa = criar(nome, idade, sexo);
            deletar(pessoa, listaPessoas);
        }
        else
        {
            imprimir(listaPessoas);
            return 0;
        }
    }

    return 0;
}
