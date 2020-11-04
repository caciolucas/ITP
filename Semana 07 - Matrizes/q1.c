#include <stdio.h>

int main()
{
    int matriz[30][30], size;
    scanf("%d",&size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i==j)
            {
                matriz[i][j]=1;
            }
            else{
                matriz[i][j]=0;
            }
            
        }
        
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ",matriz[i][j]);
        }
        puts("");
    }
    

    
    
    
    return 0;
}