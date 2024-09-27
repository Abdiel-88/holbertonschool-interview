#include "sandpiles.h"

#define STABLE 3

/**
 * sandpiles_sum - Sums two sandpiles and stabilizes the result
 * @grid1: First sandpile grid (resulting grid)
 * @grid2: Second sandpile grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;
    int stable = 0;

    /* Add grid1 and grid2 */
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            grid1[i][j] += grid2[i][j];

    /* Topple while the grid is unstable */
    while (!stable)
    {
        stable = 1;

        /* Check if grid1 is stable */
        for (i = 0; i < 3; i++)
            for (j = 0; j < 3; j++)
                if (grid1[i][j] > STABLE)
                {
                    stable = 0;
                    break;
                }

        if (!stable)
        {
            printf("=\n");
            print_grid(grid1);
            topple(grid1);
        }
    }
}

/**
 * topple - Topples the sandpile until stable
 * @grid: The 3x3 grid to topple
 */
void topple(int grid[3][3])
{
    int temp[3][3] = {0};
    int i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (grid[i][j] > STABLE)
            {
                temp[i][j] -= 4;
                if (i > 0) temp[i - 1][j]++;
                if (i < 2) temp[i + 1][j]++;
                if (j > 0) temp[i][j - 1]++;
                if (j < 2) temp[i][j + 1]++;
            }

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            grid[i][j] += temp[i][j];
}

/**
 * print_grid - Prints the 3x3 grid
 * @grid: The 3x3 grid to print
 */
void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j > 0)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}
