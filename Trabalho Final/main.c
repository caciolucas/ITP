#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "simulation.h"

/**
 * @file main.
 * @brief Recebe os parâmetros pela linha de comando e executa as funções da simulação
 */

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
    if (argc < 7)
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
        for(unsigned int i=1; i<argc; i+=2) {
            if(strcmp(argv[i], "-i") == 0)
                strcpy(inputFileName, argv[i+1]);
            else if(strcmp(argv[i], "-o") == 0)
                strcpy(outputFileName, argv[i+1]);
            else if(strcmp(argv[i], "-t") == 0)
                hours = atof(argv[i+1]);
        }
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

    for(unsigned int i=1; i<argc; i+=2) {
            if(strcmp(argv[i], "-S_0") == 0)
                inputValues[S0].value = atof(argv[i+1]);
            else if(strcmp(argv[i], "-I_0") == 0)
                inputValues[I0].value = atof(argv[i+1]);
            else if(strcmp(argv[i], "-R_0") == 0)
                inputValues[R0].value = atof(argv[i+1]);
            else if(strcmp(argv[i], "-h") == 0)
                inputValues[h].value = atof(argv[i+1]);
            else if(strcmp(argv[i], "-N_b") == 0)
                inputValues[N_b].value = atof(argv[i+1]);
            else if(strcmp(argv[i], "-T_b") == 0)
                inputValues[T_b].value = atof(argv[i+1]);
            else if(strcmp(argv[i], "-S_b0") == 0)
                inputValues[S_b0].value = atof(argv[i+1]);
            else if(strcmp(argv[i], "-I_b0") == 0)
                inputValues[I_b0].value = atof(argv[i+1]);
            else if(strcmp(argv[i], "-m_k") == 0)
                inputValues[m_k].value = atof(argv[i+1]);
            else if(strcmp(argv[i], "-n_k") == 0)
                inputValues[n_k].value = atof(argv[i+1]);
            else if(strcmp(argv[i], "-T_k") == 0)
                inputValues[T_k].value = atof(argv[i+1]);
            else if(strcmp(argv[i], "-tempo_T_b2") == 0)
                inputValues[tempo_T_b2].value = atof(argv[i+1]);
            else if(strcmp(argv[i], "-T_b2") == 0)
                inputValues[T_b2].value = atof(argv[i+1]);
            else if(strcmp(argv[i], "-tempo_T_k2") == 0)
                inputValues[tempo_T_k2].value = atof(argv[i+1]);
            else if(strcmp(argv[i], "-T_k2") == 0)
                inputValues[T_k2].value = atof(argv[i+1]);
        }

    puts("Parametros lidos");
    createSimulation((int)(hours / inputValues[h].value), output, outputFileName);
    plotSimulation(outputFileName);

    return 0;
}