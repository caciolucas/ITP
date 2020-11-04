#include <stdio.h>

int main(){
    int a;
    int b;

    scanf("%d %d", &a, &b);
    if (a%2!=0)
    {
       printf("Não posso somar, pois %d não é par\n",a);
    }
    if (b%2!=0)
    {
       printf("Não posso somar, pois %d não é par\n",b);
    }
    if (a%2==0 && b%2==0){
        int c = a + b;
        printf("%d",c);
    }
    
    
    
}