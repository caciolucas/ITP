#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int *substring(char substring[], char string[])
{
    int *r = NULL;
    char string2[51], substring2[51];
    strcpy(string2,string);
    strcpy(substring2,substring);
    // CONVERTE TUDO PRA LOWER
    for (int i = 0; i < strlen(string); i++)
    {
        string2[i] = tolower(string[i]);
    }
    
    for (int i = 0; i < strlen(substring); i++)
    {
        substring2[i] = tolower(substring[i]);
    }

    for (int i = 0; i <= strlen(string) - strlen(substring); i++)
    {
        bool achou = false;
        for (int j = 0; j < strlen(substring); j++)
        {
            if (string2[i + j] != substring2[j])
            {
                achou = true;
                break;
            }
        }
        if (!achou)
        {
            r = &i;
        }
    }

    return r;
}

int main()
{
    char A[51], B[51];
    gets(A);
    gets(B);
    int *r = substring(A, B);
    if (r == NULL)
    {
        printf("%s não é substring de %s", A, B);
    }
    else
    {
        for (int i = *r-1; B[i] ; i++)
        {
            printf("%c", B[i]);
        }
    }
    return 0;
}