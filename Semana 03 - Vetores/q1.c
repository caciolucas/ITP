#include <stdio.h>

int main()
{
    float a,b[10], c[10];
    int x;
    scanf("%d",&x);

    if (x>10)
    {
        printf("Muitos elementos!");
        return 0;
    }
    
    
    for (int i = 0; i < x; i++)
    {
        scanf(" %f",&a);
        b[i] = a;
    }
    for (int i = 0; i < x; i++)
    {
        scanf(" %f",&a);
        c[i] = a;
    }
    for (int i = 0; i < x; i++)
    {
        printf("%.2f ",b[i]+c[i]);
    }
    
}