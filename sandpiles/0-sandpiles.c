#include "sandpiles.h"

/**
 * sandpiles_sum - Computes the sum of two sandpiles and stabilizes them
 * @grid1: First 3x3 grid (result will be stored here)
 * @grid2: Second 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;
    int stable = 0;

    /* Add grid2 to grid1 */
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            grid1[i][j] += grid2[i][j];

    /* Stabilize the sandpile */
    while (!stable)
    {
        stable = 1;

        /* Check if grid1 is unstable */
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (grid1[i][j] > 3)
                {
                    stable = 0;
                    break;
                }
            }
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
 * topple - Topples the sandpile when unstable
 * @grid: The 3x3 grid to topple
 */
void topple(int grid[3][3])
{
    int temp[3][3] = {0};
    int i, j;

    /* Topple unstable cells */
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
            {
                temp[i][j] -= 4;
                if (i > 0) temp[i - 1][j]++;
                if (i < 2) temp[i + 1][j]++;
                if (j > 0) temp[i][j - 1]++;
                if (j < 2) temp[i][j + 1]++;
            }
        }
    }

    /* Apply the topple to grid */
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            grid[i][j] += temp[i][j];
}
