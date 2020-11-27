#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// #define S0 0          ///< Macro definindo posição do parâmetro no vetor inputValues
// #define I0 1          ///< Macro definindo posição do parâmetro no vetor inputValues
// #define R0 2          ///< Macro definindo posição do parâmetro no vetor inputValues
// #define h 3           ///< Macro definindo posição do parâmetro no vetor inputValues
// #define N_b 4         ///< Macro definindo posição do parâmetro no vetor inputValues
// #define T_b 5         ///< Macro definindo posição do parâmetro no vetor inputValues
// #define S_b0 6        ///< Macro definindo posição do parâmetro no vetor inputValues
// #define I_b0 7        ///< Macro definindo posição do parâmetro no vetor inputValues
// #define m_k 8         ///< Macro definindo posição do parâmetro no vetor inputValues
// #define n_k 9         ///< Macro definindo posição do parâmetro no vetor inputValues
// #define T_k 10        ///< Macro definindo posição do parâmetro no vetor inputValues
// #define tempo_T_b2 11 ///< Macro definindo posição do parâmetro no vetor inputValues
// #define T_b2 12       ///< Macro definindo posição do parâmetro no vetor inputValues
// #define tempo_T_k2 13 ///< Macro definindo posição do parâmetro no vetor inputValues
// #define T_k2 14       ///< Macro definindo posição do parâmetro no vetor inputValues

/// Enum que relaciona o nome do parâmetro à sua posição no array inputValues
enum paramIndex {
S0 /// 0
,I0 /// 1
,R0 /// 2
,h /// 3
,N_b /// 4 
,T_b /// 5
,S_b0 /// 6
,I_b0 /// 7
,m_k /// 8
,n_k /// 9
,T_k /// 10
,tempo_T_b2 /// 11
,T_b2 ///  12
,tempo_T_k2 /// 13
,T_k2 /// 14
};

/// Struct que guarda o nome do parâmetro e o valor respectivo
typedef struct
{
    double value;  ///< Valor do parâmetro
    char name[20]; ///< Nome do parâmetro
} item;

item inputValues[8]; ///< Armazena os valores passados através do arquivo de entrada

/// Recebe os valores necessários para calcular o valor da iteração atual de S
double calcS(
  double SLessOne /// Valor de S na posição anterior no vetor S do cenario
, double hNumber /// Valor de h (intervalo de tempo)
, double bNumber /// Valor de b (facilidade de contágio de um indivíduo)
, double ILessOne /// Valor de I na posição anterior no vetor I do cenario
)
{
    return SLessOne - hNumber * bNumber * SLessOne * ILessOne;
}
/// Recebe os valores necessários para calcular o valor da iteração atual de I
double calcI(
  double ILessOne /// Valor de I na posição anterior no vetor I do cenario
, double hNumber /// Valor dd h (intervalo de tempo)
, double bNumber /// Valor de bfacilidade de contágio de um indivíduo
, double SLessOne /// Valor de S na posição anterior no vetor S do cenario
, double kNumber /// Valor de k (probabilidade que um indivíduo se recupere)
    )
{
    return ILessOne + hNumber * (bNumber * SLessOne * ILessOne - kNumber * ILessOne);
}
/// Recebe os valores necessários para calcular o valor da iteração atual de R
double calcR(
  double RLessOne /// Valor de R na posição anterior no vetor R do cenario
, double hNumber /// Valor dd h (intervalo de tempo)
, double kNumber /// Valor de k (probabilidade que um indivíduo se recupere)
, double ILessOne /// Valor de I na posição anterior no vetor I do cenario
    )
{
    return RLessOne + hNumber * kNumber * ILessOne;
}
/**
 *  Aloca dinâmicamente 12 vetores (4 para cada cenário)\n 
 * Calcula os valores de b e k, e b2 e k2 (usados respectivamente nos cenários 1 e 2)\n 
 * Percorre os vetores alocados e os preenche os valores calculados usando as funções calcS, calcI e calcR\n 
 * Escreve no arquivo de saída os valores usando os vetores alocados
 */
void createSimulation(int t /// Quantidade de iterações
                      ,FILE *output /// Ponteiro para o arquivo csv de saída
                      )
{
    double *cenario0S = malloc(sizeof(double[t]));
    double *cenario0I = malloc(sizeof(double[t]));
    double *cenario0R = malloc(sizeof(double[t]));
    double *cenario0D = malloc(sizeof(double[t]));

    double *cenario1S = malloc(sizeof(double[t]));
    double *cenario1I = malloc(sizeof(double[t]));
    double *cenario1R = malloc(sizeof(double[t]));
    double *cenario1D = malloc(sizeof(double[t]));

    double *cenario2S = malloc(sizeof(double[t]));
    double *cenario2I = malloc(sizeof(double[t]));
    double *cenario2R = malloc(sizeof(double[t]));
    double *cenario2D = malloc(sizeof(double[t]));

    double k = inputValues[m_k].value / (inputValues[n_k].value * inputValues[T_k].value);
    double b = inputValues[N_b].value / (inputValues[T_b].value * inputValues[S_b0].value * inputValues[I_b0].value);

    double b2 = inputValues[N_b].value / (inputValues[T_b2].value * inputValues[S_b0].value * inputValues[I_b0].value);
    double k2 = inputValues[m_k].value / (inputValues[n_k].value * inputValues[T_k2].value);

    cenario0S[0] = inputValues[S0].value;
    cenario0I[0] = inputValues[I0].value;
    cenario0R[0] = inputValues[R0].value;

    fprintf(output, "Cenario 0 S(t),Cenario 0 I(t),Cenario 0 R(t),Cenario 0 D(t),Cenario 1 S(t),Cenario 1 I(t),Cenario 1 R(t), Cenario 1 D(t),Cenario 2 S(t),Cenario 2 I(t),Cenario 2 R(t),Cenario 2 D(t),tempo(t)\n");
    for (int i = 1; i < t; i++)
    {
        // CENARIO 0 PADRAO
        // cenario0S[i] = cenario0S[i - 1] - inputValues[h].value * b * cenario0S[i - 1] * cenario0I[i - 1];
        // cenario0I[i] = cenario0I[i - 1] + inputValues[h].value * (b * cenario0S[i - 1] * cenario0I[i - 1] - k * cenario0I[i - 1]);
        // cenario0R[i] = cenario0R[i - 1] + inputValues[h].value * k * cenario0I[i - 1];
        cenario0S[i] = calcS(cenario0S[i - 1], inputValues[h].value, b, cenario0I[i - 1]);
        cenario0I[i] = calcI(cenario0I[i - 1], inputValues[h].value, b, cenario0S[i - 1], k);
        cenario0R[i] = calcR(cenario0R[i - 1], inputValues[h].value, k, cenario0I[i - 1]);

        // Se chegou no tempo de usar o novo tb_2, os valores nos vetores vão ser calculados usando ele
        if (i >= inputValues[tempo_T_b2].value / inputValues[h].value)
        {
            // CENARIO 1 (CALCULO COM NOVO T_b)
            // cenario1S[i] = cenario1S[i - 1] - inputValues[h].value * b2 * cenario1S[i - 1] * cenario1I[i - 1];
            // cenario1I[i] = cenario1I[i - 1] + inputValues[h].value * (b2 * cenario1S[i - 1] * cenario1I[i - 1] - k * cenario1I[i - 1]);
            // cenario1R[i] = cenario1R[i - 1] + inputValues[h].value * k * cenario1I[i - 1];
            cenario1S[i] = calcS(cenario1S[i - 1], inputValues[h].value, b2, cenario1I[i - 1]);
            cenario1I[i] = calcI(cenario1I[i - 1], inputValues[h].value, b2, cenario1S[i - 1], k);
            cenario1R[i] = calcR(cenario1R[i - 1], inputValues[h].value, k, cenario1I[i - 1]);
        }
        // Se não, vai ser igual ao do cenário padrão
        else
        {
            cenario1S[i] = cenario0S[i];
            cenario1I[i] = cenario0I[i];
            cenario1R[i] = cenario0R[i];
        }
        // Se chegou no tempo de usar o novo tk_2, os valores nos vetores vão ser calculados usando ele
        if (i >= inputValues[tempo_T_k2].value / inputValues[h].value)
        {
            // CENARIO 2 (CALCULO COM NOVO T_k)
            // cenario2S[i] = cenario2S[i - 1] - inputValues[h].value * b * cenario2S[i - 1] * cenario2I[i - 1];
            // cenario2I[i] = cenario2I[i - 1] + inputValues[h].value * (b * cenario2S[i - 1] * cenario2I[i - 1] - k2 * cenario2I[i - 1]);
            // cenario2R[i] = cenario2R[i - 1] + inputValues[h].value * k2 * cenario2I[i - 1];
            cenario2S[i] = calcS(cenario2S[i - 1], inputValues[h].value, b, cenario2I[i - 1]);
            cenario2I[i] = calcI(cenario2I[i - 1], inputValues[h].value, b, cenario2S[i - 1], k2);
            cenario2R[i] = calcR(cenario2R[i - 1], inputValues[h].value, k2, cenario2I[i - 1]);
        }
        // Se não, vai ser igual ao do cenário padrão
        else
        {
            cenario2S[i] = cenario0S[i];
            cenario2I[i] = cenario0I[i];
            cenario2R[i] = cenario0R[i];
        }
    }

    for (int i = 0; i < t; i++)
    {
        cenario0D[i] = cenario0R[i] * 0.02;
        cenario1D[i] = cenario1R[i] * 0.02;
        cenario2D[i] = cenario2R[i] * 0.02;
        fprintf(output, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\n", cenario0S[i], cenario0I[i], cenario0R[i], cenario0D[i], cenario1S[i], cenario1I[i], cenario1R[i], cenario1D[i], cenario2S[i], cenario2I[i], cenario2R[i], cenario2D[i], i * inputValues[h].value);
    }
    fclose(output);
}

/**
 * Chama o script plot.py passando o nome do arquivo csv de saida como parâmetro 
 */
void plotSimulation(char file[]/** Nome do arquivo csv com os dados que serão plotados*/)
{
    char command[51];
    sprintf(command, "python3 plot.py %s\n", file);
    system(command);
}

/**
 * Recebe como parâmetro os nomes dos arquivos de entrada e saída e o tempo t da simulação em horas\n 
 * 
 * Lê os parâmetros passados no arquivo de entrada e os armazena num vetor de `item` 
 */
int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        puts("Lembre-se de passar os nomes dos arquivos de entrada e saída e o tempo de simulação");
        return 1;
    }
    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");

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

    createSimulation((int)(atof(argv[3]) / inputValues[h].value), output);
    plotSimulation(argv[2]);

    return 0;
}