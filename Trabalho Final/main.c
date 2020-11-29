#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "simulation.h"



void allocCenario(double *cenario[], int t, int n)
{
    char c;
    for (int i = 0; i < 4; i++)
    {
        switch (i)
        {
        case 0:
            c = 'S';
            break;
        case 1:
            c = 'I';
            break;
        case 2:
            c = 'R';
            break;
        case 3:
            c = 'D';
            break;
        }
        cenario[i] = malloc(sizeof(double[t]));
        if (cenario[i] == NULL)
        {
            printf("Erro na alocacao de espaco do cenario %d %c\n", n, c);
        }
        else
        {
            printf("Cenario %d %c alocado corretamente\n", n, c);
        }
    }
}

void simulateCenario(double *cenario[], int t, int cenarioN, double b, double b2, double k, double k2)
{
    if (cenarioN == 0)
    {
        cenario[S][0] = inputValues[S0].value;
        cenario[I][0] = inputValues[I0].value;
        cenario[R][0] = inputValues[R0].value;
        cenario[D][0] = cenario[R][0] * 0.02;
        for (int i = 1; i < t; i++)
        {
            cenario[S][i] = calcS(cenario[S][i - 1], inputValues[h].value, b, cenario[I][i - 1]);
            cenario[I][i] = calcI(cenario[I][i - 1], inputValues[h].value, b, cenario[S][i - 1], k);
            cenario[R][i] = calcR(cenario[R][i - 1], inputValues[h].value, k, cenario[I][i - 1]);
            cenario[D][i] = cenario[R][i] * 0.02;
        }
    }
    if (cenarioN == 1)
    {
        cenario[S][0] = inputValues[S0].value;
        cenario[I][0] = inputValues[I0].value;
        cenario[R][0] = inputValues[R0].value;
        cenario[D][0] = cenario[R][0] * 0.02;
        for (int i = 1; i < t; i++)
        {

            if (i >= inputValues[tempo_T_b2].value / inputValues[h].value)
            {

                cenario[S][i] = calcS(cenario[S][i - 1], inputValues[h].value, b2, cenario[I][i - 1]);
                cenario[I][i] = calcI(cenario[I][i - 1], inputValues[h].value, b2, cenario[S][i - 1], k);
                cenario[R][i] = calcR(cenario[R][i - 1], inputValues[h].value, k, cenario[I][i - 1]);
            }
            else
            {
                cenario[S][i] = calcS(cenario[S][i - 1], inputValues[h].value, b, cenario[I][i - 1]);
                cenario[I][i] = calcI(cenario[I][i - 1], inputValues[h].value, b, cenario[S][i - 1], k);
                cenario[R][i] = calcR(cenario[R][i - 1], inputValues[h].value, k, cenario[I][i - 1]);
            }
            cenario[D][i] = cenario[R][i] * 0.02;
        }
    }
    if (cenarioN == 2)
    {
        cenario[S][0] = inputValues[S0].value;
        cenario[I][0] = inputValues[I0].value;
        cenario[R][0] = inputValues[R0].value;
        cenario[D][0] = cenario[R][0] * 0.02;
        for (int i = 1; i < t; i++)
        {

            if (i >= inputValues[tempo_T_k2].value / inputValues[h].value)
            {

                cenario[S][i] = calcS(cenario[S][i - 1], inputValues[h].value, b, cenario[I][i - 1]);
                cenario[I][i] = calcI(cenario[I][i - 1], inputValues[h].value, b, cenario[S][i - 1], k2);
                cenario[R][i] = calcR(cenario[R][i - 1], inputValues[h].value, k2, cenario[I][i - 1]);
            }
            else
            {
                cenario[S][i] = calcS(cenario[S][i - 1], inputValues[h].value, b, cenario[I][i - 1]);
                cenario[I][i] = calcI(cenario[I][i - 1], inputValues[h].value, b, cenario[S][i - 1], k);
                cenario[R][i] = calcR(cenario[R][i - 1], inputValues[h].value, k, cenario[I][i - 1]);
            }
            cenario[D][i] = cenario[R][i] * 0.02;
        }
    }
}


void createSimulation(int t, FILE *output, char outputFileName[])
{
    double *cenario0[4], *cenario1[4], *cenario2[4];
    puts("Alocando cenario 0 ===============================");
    allocCenario(cenario0, t, 0);
    puts("Alocando cenario 1 ===============================");
    allocCenario(cenario1, t, 1);
    puts("Alocando cenario 2 ===============================");
    allocCenario(cenario2, t, 2);

    puts("Calculando os valores de k, b e k2, b2 ===========");
    double k = calcK(inputValues[m_k].value, inputValues[n_k].value, inputValues[T_k].value);
    double b = calcB(inputValues[N_b].value, inputValues[T_b].value, inputValues[S_b0].value, inputValues[I_b0].value);

    double k2 = calcK(inputValues[m_k].value, inputValues[n_k].value, inputValues[T_k2].value);
    double b2 = calcB(inputValues[N_b].value, inputValues[T_b2].value, inputValues[S_b0].value, inputValues[I_b0].value);

    puts("Simulando cenario 0 ==============================");
    simulateCenario(cenario0, t, 0, b, b2, k, k2);
    puts("Simulando cenario 1 ==============================");
    simulateCenario(cenario1, t, 1, b, b2, k, k2);
    puts("Simulando cenario 2 ==============================");
    simulateCenario(cenario2, t, 2, b, b2, k, k2);

    double **cenarios[3] = {cenario0, cenario1, cenario2};

    printf("Escrevendo os cenarios em %s ", outputFileName);
    for (int i = 0; i < 50 - (27 + strlen(outputFileName)); i++)
    {
        printf("=");
    }
    puts("");
    writeCenarios(cenarios, output, t);
    fclose(output);
    puts("Arquivo salvo e fechado");
}





/**
 * Recebe como parâmetro os nomes dos arquivos de entrada e saída e o tempo t da simulação em horas\n 
 * 
 * Lê os parâmetros passados no arquivo de entrada e os armazena num vetor de `item` 
 */
int main(int argc, char *argv[])
{
    char inputFileName[51];
    char outputFileName[51];
    float hours;
    // Validação da entrada
    if (argc < 4)
    {
        puts("Voce nao passou os nomes dos arquivos de parametros, o de saida e/ou o tempo de simulacão, por favor informe-os agora");
        printf("Arquivo com os parametros: ");
        scanf("%s", inputFileName);
        printf("Arquivo .csv de saida: ");
        scanf("%s", outputFileName);
        printf("Tempo (em horas) da simulacao: ");
        scanf("%f", &hours);
    }
    else
    {
        strcpy(inputFileName, argv[1]);
        strcpy(outputFileName, argv[2]);
        hours = atof(argv[3]);
    }
    FILE *input = fopen(inputFileName, "r"); // Arquivo txt de entrada
    while (input == NULL)
    {
        puts("Arquivo de parametro nao encontrado, informe-o novamente:");
        printf("Arquivo com os parametros:");
        scanf("%s", inputFileName);
        input = fopen(inputFileName, "r");
    }

    FILE *output = fopen(outputFileName, "w"); // Arquivo csv da saida
    readTxt(input);
    puts("Parametros lidos");
    createSimulation((int)(hours / inputValues[h].value), output, outputFileName);
    plotSimulation(outputFileName);

    return 0;
}