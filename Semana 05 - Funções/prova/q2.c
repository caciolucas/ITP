#include <stdio.h>

char *ceaserCypher(char *string, int key);

int main()
{
    int n, k;
    char msg[100];
    scanf("%d", &n);
    while (n)
    {
        scanf("%s",msg);
        scanf(" %d", &k);
        printf("%s",ceaserCypher(msg, k));
        n--;
    }
    return 0;
}

char *ceaserCypher(char *string, int key)
{
    for (int i = 0; string[i] != 0; i++)
    {
        string[i] = (string[i] - key < 65) ? string[i] + 26 - key : string[i] - key;
    }
    return string;
}