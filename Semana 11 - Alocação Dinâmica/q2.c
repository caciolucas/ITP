#include <stdio.h>
#include <stdlib.h>
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
void readMatrix(Matrix *m){

    for (int i = 0; i < m->nlin; i++)
    {
        for (int j = 0; j < m->ncol; j++)
        {
            scanf("%d",&m->mat[i][j]);
        }
    }
    
}
void printMatrix(Matrix *m){
    for (int i = 0; i < m->nlin; i++)
    {
        for (int j = 0; j < m->ncol; j++)
        {
            printf("%d ",m->mat[i][j]);
        }
        puts("");
    }
    
}
void destroyMatrix(Matrix **m){
    for (int i = 0; i < (*m)->nlin; i++)
    {
        (*m)->mat[i]=NULL;
    }
    (*m)->mat=NULL;
    (*m)=NULL;
    return;
}

int main()
{
    int lin, col;
    Matrix *mat;

    scanf("%i %i", &lin, &col);
    mat = createMatrix(lin, col);
    readMatrix(mat);
    printMatrix(mat);
    destroyMatrix(&mat);
    if (mat == NULL)
    {
        printf("OK\n");
    }
    return 0;
}