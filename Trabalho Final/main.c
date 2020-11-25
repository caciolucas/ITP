#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char name[20];
    float value;
} item;

int tempo(int t)
{
    if (t == 1)
        return 0;
    else
        return tempo(t - 1) + 2;
}

float calcB(float N, float T, float S0, float I0)
{
    return (N) / (T * S0 * I0);
}

int main(int argc, char *argv[])
{

    FILE *input = fopen(argv[1], "r");

    char inputPrefix[10][8] = {
        "S(0)=",

    };
    item inputValues[8];
    char linha[11];
    for (int i = 0; i < 8; i++)
    {
        fscanf(input, "%[^\n]%*c", linha);
        int x = 0;
        while (linha[x] <= '0' || linha[x] >= '9')
        {
            x++;
        }
        sscanf(linha,"%[^=]",inputValues[i].name)
        inputValues[i].value=atof(linha[x]);
    }
    
    for(int i=0; i<8;i++){
        printf("%s:%.1f\n",inputValues[i].name,inputValues[i].value)
    }

    printf("%d\n", s0);

    // "S(0)=2"

    // "S(0)=2\n\0"

    // depois checa se foi ou n

    // strtok(linha, "=");
    // s0 = (NULL, "\n");
    // printf("%d\n", s0);

    return 0;
}
