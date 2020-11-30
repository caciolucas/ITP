/**
 * @file fileandplot.h
 * @brief Definição das funções relacionadas a manipulação dos arquivos de saída e entrada
 * @details Prototipa a função que lê o arquivo de parâmetros, a que escreve no
 * arquivo csv de saída e a que chama pelo terminal o script ploy.py.
 */

#ifndef FILEANDPLOT_H
#define FILEANDPLOT_H
#include <stdio.h>
#include <stdlib.h>

#include "types.h"

/**
 * @brief Lê o arquivo txt e armazena na variavel do inputValues
 * @details Lê o arquivo de texto com os parâmetros e armazena o nome e valor
 * de cada parâmetro no array global \ref inputValues .
 * @param input Arquivo de entrada com os parâmetros predefinidos
 */
void readTxt(FILE *input);
/**
 * @brief Escreve os 3 cenarios calculados no arquivo .csv de saida
 * @param cenarios Array com os 3 cenários cenários da simulação
 * @param outputFile Ponteiro pro arquivo csv de saída onde serão escritos os dados
 * @param t Quantidade de iterações usado para percorrer os arrays
 */
void writeCenarios(double ***cenarios, FILE *outputFile, int t);

/**
 * @brief Chama o script plot.py passando o nome do arquivo csv de saida como parâmetro 
 * @details Usa a função system() para chamar pelo terminal o script plot.py passando 
 * o nome do arquivo csv de saída como argumento na chamada.
 * @param file Nome do arquivo csv de saida pra ser passado pro comando que executa o script
 * que irá traçar os gráficos, o plot.py 
 */
void plotSimulation(char file[]);

#endif