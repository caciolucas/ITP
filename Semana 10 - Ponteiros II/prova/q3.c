#include <stdio.h>
#include <string.h>

typedef struct
{
    char numero[52];
    int positivo;
} big_int;

int convert(char *str, big_int *num)
{
    if (strlen(str) > 51)
    {
        return 0;
    }

    strcpy(num->numero, str);
    num->positivo = 1 ? str[0] != '-' : 0;

    return 1;
}

void strrev(char string[], char reversed[])
{
    int begin, end, count = 0;

    count = strlen(string);

    end = count - 1;

    for (begin = 0; begin < count; begin++)
    {
        reversed[begin] = string[end];
        end--;
    }

    reversed[begin] = '\0';
}
int add(char str1[], char str2[], char res[])
{
    char resrev[100];
    char temp[50];
    if (strlen(str1) > strlen(str2))
    {
        strcpy(temp, str1);
        strcpy(str1, str2);
        strcpy(str2, temp);
    }

    int n1 = strlen(str1), n2 = strlen(str2);

    char str1rev[50], str2rev[50];
    strrev(str1, str1rev);
    strrev(str2, str2rev);

    int dezena = 0, unidade;
    for (int i = 0; i < n1; i++)
    {
        int sum = ((str1rev[i] - '0') + (str2rev[i] - '0') + dezena);
        unidade = sum % 10 + '0';
        res[i] = unidade;

        dezena = sum / 10;
    }
    for (int i = n1; i < n2; i++)
    {
        int sum = ((str2rev[i] - '0') + dezena);
        unidade = sum % 10 + '0';
        res[i] = unidade;

        dezena = sum / 10;
    }

    if (dezena)
        res[strlen(res)] = (dezena + '0');

    strrev(res, resrev);

    strcpy(temp, resrev);
    strcpy(resrev, res);
    strcpy(res, temp);

    if (strlen(res) > 50)
        return 0;
    return 1;
}

int main()
{
    char num_a[100], num_b[100], res[100], operacao[4];
    big_int bigA, bigB, result;

    scanf("%s", num_a);
    scanf(" %s", num_b);
    scanf("%s",operacao);
    if (!convert(num_a, &bigA))
    {
        printf("impossível converter %s\n", num_a);
        return 1;
    }
    if (!convert(num_b, &bigB))
    {
        printf("impossível converter %s\n", num_b);
        return 1;
    }
    if (strcmp(operacao, "add")==0)
    {
        if (!add(bigA.numero, bigB.numero, res))
        {
          printf("impossivel converter");
        }
        else
        {
          printf("%s", res);
        }
    }
    else if (strcmp(operacao, "mul")==0)
    {
      if((strcmp("0",bigA.numero)&&strcmp("0",bigB.numero))&&strlen(bigA.numero)+strlen(bigB.numero)>=52){
        printf("impossível calcular %s * %s\n",bigA.numero,bigB.numero);
      }
    }
    return 0;
}