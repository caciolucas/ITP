#include <stdio.h>

void ordenaAscVetor(int* array);
void ordenaDesVetor(int* array);
int main()
{
    int vetor[5], vetorOriginal[5], x;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &x);
        vetor[i] = x;
        vetorOriginal[i] = x;

    }
    ordenaAscVetor(vetor);
    ordenaDesVetor(vetor);
    for (int i = 0; i < 5; i++) {
      printf("%d ", vetorOriginal[i]);
    }
    return 0;
}

void ordenaAscVetor(int*  array)
{
    int tmp, i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = i + 1; j < 5; j++)
        {
            if (array[j] < array[i])
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
    for (int i = 0; i < 5; i++) {
      printf("%d ", array[i]);
    }
    puts("");

}
void ordenaDesVetor(int*  array)
{
    int tmp, i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = i + 1; j < 5; j++)
        {
            if (array[j] > array[i])
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
    for (int i = 0; i < 5; i++) {
      printf("%d ", array[i]);
    }
    puts("");

}