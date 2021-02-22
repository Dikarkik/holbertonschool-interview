#include <stdlib.h>
#include <stdio.h>

#include "slide_line.h"

/**
 * print_array - Prints out an array of integer, followed by a new line
 * 
 * @array: Pointer to the array of integer to be printed
 * @size: Number of elements in @array
 */
static void print_array(int const *array, size_t size)
{
	size_t i;

	printf("Line: ");
	for (i = 0; i < size; i++)
		printf("%s%d", i > 0 ? ", " : "", array[i]);
	printf("\n");
}

/**
 * main - Entry point
 *
 * @ac: Arguments counter
 * @av: Arguments vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main()
{
	/* test 1 */
	int test1[4] = {2, 2, 0, 0};
	print_array(test1, 4);
	printf("Slide to the left\n");
	slide_line(test1, 4, SLIDE_LEFT);
	print_array(test1, 4);
	printf("MUST BE\n");
	printf("Line: 4, 0, 0, 0\n");
	printf("======================================\n");

	/* test 2 */
	int test2[14] = {2, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 4};
	print_array(test2, 14);
	printf("Slide to the left\n");
	slide_line(test2, 14, SLIDE_LEFT);
	print_array(test2, 14);
	printf("MUST BE\n");
	printf("Line: 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n");
	printf("======================================\n");

	/* test 3 */
	int test3[4] = {2, 2, 2, 2};
	print_array(test3, 4);
	printf("Slide to the right\n");
	slide_line(test3, 4, SLIDE_RIGHT);
	print_array(test3, 4);
	printf("MUST BE\n");
	printf("Line: 0, 0, 4, 4\n");
	printf("======================================\n");

	/* test 4 */
	int test4[5] = {2, 2, 2, 2, 2};
	print_array(test4, 5);
	printf("Slide to the right\n");
	slide_line(test4, 5, SLIDE_RIGHT);
	print_array(test4, 5);
	printf("MUST BE\n");
	printf("Line: 0, 0, 2, 4, 4\n");
	printf("======================================\n");

	/* test 5 */
	int test5[4] = {2, 4, 8, 16};
	print_array(test5, 4);
	printf("Slide to the left\n");
	slide_line(test5, 4, SLIDE_LEFT);
	print_array(test5, 4);
	printf("MUST BE\n");
	printf("Line: 2, 4, 8, 16\n");
	printf("======================================\n");

	/* test 6 */
	int test6[4] = {2, 4, 8, 16};
	print_array(test6, 4);
	printf("Slide to the right\n");
	slide_line(test6, 4, SLIDE_RIGHT);
	print_array(test6, 4);
	printf("MUST BE\n");
	printf("Line: 2, 4, 8, 16\n");
	printf("======================================\n");

	/* test 7 */
	int test7[4] = {4, 4, 8, 16};
	print_array(test7, 4);
	printf("Slide to the right\n");
	slide_line(test7, 4, SLIDE_RIGHT);
	print_array(test7, 4);
	printf("MUST BE\n");
	printf("Line: 0, 8, 8, 16\n");
	printf("======================================\n");

	return (EXIT_SUCCESS);
}
