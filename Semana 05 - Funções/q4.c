#include <stdio.h>

float calculaMedia(char c, float n1, float n2, float n3);
float mediaAntiga(float n1, float n2, float n3);
float mediaNova(float n1, float n2, float n3);

int main()
{
    float n1, n2, n3;
    char c;

    scanf("%c", &c);
    scanf(" %f %f %f", &n1, &n2, &n3);

    printf("%.2f", calculaMedia(c, n1, n2, n3));
    return 0;
}

inline float calculaMedia(char c, float n1, float n2, float n3)
{
    return (c == 'A') ? mediaAntiga(n1, n2, n3) : mediaNova(n1, n2, n3);
}

float mediaAntiga(float n1, float n2, float n3)
{
    return ((n1 * 4) + (n2 * 5) + (n3 * 6)) / 15;
}
float mediaNova(float n1, float n2, float n3)
{
    return (n1 + n2 + n3) / 3;
}