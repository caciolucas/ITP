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