#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    int matricula;
    char nome[21];
} Aluno;

typedef struct
{
    Aluno lista_alunos[100];
    int total_alunos;
    int n_alunos;
} BDAluno;

void criaAluno(char nome[], int matricula, Aluno *aluno){
    aluno->matricula=matricula;
    strcpy(aluno->nome,nome);
    return;
}

void insereAluno(BDAluno *alunos, Aluno *aluno){
    int index=alunos->n_alunos;
    alunos->lista_alunos[index].matricula=aluno->matricula;
    strcpy(alunos->lista_alunos[index].nome,aluno->nome);
    
    alunos->n_alunos++;
    // printf("novo numero de alunos %d\n",alunos->n_alunos);
    return;
}

void imprimeAlunos(BDAluno *alunos){
    // printf("Alunos %d\n",alunos->n_alunos);
    puts("Alunos");
    for (int i = 0; i < alunos->n_alunos; i++)
    {
        printf("matricula: %03d\n",alunos->lista_alunos[i].matricula);
        printf("nome: %s\n",alunos->lista_alunos[i].nome);
    }
    return;
}

void statusBD(BDAluno *alunos){
    float percent=((float)alunos->n_alunos/(float)alunos->total_alunos)*100.0;
    printf("memoria ocupada: %d/%d ou %.0f%%\n",alunos->n_alunos,alunos->total_alunos,percent);
    return;
}

void ordenaBD(BDAluno *alunos){
    Aluno swap;
    for (int i = 0; i <= alunos->n_alunos; i++)
    {
        for (int j = i+1; i <= alunos->n_alunos; i++)
        {
            if(strcmp(alunos->lista_alunos[i].nome,alunos->lista_alunos[j].nome)>0){
                swap.matricula = alunos->lista_alunos[i].matricula;
                strcpy(swap.nome,alunos->lista_alunos[i].nome);

                alunos->lista_alunos[i].matricula = alunos->lista_alunos[j].matricula;
                strcpy(alunos->lista_alunos[i].nome,alunos->lista_alunos[j].nome);

                alunos->lista_alunos[j].matricula = swap.matricula;
                strcpy(alunos->lista_alunos[j].nome,swap.nome);
            }
        }
    }
}

int main()
{
    BDAluno alunos;
    alunos.n_alunos=0;
    char comando[11];
    scanf("%d", &alunos.total_alunos);
    while (true)
    {
        // puts("comando:");
        scanf(" %s", comando);
        if (strcmp(comando,"sair")==0)
        {
            break;
        }
        else if (strcmp(comando,"inserir")==0)
        {
            int matricula;
            char nome[21];
            scanf("%d",&matricula);
            scanf(" %[^\n]%*c",nome);
            
            Aluno aluno;
            criaAluno(nome,matricula,&aluno);
            insereAluno(&alunos,&aluno);
            printf("inserido %03d\n",matricula);
        }
        else if (strcmp(comando,"imprimir")==0)
        {
            imprimeAlunos(&alunos);
        }
        else if (strcmp(comando,"status")==0)
        {
            statusBD(&alunos);
        }
        else if (strcmp(comando,"ordenar")==0)
        {
            ordenaBD(&alunos);
            puts("ordenacao completa");
        }
        
        
        
    }

    return 0;
}