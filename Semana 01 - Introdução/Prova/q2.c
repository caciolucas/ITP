#include <stdio.h>
#include <math.h>
int main()
{
    ///////////////////////////////////////////////////////
    // TRANSFORMANDO EM CHAR E PRINTANDO CADA CARACTERE
    ///////////////////////////////////////////////////////
    int i, len,num;
    scanf("%d", &num);

    char asString[6];
    sprintf(asString, "%d", num);

    len = strlen(asString);
    for (i = 0; i < len; i++)
        printf("%c\n", asString[i]);

    // int num, i = 0, o, inverted = 0, n;
    // scanf("%d", &num);
    // o = num;

    // while (o > 1)
    // {
    //     i += 1;
    //     o /= 10;
    //     // printf("i: %d\n", i);
    // }
    // // printf("==============================\n");
    // while (i >= 0)
    // {
    //     // printf("i: %d\n", i);
    //     n = (num % 10);
    //     // printf("n: %d\n", n);
    //     double s = pow(10, i);
    //     // printf("s: %f\n", s);
    //     n *= s;
    //     // printf("n*s: %d\n", n);
    //     inverted += n;
    //     // printf("inverted: %d\n", inverted);
    //     num/=10;
    //     // printf("novo num: %d\n",n);
    //     i -= 1;
    // }
    // // printf("%d\n",inverted);
    // while (inverted>1)
    // {
    //     printf("%d\n",inverted%10);
    //     inverted/=10;
    // }
    
}