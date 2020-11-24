#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct
{
    int nlin, ncol;
    int **mat;
} Matrix;

Matrix *createMatrix(int nlin, int ncol)
{
    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->nlin = nlin;
    matrix->ncol = ncol;
    matrix->mat = calloc(nlin, sizeof(int *));

    for (int i = 0; i < nlin; i++)
    {
        matrix->mat[i] = calloc(ncol, sizeof(int));
    }
    return matrix;
}
void readMatrix(Matrix *m)
{

    for (int i = 0; i < m->nlin; i++)
    {
        for (int j = 0; j < m->ncol; j++)
        {
            scanf("%d", &m->mat[i][j]);
        }
    }
}
void printMatrix(Matrix *m)
{
    for (int i = 0; i < m->nlin; i++)
    {
        for (int j = 0; j < m->ncol; j++)
        {
            printf("%d ", m->mat[i][j]);
        }
        puts("");
    }
}
Matrix *doubleMatrix(Matrix *mat)
{
    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->nlin = ((mat->nlin) * 2) - 1;
    matrix->ncol = ((mat->ncol) * 2) - 1;
    matrix->mat = calloc(matrix->nlin, sizeof(int *));

    for (int i = 0; i < matrix->nlin; i++)
    {
        matrix->mat[i] = calloc(matrix->ncol, sizeof(int));
    }
    for (int i = 0; i < mat->nlin; i++)
    {
        for (int j = 0; j < mat->ncol; j++)
        {
            matrix->mat[2 * i][2 * j] = mat->mat[i][j];
        }
    }
    for (int i = 0; i < matrix->nlin; i++)
    {
        for (int j = 0; j < matrix->ncol; j++)
        {
            if (i % 2 != 0 || j % 2 != 0)
                matrix->mat[i][j] = (-1);
        }
    }

    for (int k = 0; k<2 ; k++)
    {
        for (int i = 0; i < matrix->nlin; i++)
        {
            for (int j = 0; j < matrix->ncol; j++)
            {
                bool cima = (i == 0) ? false : true;
                bool baixo = (i == matrix->nlin - 1) ? false : true;
                bool esquerda = (j == 0) ? false : true;
                bool direita = (j == matrix->ncol - 1) ? false : true;
                if (matrix->mat[i][j] == -1)
                {
                    if (esquerda && direita)
                    {
                        if (matrix->mat[i][j + 1] != -1 && matrix->mat[i][j - 1] != -1)
                        {
                            matrix->mat[i][j] = (matrix->mat[i][j + 1] + matrix->mat[i][j - 1]) / 2;
                        }
                    }
                    if (cima && baixo)
                    {
                        if (matrix->mat[i + 1][j] != -1 && matrix->mat[i - 1][j] != -1)
                        {
                            matrix->mat[i][j] = (matrix->mat[i + 1][j] + matrix->mat[i - 1][j]) / 2;
                        }
                    }
                }
            }
        }
        // printMatrix(matrix);
    }
    return matrix;
}
int main()
{
    int lin, col;
    Matrix *mat, *mat2;

    scanf("%i %i", &lin, &col);
    mat = createMatrix(lin, col);
    readMatrix(mat);
    mat2 = doubleMatrix(mat);
    printMatrix(mat2);
    return 0;
}