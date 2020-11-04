#include <stdio.h>

int main()
{
    int p;
    char format[20];
    scanf("%d", &p);
    sprintf(format, "Valor de pi %%.%dlf\n", p);
    printf(format, 3.14159265358979323846);
    return 0;
}