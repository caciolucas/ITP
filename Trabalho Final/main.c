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

typedef struct
{
    double value;
    char name[20];
} item;

item inputValues[8];
double S[1024];
double I[1024];
double R[1024];

void createSimulation(int t,FILE *output)
{

    double k = inputValues[m_k].value / (inputValues[n_k].value * inputValues[T_k].value);

    double b = inputValues[N_b].value / (inputValues[T_b].value * inputValues[S_b0].value * inputValues[I_b0].value);

    S[0] = inputValues[S0].value;
    I[0] = inputValues[I0].value;
    R[0] = inputValues[R0].value;

    fprintf(output, "S(t),I(t),R(t),tempo(t)\n");
    for (int i = 1; i < t; i++)
    {
        S[i] = S[i - 1] - inputValues[h].value * b * S[i - 1] * I[i - 1];
        I[i] = I[i - 1] + inputValues[h].value * (b * S[i - 1] * I[i - 1] - k * I[i - 1]);
        R[i] = R[i - 1] + inputValues[h].value * k * I[i - 1];
    }

    for (int i = 0; i < t; i++)
    {
        //printf("%lf,%lf,%lf,%lf\n",S[i],I[i],R[i],i*inputValues[h].value);
        fprintf(output, "%lf,%lf,%lf,%lf\n", S[i], I[i], R[i], i * inputValues[h].value);
    }
    fclose(output);
}
void plotSimulation(char file[]){
    char command[51];
    sprintf(command,"python plot.py %s\n",file);
    printf("%s\n",command);
    system("pause");
    system(command);
}
int main(int argc, char *argv[])
{

    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");
    // FILE *input = fopen("entrada.txt", "r");

    char linha[11];
    for (int i = 0; i < 11; i++)
    {
        fscanf(input, "%[^\n]%*c", linha);
        sscanf(linha, "%[^=]", inputValues[i].name);
        int x = 0;
        while (linha[x++] != '=')
            ;

        while (!('0' <= linha[x] && linha[x] <= '9'))
        {
            x++;
        }
        inputValues[i].value = atof(&linha[x]);
    }

    createSimulation(atoi(argv[3])/inputValues[h].value,output);
    plotSimulation(argv[2]);

    return 0;
}
