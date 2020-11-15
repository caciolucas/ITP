#include <stdio.h>
#include <string.h>
int main()
{
    char comando[11];
    int res;
    while (1)
    {
        scanf("%[^\n]%*c", comando);

        char operacao[4];
        int n1, n2;
        sscanf(comando, "%s %d %d", operacao, &n1, &n2);
        if (!strcmp(comando,"add"))
        {
            res=n1+n2;
            continue;
        }
    }
}