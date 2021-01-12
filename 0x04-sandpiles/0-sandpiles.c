#include "sandpiles.h"

void save_grid_and_check_stability(int*, int[3][3], int[3][3]);
void print_grid(int[3][3]);

/**
 * sandpiles_sum - function that computes the sum of two sandpiles.
 *
 * @grid1: int[3][3]
 * @grid2: int[3][3]
 *
 * Both grid1 and grid2 are individually stable.
 * A sandpile is considered stable when none of its cells
 * contains more than 3 grains.
 * When the function is done, grid1 must be stable.
 * grid1 must be printed before each toppling round, only if it is unstable.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int flag_unstable = 1; /* starts asuming this is unstable */
	int y, x;

	/* sum */
	for (y = 0; y < 3; y++)
		for (x = 0; x < 3; x++)
			grid1[y][x] += grid2[y][x];

	/* toppling round */
	while (flag_unstable == 1)
	{
		save_grid_and_check_stability(&flag_unstable, grid1, grid2);

		if (flag_unstable == 0)
			return;

		printf("=\n");
		print_grid(grid1);

		for (y = 0; y < 3; y++)
		{
			for (x = 0; x < 3; x++)
			{
				if (grid2[y][x] <= 3)
					continue;

				grid1[y][x] -= 4;

				/* top */
				if (y > 0)
					grid1[y - 1][x] += 1;

				/* bot */
				if (y <= 1)
					grid1[y + 1][x] += 1;

				/* right */
				if (x <= 1)
					grid1[y][x + 1] += 1;

				/* left */
				if (x > 0)
					grid1[y][x - 1] += 1;
			}
		}
	}
}

/**
 * save_grid_and_check_stability - save grid1 into grid2 and check if
 * grid1 is stable.
 *
 * @flag: pointer to 'flag_unstable', the flag about stability of grid1.
 * 0 stable, 1 unstable.
 * @grid1: int grid1[3][3]
 * @grid2: int grid1[3][3]
 */
void save_grid_and_check_stability(int *flag, int grid1[3][3], int grid2[3][3])
{
	int y, x;

	*flag = 0;

	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 3; x++)
		{
			grid2[y][x] = grid1[y][x];

			if (grid1[y][x] > 3)
				*flag = 1;
		}
	}
}

/**
 * print_grid - print the grid
 *
 * @grid: int grid[3][3]
 */
void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
