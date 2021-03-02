#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "menger.h"

void paste(char **matrix, int copy_until,
			int paste_y, int paste_x, char empty);
void print_matrix(char **matrix, int size);
void free_matrix(char **matrix, int rows_to_free);

/**
 * menger - function that draws a 2D Menger Sponge
 *
 * @level: is the level of the Menger Sponge to draw
 *
 * If level is lower than 0, do nothing
 * gcc -Wall -Wextra -Werror -pedantic -o 0-menger 0-menger.c 0-main.c -lm
 */
void menger(int level)
{
	char **matrix;
	int i, current_level, copy_until, size;

	if (level < 0)
		return;

	size = pow(3, level);
	matrix = malloc(size * sizeof(char *));

	if (matrix == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		matrix[i] = malloc((size * sizeof(char)) + 1);

		if (matrix[i] == NULL)
		{
			free_matrix(matrix, i - 1);
			return;
		}

		matrix[i][size - 1] = '\0';
	}

	matrix[0][0] = '#';
	current_level = 0;

	while (current_level < level)
	{
		copy_until = pow(3, current_level);

		paste(matrix, copy_until, 0, copy_until, 'n');
		paste(matrix, copy_until, 0, copy_until * 2, 'n');
		paste(matrix, copy_until, copy_until, 0, 'n');
		paste(matrix, copy_until, copy_until, copy_until, 'y');
		paste(matrix, copy_until, copy_until, copy_until * 2, 'n');
		paste(matrix, copy_until, copy_until * 2, 0, 'n');
		paste(matrix, copy_until, copy_until * 2, copy_until, 'n');
		paste(matrix, copy_until, copy_until * 2, copy_until * 2, 'n');

		current_level++;
	}

	print_matrix(matrix, size);
	free_matrix(matrix, size);
}

/**
 * paste - "copy" and paste the values
 *
 * @matrix: matrix to read and paste values
 * @copy_until: index to stop
 * @paste_y: 'y' index to start the new segment
 * @paste_x: 'x' index to start the new segment
 * @empty: flag to draw or left empty
 */
void paste(char **matrix, int copy_until, int paste_y, int paste_x, char empty)
{
	int y, x;
	int paste_x_backup = paste_x;

	for (y = 0; y < copy_until; y++)
	{
		paste_x = paste_x_backup;

		for (x = 0; x < copy_until; x++)
		{
			if (empty == 'n')
				matrix[paste_y][paste_x] = matrix[y][x];
			else
				matrix[paste_y][paste_x] = ' ';

			paste_x++;
		}
		paste_y++;
	}
}

/**
 * print_matrix - print a 2d array
 *
 * @matrix: matrix to print
 * @size: size of the matrix
 */
void print_matrix(char **matrix, int size)
{
	int y;

	for (y = 0; y < size; y++)
	{
		printf("%s", matrix[y]);
		printf("\n");
	}
}

/**
 * free_matrix - clean a 2d array
 * @matrix: 2d array
 * @rows_to_free: free rows until this number
 */
void free_matrix(char **matrix, int rows_to_free)
{
	int i;

	for (i = 0; i < rows_to_free; i++)
		free(matrix[i]);

	free(matrix);
}
