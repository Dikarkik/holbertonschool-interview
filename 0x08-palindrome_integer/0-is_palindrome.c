#include <stdio.h>
#include <stdlib.h>
#include "palindrome.h"

void get_numbers(unsigned long n, int *numbers, int *index);


/**
 * is_palindrome - checks whether or not a given
 * unsigned integer is a palindrome.
 *
 * @n: is the number to be checked.
 *
 * Return: 1 if n is a palindrome, and 0 otherwise.
 *
 * gcc -Wall -Wextra -Werror -pedantic -g3 -o
 * palindrome 0-main.c 0-is_palindrome.c
 */
int is_palindrome(unsigned long n)
{
	int numbers[19] = {0, 0, 0, 0, 0,
					   0, 0, 0, 0, 0,
					   0, 0, 0, 0, 0,
					   0, 0, 0, 0};
	int index = 0;
	int left, right;

	get_numbers(n, numbers, &index);

	left = 0;
	right = index - 1;

	while (left < right)
	{
		if (numbers[left] != numbers[right])
			return (EXIT_FAILURE);

		left++;
		right--;
	}

	return (EXIT_SUCCESS);
}

/**
 * get_numbers - function to save every number of a
 * unsigned long to a int array.
 *
 * @n: number to get units
 * @numbers: array of integers
 * @index: index to save numbers into the array
 *
 * Return: void
 */
void get_numbers(unsigned long n, int *numbers, int *index)
{
	if (n >= 10)
		get_numbers(n / 10, numbers, index);

	/* save number in 'numbers' */
	numbers[*index] = n % 10;
	*index = *index + 1;
}
