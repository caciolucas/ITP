#include <stdio.h>

int main()
{
    char a;
    char b;
    scanf("%c %c", &a, &b);

    switch (a == b)
    {
    case 0:
        switch (b > a)
        {
        case 0:
            printf("Caractere %c antecede %c", b, a);
            break;
        case 1:
            printf("Caractere %c antecede %c", a, b);
            break;
        }
        break;
    case 1:
        printf("Caracteres %c e %c iguais", a, b);
        break;
    }
}