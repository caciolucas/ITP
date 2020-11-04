#include <stdio.h>
#include <math.h>

void inverteNumero(int* numero){
    int normal = &numero;
    int reverso = 0;
    int x = 0;
    while (normal>=10)
    {
        reverso+= normal%10*pow(10,x);
        normal/=10;
    }
    numero = reverso;
}


int main()
{
    int n;
    scanf("%d",&n);
    inverteNumero(&n);
    printf("%d",n);
    return 0;
}