#include <stdio.h>

int main()
{
    int size = 3;
    int array[size];
    int max, min;
    int i;

    // scanf("%d %d %d", &array[0], &array[1], &array[2]);

    for (i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }




    // printf("a: %d\nb: %d\nc: %d\n", array[0], array[1], array[2]);
    max = array[0];
    min = array[0];
    // printf("\n \n min: %d\n max: %d\n", min, max);
    switch (array[0] == array[1] && array[1] == array[2])
    {
    case 1:
        printf(" Os três números são iguais\n ");
        break;
    case 0:
        for (i = 0; i < size; i++)
        {
            // printf("Verificando o array[%d]: %d\n", i, array[i]);
            if (array[i] > max)
            {
                max = array[i];
                // printf("Novo max: %d\n", max);
            }
            if (array[i] < min)
            {
                min = array[i];
                // printf("Novo min: %d\n", min);
            }
        }
        printf(" O menor número e %d e o maior numero é %d ", min, max);
        break;
        break;
    }
}