#include <stdio.h>
#include <stdbool.h>

int main()
{
    int A, L, grid[20][20], shot_i = 1, shot_j = 1;
    scanf("%d %d", &A, &L);
    for (int i = 0; i < A; i++)
    {
        for (int j = 0; j < L; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }

    while (true)
    {
        scanf("%d %d", &shot_i, &shot_j);
        shot_j--;
        shot_i--;

        if (shot_j < 0 || shot_j >= L || shot_i < 0 || shot_i >= A)
        {
            return 0;
        }
        if (grid[shot_i][shot_j] == 0)
        {
            puts("1");
        }
        else if (grid[shot_i][shot_j] == -1)
        {
            puts("4");
        }
        else if (
            grid[shot_i + 1][shot_j] != 1 &&
            grid[shot_i - 1][shot_j] != 1 &&
            grid[shot_i][shot_j + 1] != 1 &&
            grid[shot_i][shot_j - 1] != 1)
        {
            puts("3");
        }
        else if (
            grid[shot_i + 1][shot_j] == 1 ||
            grid[shot_i - 1][shot_j] == 1 ||
            grid[shot_i][shot_j + 1] == 1 ||
            grid[shot_i][shot_j - 1] == 1)
        {
            puts("2");
        }
        grid[shot_i][shot_j] = -1;
        shot_j++;
        shot_i++;
    }

    return 0;
}