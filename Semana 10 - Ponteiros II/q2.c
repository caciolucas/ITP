#include <stdio.h>
#include <string.h>

typedef struct
{
    int dia;
    char mes[3 + 1]; //1 caractere para o '\0'
    int ano;
} Data;

typedef struct
{
    char nome[50];
    char estado_civil;    // s - solteiro, c - casado, d - divorciado
    Data data_nascimento; //registro definido acima

} Pessoa;

typedef struct
{
    Pessoa pessoas[50];
    int quantidade;
} BDPessoa;

Data criaData(int dia, char *mes, int ano)
{
    Data nascimento;
    nascimento.dia = dia;
    nascimento.ano = ano;
    strcpy(nascimento.mes, mes);
    return nascimento;
}

Pessoa criaPessoa(char nome[], char estado_civil, Data data_nascimento)
{
    Pessoa pessoa;
    strcpy(pessoa.nome, nome);
    pessoa.estado_civil = estado_civil;
    pessoa.data_nascimento = data_nascimento;
    return pessoa;
}
void adicionaPessoa(BDPessoa *lista_pessoas, Pessoa pessoa)
{
    int indice = lista_pessoas->quantidade;
    lista_pessoas->pessoas[indice] = pessoa;
    lista_pessoas->quantidade++;
    return;
}
void buscaPessoas(BDPessoa lista_pessoas, char nome[50])
{
    printf("Pesquisa %s:\n", nome);
    for (int i = 0; i < lista_pessoas.quantidade; i++)
    {
        if (strcmp(lista_pessoas.pessoas[i].nome, nome) == 0)
        {
            printf("%s - ", lista_pessoas.pessoas[i].nome);
            printf("%c - ", lista_pessoas.pessoas[i].estado_civil);
            printf("%d/%s/%d\n", lista_pessoas.pessoas[i].data_nascimento.dia,
                   lista_pessoas.pessoas[i].data_nascimento.mes,
                   lista_pessoas.pessoas[i].data_nascimento.ano);
        }
    }
    return;
}
void buscaIdades(BDPessoa lista_pessoas, char nome[50])
{
    puts("idade");
    printf("%s\n", nome);
    for (int i = 0; i < lista_pessoas.quantidade; i++)
    {
        if (strcmp(lista_pessoas.pessoas[i].nome, nome) == 0)
        {
            int idade = 2020 - lista_pessoas.pessoas[i].data_nascimento.ano;
            printf("%s - ", lista_pessoas.pessoas[i].nome);
            printf("%c - ", lista_pessoas.pessoas[i].estado_civil);
            printf("%d/%s/%d - ", lista_pessoas.pessoas[i].data_nascimento.dia,
                   lista_pessoas.pessoas[i].data_nascimento.mes,
                   lista_pessoas.pessoas[i].data_nascimento.ano);
            printf("%d ano(s)\n", idade);
        }
    }
    return;
}
void maisVelho(BDPessoa lista_pessoas)
{
    char mais_velho[50];
    int maior_idade = 0;
    int index=0;
    for (int i = 0; i < lista_pessoas.quantidade; i++)
    {
        int idade = 2020 - lista_pessoas.pessoas[i].data_nascimento.ano;
        if (idade > maior_idade)
        {
            maior_idade = idade;
            strcpy(mais_velho, lista_pessoas.pessoas[i].nome);
            index=i;
        }
    }
    printf("mais velho: ");
    printf("%s - ", lista_pessoas.pessoas[index].nome);
    printf("%c - ", lista_pessoas.pessoas[index].estado_civil);
    printf("%d/%s/%d\n", lista_pessoas.pessoas[index].data_nascimento.dia,
           lista_pessoas.pessoas[index].data_nascimento.mes,
           lista_pessoas.pessoas[index].data_nascimento.ano);
}
void maisNovo(BDPessoa lista_pessoas)
{
    char mais_novo[50];
    int menor_idade = 100000;
    int index=0;
    for (int i = 0; i < lista_pessoas.quantidade; i++)
    {
        int idade = 2020 - lista_pessoas.pessoas[i].data_nascimento.ano;
        if (idade < menor_idade)
        {
            menor_idade= idade;
            strcpy(mais_novo, lista_pessoas.pessoas[i].nome);
            index=i;
        }
    }
    printf("mais novo: ");
    printf("%s - ", lista_pessoas.pessoas[index].nome);
    printf("%c - ", lista_pessoas.pessoas[index].estado_civil);
    printf("%d/%s/%d\n", lista_pessoas.pessoas[index].data_nascimento.dia,
           lista_pessoas.pessoas[index].data_nascimento.mes,
           lista_pessoas.pessoas[index].data_nascimento.ano);
}
int main()
{
    BDPessoa pessoas;
    pessoas.quantidade = 0;
    char opcao[20];
    while (1)
    {
        // puts("Opcao:");
        scanf("%s", &opcao);
        if (strcmp(opcao, "adicionar") == 0)
        {
            char nome[50], estado_civil, mes_nascimento[4];
            int dia_nascimento, ano_nascimento;
            // puts("Nome:");
            scanf(" %[^\n]%*c", nome);
            // puts("Estado:");
            scanf(" %c", &estado_civil);

            // puts("dia:");
            scanf(" %d", &dia_nascimento);
            // puts("mes:");
            scanf(" %[^\n]%*c", mes_nascimento);
            // puts("ano:");
            scanf(" %d", &ano_nascimento);

            Data nascimento = criaData(dia_nascimento, mes_nascimento, ano_nascimento);
            Pessoa pessoa = criaPessoa(nome, estado_civil, nascimento);

            adicionaPessoa(&pessoas, pessoa);
            printf("adicionado %s\n", pessoa.nome);
        }

        else if (strcmp(opcao, "pesquisar") == 0)
        {
            char nome[50];
            // puts("Nome:");
            scanf(" %[^\n]%*c", nome);

            buscaPessoas(pessoas, nome);
        }
        else if (strcmp(opcao, "idade") == 0)
        {
            char nome[50];
            // puts("Nome:");
            scanf(" %[^\n]%*c", nome);

            buscaIdades(pessoas, nome);
        }
        else if (strcmp(opcao, "maisvelho")==0){
            maisVelho(pessoas);
        }
        else if (strcmp(opcao, "maisnovo")==0){
            maisNovo(pessoas);
            break;
        }
    }

    return 0;
}
