#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Outra forma de fazer
// char semana[7][8] = {"Domingo","Segunda","Terça","Quarta","Quinta","Sexta","Sábado"};
int diadasemana(char entrada[], char **saida, int *bissexto)
{
    // Checa se é válida
    if (
        (entrada[2] != '/' || entrada[5] != '/') ||
        !isdigit(entrada[0]) ||
        !isdigit(entrada[1]) ||
        !isdigit(entrada[3]) ||
        !isdigit(entrada[4]) ||
        !isdigit(entrada[6]) ||
        !isdigit(entrada[7]) ||
        !isdigit(entrada[8]) ||
        !isdigit(entrada[9]) ||
        entrada[10] != '\0')
    {
        return -2;
    }

    // Recupera os valores
    int dia = (entrada[0] - '0') * 10 + entrada[1] - '0';
    int mes = (entrada[3] - '0') * 10 + entrada[4] - '0';
    int ano = (entrada[6] - '0') * 1000 + (entrada[7] - '0') * 100 + (entrada[8] - '0') * 10 + entrada[9] - '0';

    // Verifica se é bissexto
    if (ano % 400 == 0)
        *bissexto = 1;
    else if (ano % 100 == 0)
        *bissexto = 0;
    else if (ano % 4 == 0)
        *bissexto = 1;
    else
        *bissexto = 0;

    if (
        (mes == 1  && dia > 31) ||                 //Janeiro
        (!*bissexto && (mes == 2 && dia > 28)) ||  //Fevereiro (bissexto)
        (*bissexto && (mes == 2 && dia > 29)) ||   //Fevereiro (bissexto)
        (mes == 3  && dia > 31) ||                 //Março
        (mes == 4  && dia > 30) ||                 //Abril
        (mes == 5  && dia > 31) ||                 //Maio
        (mes == 6  && dia > 30) ||                 //Junho
        (mes == 7  && dia > 31) ||                 //Julho
        (mes == 8  && dia > 31) ||                 //Agosto
        (mes == 9  && dia > 30) ||                 //Setembro
        (mes == 10 && dia > 31) ||                 //Outubro
        (mes == 11 && dia > 30) ||                 //Novembro
        (mes == 12 && dia > 31)                    //Dezembro

    )
    {
        return -1;
    }

    // Calcula o dia da semana
    int diaDaSemana = (23 * mes / 9 + dia + 4 + (mes < 3 ? ano - 1 : ano - 2) + ano / 4 - ano / 100 + ano / 400) % 7;
    switch (diaDaSemana)
    {
    case 0:
        *saida = "Domingo";
        break;
    case 1:
        *saida = "Segunda";
        break;
    case 2:
        *saida = "Terça";
        break;
    case 3:
        *saida = "Quarta";
        break;
    case 4:
        *saida = "Quinta";
        break;
    case 5:
        *saida = "Sexta";
        break;
    case 6:
        *saida = "Sábado";
        break;
    }
    // Outra forma de fazer
    // *saida = semana[diaDaSemana];

    return 1;
}
// 11/09/2001

int main()
{
    int status = 0, bissexto = 0;
    char entrada[11] = {0}, *saida = NULL;
    fgets(entrada, 11, stdin);

    status = diadasemana(entrada, &saida, &bissexto);
    if (status > 0)
        printf("%s.%s\n", saida,
               bissexto ? " Ano bissexto." : "");
    else
    {
        if (status == -1)
            printf("Data inexistente.\n");
        else
            printf("Entrada invalida.\n");
        return 1;
    }

    return 0;
}