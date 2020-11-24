#include <stdio.h>

typedef struct
{
    int CPF;
    char nome[16], sobrenome[16], endereco[41], telefone[9];

} Pessoa;

void write(Pessoa pessoa)
{
    FILE *file = fopen("pessoas.csv", "a");
    fprintf(file,"%d,%s,%s,%s,%s\n", pessoa.CPF, pessoa.nome, pessoa.sobrenome, pessoa.endereco, pessoa.telefone);
    fclose(file);
    return;
}
void read(FILE *arquivo,int n)
{
    char linha[101];
    fscanf(arquivo, "%s", linha);

    while (n)
    {
        fscanf(arquivo, "%*c%[^\n]", linha);
        printf("%s\n",linha);
        n--;
    }
    fclose(arquivo);
}
int main()
{
    int n;
    Pessoa pessoa;
    FILE *file;
    file = fopen("pessoas.csv", "w");
    fprintf(file, "CPF,nome,sobrenome,endereco,telefone\n");
    fclose(file);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pessoa.CPF);
        scanf("%*c%[^\n]", pessoa.nome);
        scanf("%*c%[^\n]", pessoa.sobrenome);
        scanf("%*c%[^\n]", pessoa.endereco);
        scanf("%*c%[^\n]", pessoa.telefone);
        write(pessoa);
    }
    file = fopen("pessoas.csv", "r");
    read(file,n);
    return 0;
}