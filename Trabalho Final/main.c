#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define S0 0
#define I0 1
#define R0 2
#define h 3
#define N_b 4
#define T_b 5
#define S_b0 6
#define I_b0 7
#define m_k 8
#define n_k 9
#define T_k 10
#define tempo_T_b2 11
#define T_b2 12
#define tempo_T_k2 13
#define T_k2 14

typedef struct
{
    double value;
    char name[20];
} item;

item inputValues[8];

void createSimulation(int t, FILE * output)
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
        cenario0S[i] = cenario0S[i - 1] - inputValues[h].value * b * cenario0S[i - 1] * cenario0I[i - 1];
        cenario0I[i] = cenario0I[i - 1] + inputValues[h].value * (b * cenario0S[i - 1] * cenario0I[i - 1] - k * cenario0I[i - 1]);
        cenario0R[i] = cenario0R[i - 1] + inputValues[h].value * k * cenario0I[i - 1];

        // Se chegou no tempo de usar o novo tb_2, os valores nos vetores vão ser calculados usando ele
        if (i >= inputValues[tempo_T_b2].value / inputValues[h].value)
        {
            // CENARIO 1 (CALCULO COM NOVO T_b)
            cenario1S[i] = cenario1S[i - 1] - inputValues[h].value * b2 * cenario1S[i - 1] * cenario1I[i - 1];
            cenario1I[i] = cenario1I[i - 1] + inputValues[h].value * (b2 * cenario1S[i - 1] * cenario1I[i - 1] - k * cenario1I[i - 1]);
            cenario1R[i] = cenario1R[i - 1] + inputValues[h].value * k * cenario1I[i - 1];
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
            cenario2S[i] = cenario2S[i - 1] - inputValues[h].value * b * cenario2S[i - 1] * cenario2I[i - 1];
            cenario2I[i] = cenario2I[i - 1] + inputValues[h].value * (b * cenario2S[i - 1] * cenario2I[i - 1] - k2 * cenario2I[i - 1]);
            cenario2R[i] = cenario2R[i - 1] + inputValues[h].value * k2 * cenario2I[i - 1];
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
void plotSimulation(char file[])
{
    char command[51];
    sprintf(command, "python plot.py %s\n", file);
    system(command);
}
int main(int argc, char *argv[])
{
    // if (argc < 4)
    // {
    //     puts("Lembre-se de passar os nomes dos arquivos de entrada e saída");
    //     return 1;
    // }
    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");
    // FILE *input = fopen("entrada.txt", "r");

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

    createSimulation((int) (atof(argv[3]) / inputValues[h].value), output);
    // plotSimulation(argv[2]);

    return 0;
}