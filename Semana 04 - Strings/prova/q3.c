#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void capitalize(char *frase)
{
    int transformar = false;
    for (int i = 0; i < strlen(frase); i++)
    {
        if (frase[i-1]==' ' || (i==0 && frase[i]!=' '))
        {
            transformar = true;
        }else{
            transformar = false;
        }
        
        if (transformar)
        {
            frase[i]=toupper(frase[i]);
        }
        else{
            frase[i]=tolower(frase[i]);
        }
    };
}
int main()
{
    char frase[61], novaFrase[61];
    gets(frase);
    capitalize(frase);
    printf("%s", frase);
    return 0;
}
