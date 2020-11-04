#include <stdio.h>

struct numeroFracionario
{
    int numerador;
    int denominador;
};

struct numeroFracionario add(struct numeroFracionario numero1, struct numeroFracionario numero2)
{
    struct numeroFracionario resultado;
    resultado.denominador = numero1.denominador * numero2.denominador;
    resultado.numerador = (((resultado.denominador / numero1.denominador) * numero1.numerador) +
                           ((resultado.denominador / numero2.denominador) * numero2.numerador));
    return resultado;
};
struct numeroFracionario mult(struct numeroFracionario numero1, struct numeroFracionario numero2){
    struct numeroFracionario resultado;
    resultado.denominador = numero1.denominador * numero2.denominador;
    resultado.numerador = numero1.numerador * numero2.numerador;
    return resultado;
};
struct numeroFracionario div(struct numeroFracionario numero1, struct numeroFracionario numero2){
    struct numeroFracionario resultado;
    resultado.denominador = numero1.denominador * numero2.numerador;
    resultado.numerador = numero1.numerador * numero2.denominador;
    if (resultado.denominador<0)
    {
        resultado.denominador*=-1;
        resultado.numerador*=-1;
    }
    return resultado;
};

int main()
{
    struct numeroFracionario numero1;
    struct numeroFracionario numero2;
    struct numeroFracionario resposta;
    char operacao;
    scanf("%d/%d %d/%d %c", &numero1.numerador,
                            &numero1.denominador,
                            &numero2.numerador,
                            &numero2.denominador,
                            &operacao);

    switch (operacao)
    {
    case 'a':
        resposta = add(numero1,numero2);
        printf("%d/%d",resposta.numerador,resposta.denominador);
        break;
    case 'm':
        resposta = mult(numero1,numero2);
        printf("%d/%d",resposta.numerador,resposta.denominador);
        break;
    case 'd':
        resposta = div(numero1,numero2);
        printf("%d/%d",resposta.numerador,resposta.denominador);
        break;
    }
    return 0;
}