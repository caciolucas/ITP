#include <stdio.h>

int main()
{
    int n, x, y, res;
    scanf("%d", &n);
	
    while (n)
    {
    	res=0;

    	scanf(" %d %d",&x,&y);
    	x+=1;
    	x = (x%2!=0) ? x : x+1;
    	while(x<y){
    		res+=x;
    		x+=2;
		}
		printf("%d \n",res);

        n--;
    }


    return 0;
}
