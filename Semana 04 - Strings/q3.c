#include <stdio.h>
#include <ctype.h>
int main()
{
    char caractere;
    while (1)
    {
        scanf("%c", &caractere);

        if (caractere == '@')
        {
            break;
        }
        else if (!isalpha(caractere))
        {
            continue;
        }
        else
        {
            printf("%c ", caractere ^ 32);
        }
    }
    return 0;
}