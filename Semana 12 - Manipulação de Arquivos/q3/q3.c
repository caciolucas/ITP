#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char matricula[9];
    char nome[31];
    float nota1;
    float nota2;
    float nota3;
    float media;
} Aluno;

void writeAluno(Aluno aluno, char nome[]) {
    FILE *arquivo = fopen(nome, "a");
    char status[26];
    bool menorq3;
    if (aluno.nota1 <= 3 || aluno.nota2 <= 3 || aluno.nota3 <= 3) {
        menorq3 = true;
    }

    if (aluno.media >= 5 && !menorq3)
        strcpy(status, "aprovado");
    else if (aluno.media >= 5 && menorq3)
        strcpy(status, "reprovado por nota");
    else if (aluno.media < 5)
        strcpy(status, "reprovado por média");

    fprintf(arquivo, "%s,%s,%.1f,%s\n", aluno.matricula, aluno.nome, aluno.media, status);
    fclose(arquivo);
}
void calcMedia(Aluno *aluno) {
    aluno->media = ((aluno->nota1) + (aluno->nota2) + (aluno->nota3)) / 3;
    return;
}

int main(int argc, char *argv[]) {
    FILE *origem, *destino;
    origem = fopen(argv[2], "r");
    destino = fopen(argv[4], "w");
    fprintf(destino, "matrícula,nome,média,status\n");
    fclose(destino);
    char linha[101];
    fscanf(origem, "%s", linha);
    int i=1;

    Aluno aluno;

    while (true) {
        i = fscanf(origem, "%*c%[^\n]", linha);
        if (i==EOF)
            break;

        strcpy(aluno.matricula, strtok(linha, ","));
        strcpy(aluno.nome, strtok(NULL, ","));
        
        aluno.nota1 = atof(strtok(NULL, ","));
        aluno.nota2 = atof(strtok(NULL, ","));
        aluno.nota3 = atof(strtok(NULL, "\n"));

        calcMedia(&aluno);
        writeAluno(aluno, argv[4]);
                
                
    }
    return 0;
}