#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"

/**
 * main - Entry point
 *
 * @ac: Arguments counter
 * @av: Arguments vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 * 
 * ./palindrome 1 (true)
 * ./palindrome 11 (true)
 * ./palindrome 112 (false)
 * ./palindrome 121 (true)
 * ./palindrome 12345678987654321 (true)
 * ./palindrome 123456789987654321 (true)
 * ./palindrome 1234567898654321 (false)
 */
int main(int ac, char **av)
{
	unsigned long n;
	int ret;

	if (ac < 2)
	{
		fprintf(stderr, "Usage: %s arg\n", av[0]);
		return (EXIT_FAILURE);
	}

	n = (unsigned long)(atol(av[1]));
	ret = is_palindrome(n);

	printf("%lu is ", n);
	if (ret == 0)
		printf("not ");
	printf("a palindrome.\n");

	return (EXIT_SUCCESS);
}
