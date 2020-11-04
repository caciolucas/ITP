#include <stdio.h>

void checkTripla(int a, int b, int c);

int main()
{
    int x, y, z;
    scanf("%d %d %d",&x,&y,&z);
    checkTripla(x,y,z);
    return 0;
}
void checkTripla(int a, int b, int c){

    int i,f=0;
    if ((a*a==b*b+c*c)||(b*b==a*a+c*c)||(c*c==a*a+b*b))
    {

        for (i = 2; i < a/2; i++)
        {

            if ((a%i==0)&&(b%i==0)&&(c%i==0))
            {

                printf("tripla pitagorica\n");
                f=1;
                break;
            }
            
        }
        if(!f){
        printf("tripla pitagorica primitiva\n");
        }
    }
    else{
        puts("tripla");
    }
    
}


