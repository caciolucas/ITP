#include <stdio.h>
#include <string.h>

typedef struct string_t
{
    char val[100];
} string;

void insereStrEm(string *result, string *srt1, int pos, string *str2)
{
    int i;
    int s1 = strlen(srt1->val);
    int s2 = strlen(str2->val);
    // printf("s1: %d\n",s1);
    // printf("s2: %d\n",s2);
    // Define o tamanho da string resultado baseado no tamanho das outras 2
    result->val[s2 + s1 + 1] = 0;
    // Adiciona a primeira parte de str2 à string resultado
    for (i = 0; i < pos; i++)
        result->val[i] = str2->val
                             [i];
    // printf("\"%s\"\n", result->val);
    // Adiciona a str1 à string resultado
    for (i = 0; i < s1; i++)
        result->val[pos + i] = srt1->val[i];
    // printf("\"%s\"\n", result->val);
    // Adiciona o resto de str2 à string resultado 
    for (i = pos; i < s2; i++)
        result->val[i + s1] = str2->val[i];

    for (int i = 0; i < s1+s2; i++)
    {
        printf("%c",result->val[i]);
    }
    
    // printf("%s\n", result->val);
}

int main()
{
    string string1, string2, resultado;
    int index;
    // puts("String 2:");
    scanf("%[^\n]%*c", string2.val);
    // puts("String 1:");
    scanf("%[^\n]%*c", string1.val);
    // puts("Indice:");
    scanf("%d", &index);
    insereStrEm(&resultado, &string1, index, &string2);
    return 0;
}