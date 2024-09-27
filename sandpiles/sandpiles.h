#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void print_grid(int grid[3][3]);  // This is globally declared
void topple(int grid[3][3]);  /* Add this line */

#endif /* SANDPILES_H */
