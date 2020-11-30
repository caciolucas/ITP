/**
 * @file fileandplot.c
 * @brief Funções relacionadas a manipulação dos arquivos de saída e entrada
 * @details Prototipa a função que lê o arquivo de parâmetros, a que escreve no
 * arquivo csv de saída e a que chama pelo terminal o script ploy.py.
 */

#include <stdio.h>
#include <stdlib.h>
#include "fileandplot.h"

void readTxt(FILE *input)
{
    char lines[21];
    for (int i = 0; i < 15; i++)
    {
        fscanf(input, "%[^\n]%*c", lines);
        sscanf(lines, "%[^=]", inputValues[i].name);
        int x = 0;
        while (lines[x++] != '=')
            ;

        while (!('0' <= lines[x] && lines[x] <= '9'))
        {
            x++;
        }
        inputValues[i].value = atof(&lines[x]);
    }
}

void writeCenarios(double ***cenarios, FILE *outputFile, int t)
{

        fprintf(outputFile, "Cenario 0 S(t),Cenario 0 I(t),Cenario 0 R(t),Cenario 0 D(t),");
        fprintf(outputFile, "Cenario 1 S(t),Cenario 1 I(t),Cenario 1 R(t),Cenario 1 D(t),");
        fprintf(outputFile, "Cenario 2 S(t),Cenario 2 I(t),Cenario 2 R(t),Cenario 2 D(t),");
        fprintf(outputFile, "tempo(t)\n");
        for (int j = 0; j < t; j++)
        {
                fprintf(outputFile, "%014.10lf,%014.10lf,%014.10lf,%014.10lf,", cenarios[0][S][j],
                        cenarios[0][I][j],
                        cenarios[0][R][j],
                        cenarios[0][D][j]);
                fprintf(outputFile, "%014.10lf,%014.10lf,%014.10lf,%014.10lf,", cenarios[1][S][j],
                        cenarios[1][I][j],
                        cenarios[1][R][j],
                        cenarios[1][D][j]);
                fprintf(outputFile, "%014.10lf,%014.10lf,%014.10lf,%014.10lf,", cenarios[2][S][j],
                        cenarios[2][I][j],
                        cenarios[2][R][j],
                        cenarios[2][D][j]);
                fprintf(outputFile, "%08.4lf\n", j * inputValues[h].value);
        }
}

void plotSimulation(char file[])
{
    char command[51];
    sprintf(command, "python plot.py %s \n", file);
    puts("Plotando os graficos =============================");
    puts("Aperte ESC ou feche a janela para encerrar =======");
    system(command);
}