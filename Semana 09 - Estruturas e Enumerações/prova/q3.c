#include <stdio.h>
#include <math.h>
#include <string.h>

struct pontoFixo
{
    int inteiro;
    int escala;
};

struct pontoFixo convert(struct pontoFixo numero, int novaEscala)
{
    struct pontoFixo novoNumero;
    novoNumero.escala = novaEscala;
    double fator = pow(10, numero.escala * -1) / pow(10, novaEscala * -1);
    novoNumero.inteiro = numero.inteiro*fator;
    return novoNumero;
}

struct pontoFixo add(struct pontoFixo numero1, struct pontoFixo numero2, int escalaDesejada)
{
    struct pontoFixo novoNumero;
    if (numero2.escala > numero1.escala)
    {
        numero1 = convert(numero1, numero2.escala);
    }
    else if (numero1.escala > numero2.escala)
    {
        numero2 = convert(numero2, numero1.escala);
    }
    novoNumero.escala = numero1.escala;
    novoNumero.inteiro = numero1.inteiro + numero2.inteiro;
    novoNumero=convert(novoNumero,escalaDesejada);
    return novoNumero;
}

void to_string(struct pontoFixo numero, char resultado[])
{
    sprintf(resultado, "fixo(%d,%d)", numero.inteiro, numero.escala);
    return;
}

int main()
{
    int escalaDesejada;
    struct pontoFixo n1, n2, n3;
    scanf("%d %d", &n1.inteiro, &n1.escala);
    scanf("%d %d", &n2.inteiro, &n2.escala);
    scanf("%d", &escalaDesejada);

    char s1[20], s2[20], s3[20];
    to_string(n1, s1);
    to_string(n2, s2);

    n3 = add(n1, n2, escalaDesejada);
    to_string(n3, s3);

    printf("%s + %s = %s", s1, s2, s3);
    return 0;
}