#include <stdio.h>

int main()
{
    int tabuleiro[15][15];
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            scanf("%d", &tabuleiro[i][j]);
        }
    }
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if(tabuleiro[i][j]==1){
                for (int x = 0; i < 5; i++)
                {
                    if (tabuleiro[i])
                    {
                        /* code */
                    }
                    
                }
                
            }
        }
    }
    
    return 0;
}