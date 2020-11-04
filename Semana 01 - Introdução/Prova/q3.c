#include <stdio.h>

int main()
{
    int a, b;
    double res;
    char op, opa, opl;
    printf("Entre com os operandos:\n");
    scanf("%d %d", &a, &b);
    printf("Escolha o tipo de operação('a' ou 'l'):\n");
    scanf(" %c", &op);
    // printf("%c",op);
    switch (op)
    {
    case 'a':
        printf("Escolha a operação Aritmética(d, m, a): \n");
        scanf(" %c", &opa);
        switch (opa)
        {
        case 'd':
            res = a / b;
            printf("%d / %d=%d", a, b, (int)res);
            break;
        case 'm':
            res = a * b;
            printf("%d * %d=%d", a, b, (int)res);
            break;
        case 'a':
            res = a + b;
            printf("%d + %d=%d", a, b, (int)res);
            break;
        default:
            printf("op inválida");
            break;
        }
        break;
    case 'l':
        printf("Escolha a operação Lógica(a, x, o):\n");
        scanf(" %c", &opl);
        switch (opl)
        {
        case 'a':
            res = a & b;
            printf("%d and %d=%d",a,b, (int)res);
            break;

        case 'x':
            res = a ^ b;
            printf("%d xor %d=%d",a,b, (int)res);
            break;

        case 'o':
            res = a | b;
            printf("%d or %d=%d",a,b, (int)res);
            break;

        default:
            printf("op inválida");
            break;
        }
        break;

    default:
        printf("Operação Inválida\n");
        break;
    }
}