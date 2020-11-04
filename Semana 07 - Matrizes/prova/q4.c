#include <stdio.h>

int main()
{
    int matriz[20][20], size;
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }
    int temUm;
    for (int i = 0; i < size; i++)
    {
        temUm = 0;
        for (int j = 0; j < size; j++)
        {
            if (matriz[i][j]==1)
            {
                if (temUm)
                {
                    puts("0");
                    return 0;
                }
                
                temUm=1;
            }
            if (matriz[i][j]!=1 && matriz[i][j]!=0)
            {
                puts("0");
                return 0;
            }
            
            
        }
    }
    puts("1");
    return 0;
}