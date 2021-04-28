#include "search_algos.h"
#include <stdio.h>

int binary_search(int *array, int value, int left, int right);
void print_subarray(int *array, int left, int right);

/**
 * advanced_binary - searches for a value in a sorted array of integers.
 * You can assume that array will be sorted in ascending order.
 *
 * @array: is a pointer to the first element of the array to search in.
 * @size: is the number of elements in array.
 * @value: is the value to search for.
 *
 * Return: the index of the first value in the array.
 * If value is not present in array or if array is NULL,
 * your function must return -1.
 *
 * gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-advanced_binary.c
 * -o 0-advanced_binary
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array && size > 0)
		return (binary_search(array, value, 0, size - 1));

	return (-1);
}

/**
 * binary_search - searches for a value in a sorted subarray of integers
 * (from left to right index).
 *
 * @array: is a pointer to the first element of the array to search in.
 * @value: is the value to search for.
 * @left: left index of the subarray.
 * @right: right index of the subarray.
 *
 * Return: the index of the first value in the array.
 * -1 if value is not present in array.
 */
int binary_search(int *array, int value, int left, int right)
{
	int middle = (right + left) / 2;

	print_subarray(array, left, right);

	if (left == right && array[middle] != value)
		return (-1);

	if (array[middle] == value)
	{
		if (array[middle - 1] == value && middle > 0)
			return (binary_search(array, value, left, middle));
		else
			return (middle);
	}
	else if (value < array[middle])
		return (binary_search(array, value, left, middle - 1));
	else
		return (binary_search(array, value, middle + 1, right));
}

/**
 * print_subarray - print a subarray of integers.
 *
 * @array: is a pointer to the first element of the array.
 * @left: left index of the subarray.
 * @right: right index of the subarray.
 */
void print_subarray(int *array, int left, int right)
{
	int i;

	printf("Searching in array: ");

	for (i = left; i <= right; i++)
	{
		printf("%i", array[i]);

		if (i < right)
			printf(", ");
	}

	printf("\n");
}
