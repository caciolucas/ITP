#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa_t
{
    char nome[20];
    int id;
} pessoa;
typedef struct irmao_t
{
    int id1;
    int id2;
} irmao;
typedef struct bd_pessoas_t
{
    pessoa pessoas[20];
    int num_pessoas;
} bd_pessoas;
typedef struct bd_irmaos_t
{
    irmao irmaos[50];
    int num_relacoes;
} bd_irmaos;

typedef struct c_vector_t
{
    int elementos[50];
    int len;
} c_vector;

char *get_nome(bd_pessoas *Pessoas, int id)
{
    for (int i = 0; i < Pessoas->num_pessoas; i++)
    {
        if (Pessoas->pessoas[i].id == id)
        {
            return Pessoas->pessoas[i].nome;
        }
    }

    printf("Erro em get_nome()\n");
    exit(0);
}

bd_pessoas inserir_pessoa(pessoa Pessoa, bd_pessoas Pessoas)
{
    for (int i = 0; i <= Pessoas.num_pessoas; i++)
    {
        if (Pessoas.pessoas[i].id == Pessoa.id)
        {
            printf("Identificador %d duplicado!\n", Pessoa.id);
            return Pessoas;
        }
    }
    Pessoas.pessoas[Pessoas.num_pessoas] = Pessoa;
    Pessoas.num_pessoas++;

    return Pessoas;
}
bd_irmaos inserir_irmao(bd_pessoas Pessoas, bd_irmaos Irmaos, int id1, int id2)
{
    for (int i = 0; i < Irmaos.num_relacoes; i++)
    {
        if (id1 == Irmaos.irmaos[i].id1)
        {
            if (id2 == Irmaos.irmaos[i].id2)
            {
                printf("Parentesco %d %d já cadastrado!\n", id1, id2);
                return Irmaos;
            }
        }
        else if (id1 == Irmaos.irmaos[i].id2)
        {
            if (id2 == Irmaos.irmaos[i].id1)
            {
                printf("Parentesco %d %d já cadastrado!\n", id1, id2);
                return Irmaos;
            }
        }
    }
    irmao novaRelacao;
    novaRelacao.id1 = id1;
    novaRelacao.id2 = id2;

    Irmaos.irmaos[Irmaos.num_relacoes] = novaRelacao;
    Irmaos.num_relacoes++;

    return Irmaos;
}
void imprimir_irmaos(bd_irmaos Irmaos, bd_pessoas Pessoas, int id)
{
    c_vector listaIrmaos;
    listaIrmaos.len = 0;
    char *nome = get_nome(&Pessoas, id);
    for (int i = 0; i < Irmaos.num_relacoes; i++)
    {
        if (Irmaos.irmaos[i].id1 == id || Irmaos.irmaos[i].id2 == id)
        {
            if (Irmaos.irmaos[i].id1 == id)
            {
                listaIrmaos.elementos[listaIrmaos.len] = Irmaos.irmaos[i].id2;
            }
            if (Irmaos.irmaos[i].id2 == id)
            {
                listaIrmaos.elementos[listaIrmaos.len] = Irmaos.irmaos[i].id1;
            }
            listaIrmaos.len++;
        }
    }
    if (listaIrmaos.len)
    {
        for (int i = 0; i < listaIrmaos.len; i++)
        {
            char *nomeIrmao = get_nome(&Pessoas, listaIrmaos.elementos[i]);
            printf("%s é irmão de %s\n", nomeIrmao, nome);
        }
    }
    else
    {
        printf("%s não tem irmãos cadastrados\n", nome);
    }
}
int main()
{
    bd_pessoas Pessoas;
    for (int i = 0; i < 20; i++)
    {
        Pessoas.pessoas[i].id = -1;
    }
    Pessoas.num_pessoas = 0;

    bd_irmaos Irmaos;
    for (int i = 0; i < 50; i++)
    {
        Irmaos.irmaos[i].id1 = -1;
        Irmaos.irmaos[i].id2 = -1;
    }

    Irmaos.num_relacoes = 0;
    while (true)
    {
        char operacao;
        // puts("Operacao:");
        scanf("%c", &operacao);
        if (operacao == 'i')
        {
            // puts("Digite as informacoes:");
            pessoa Pessoa;
            int achou = 0;
            char dados[40];
            scanf(" %[^\n]%*c", dados);
            for (int i = 0; dados[i]; i++)
            {
                if (dados[i] == ',')
                {
                    achou = 1;
                    sscanf(dados, "%[^,],%d", Pessoa.nome, &Pessoa.id);
                }
            }
            if (!achou)
            {
                char sobrenome[20];
                sscanf(dados, "%s %s %d", Pessoa.nome, sobrenome, &Pessoa.id);
                strcat(Pessoa.nome, " ");
                strcat(Pessoa.nome, sobrenome);
            }

            Pessoas = inserir_pessoa(Pessoa, Pessoas);
        }
        else if (operacao == 'b')
        {
            char dados[25];
            scanf(" %[^\n]%*c", dados);

            int irmao1, irmao2;
            sscanf(dados, "%d %d", &irmao1, &irmao2);
            Irmaos = inserir_irmao(Pessoas, Irmaos, irmao1, irmao2);
        }
        else if (operacao == 'p')
        {
            int idBuscado;
            scanf("%d", &idBuscado);
            imprimir_irmaos(Irmaos, Pessoas, idBuscado);
            break;
        }
    }

    return 0;
}