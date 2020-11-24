#include <stdio.h>

int tempo(int t){
    if(t==1)
        return 0;
    else
        return tempo(t-1)+2;
}
// S(0), I(0), R(0), h, N, T, S0, I0, m, n, T'
float calcB(float N, float T, float S0, float I0){
    return (N)/(T*S0*I0);
}
int main(int argc, char *argv[])
{
    FILE *entrada = fopen("entrada.txt","r");
    return 0;
}