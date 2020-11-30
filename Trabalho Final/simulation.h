/**
 * @file simulation.h
 * @brief Define  as funções relacionadas aos vetores da simulação
 * @details Prototipa as funções que fazem a simulação acontecer, alocam a 
 * memória dos vetores e usam as funções calcS, calcI e calcR para
 * popular os vetores S, I e R da simulação.
 */

#ifndef SIMULATION_H
#define SIMULATION_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calc.h"
#include "fileandplot.h"

/**
 * @brief Faz a simulação acontecer usando as demais funções
 * @details Aloca espaço pros 3 cenários usando \ref allocCenario
 * calcula as taxas b,k e b2,k2 usando \ref calcB e \ref calcK com 
 * os parâmetros recebidos no arquivo de entrada. Simula cada um 
 * dos cenários com a \ref simulateCenario e então, escreve cada um
 * dos cenários no arquivo de saida csv com \ref writeCenarios.
 * 
 * @param t Quantidade de iterações que a simulação terá 
 * @param output Ponteiro pro arquivo csv onde serão escritos os dados simulados
 * @param outputFileName Nome do arquivo csv de saída usado para print no terminal
 */
void createSimulation(int t, FILE *output, char outputFileName[]);
/**
 * @brief Popula os 4 vetores S, I, R e D de um cenário
 * @details Percorre os 4 vetores e cada iteração vai os preenchendo
 * usando  as funções \ref calcS, \ref calcI e \ref calcR .
 * 
 * @param cenario Vetor com os 4 vetores S, I, R e D a serem populados 
 * @param t Quantidade total de iterações da simulação
 * @param cenarioN Número do cenário (0,1 ou 2)
 * @param b Taxa b (taxa de contágio) usada em todos os cenários
 * @param b2 Taxa b (taxa de contágio) usada somente no cenário 1
 * @param k Taxa k (taxa de recuperação) usada em todos os cenários
 * @param k2 Taxa k (taxa de recuperação) usada somente no cenário 2
 */
void simulateCenario(double *cenario[], int t, int cenarioN, double b, double b2, double k, double k2);

/**
 * @brief Aloca espaço na memória pra os 4 vetores S, I, R e D do respectivo cenário
 * @details Aloca espaço pros 4 vetores do cenário usando o parametro t e a função malloc
 * @param cenario Vetor com os 4 vetores S, I, R e D a serem alocados
 * @param t Quantidade total de iterações (itens) que os vetores terão
 * @param n Número para identificar o cenário
 */
void allocCenario(double *cenario[], int t, int n);

#endif