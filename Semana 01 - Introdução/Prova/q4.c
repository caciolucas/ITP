#include <stdio.h>

int main()
{
    float m1, c1, m2, c2, xi, yi;
    int t,t2;

    scanf("%f %f %f %f", &m1, &c1, &m2, &c2);
    // printf("m1: %f\n",m1);
    // printf("m2: %f\n",m2);
    // printf("%f\n",(int)m1+m2);
    t = (m2 - m1 == 0) ? 0 : 1;
    // printf("%d\n", t);
    if (!t)
    {
        t2 = (c2 - c1 == 0) ? 0 : 1;
        if (!t2){
            printf("Retas colineares!");
        }else{
        printf("Retas paralelas!");
      }
    }
    else
    {
        xi = (c1 - c2) / (m2 - m1);
        yi = m1 * xi + c1;
        printf("Interseção Pi = (%.1f, %.1f)", xi, yi);
        return 0;
    }
}