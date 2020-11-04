#include <stdio.h>

#include <stdlib.h>

void main(void)

{

    int i, j, k, l, c;

    float m[10][10];

    float m1[10][10];

    float maux[10][10];

    printf("digite a quntidade de linhas das matrizes \n");

    scanf("%i", &l);

    printf("\n\n");

    printf("Digite a quantidade de colunas das matrizes\n");

    scanf("%i", &c);

    printf("\n\n");

    printf("Digite os elementos da matriz 1");

    printf("\n\n");

    for (i = 0; i < l; i++)

    {

        for (j = 0; j < c; j++)

        {

            printf("elemento %i%i -->", i, j);

            scanf("%f", &m[j]);
        }
    }

    printf("\n\n");

    printf("Digite os elementos da matriz 2");

    printf("\n\n");

    for (i = 0; i < l; i++)

    {

        for (j = 0; j < c; j++)

        {

            printf("elemento %i%i -->", i, j);

            scanf("%f", &m1[j]);

            maux[j] = 0;
        }
    }

    for (i = 0; i < l; i++)

    {

        for (j = 0; j < c; j++)

        {

            for (k = 0; k < l; k++)

            {

                maux[j] = maux[j] + (m[k] * m1[k][j]);
            }
        }
    }

    printf("\n\n");

    printf("As matrizes multiplicadas geram a matriz abaixo");

    printf("\n\n");

    for (i = 0; i < l; i++)

    {

        printf("\n");

        for (j = 0; j < c; j++)

        {

            printf("% 6.2f", maux[j]);
        }
    }

    printf("\n\n");
}

// #include <stdio.h>
// int main(int argc, char *argv[])
// { int linha;
//   int coluna;
//   int i;
//   int somaprod;

//   int mat1[2][3]={{2,5,9},{3,6,8}};
//   int mat2[3][2]={{2,7},{4,3},{5,2}};
//   int mat3[2][2];
//   int M1L=2, M1C=3, M2L=3, M2C=2;
//   for(linha=0; linha<M1L; linha++)
//     for(coluna=0; coluna<M2C; coluna++){
//       somaprod=0;
//       for(i=0; i<M1L; i++) somaprod+=mat1[linha][i]*mat2[i][coluna];
//       mat3[linha][coluna]=somaprod;
//     }
//   //
//   //imprime mat3
//   //
//   for(linha=0; linha<M1L; linha++){
//     for(coluna=0; coluna<M2C; coluna++)
//       printf("%d ", mat3[linha][coluna]);
//     printf("\n");
//   }
//   return 0;
// }