#include "holberton.h"

int valid_integer(char *string);
char *_malloc(int len);
char *_multiply(char *num1, char *num2, int n1_len, int n2_len);
void _print(char *string);

/**
 * main - receives 2 positive integers and multiplies them
 *
 * @argc: argv counter
 * @argv: arguments
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	int n1_len, n2_len;
	char *result;

	if (argc != 3)
	{
		_print("Error");
		exit(98);
	}

	n1_len = valid_integer(argv[1]);
	n2_len = valid_integer(argv[2]);

	if (n1_len == -1 || n2_len == -1)
	{
		_print("Error");
		exit(98);
	}

	if (argv[1][0] == '0' || argv[2][0] == '0')
	{
		_print("0");
		return (0);
	}

	if (n1_len >= n2_len)
		result = _multiply(argv[1], argv[2], n1_len, n2_len);
	else
		result = _multiply(argv[2], argv[1], n2_len, n1_len);

	if (result[0] == '0')
		_print(result + 1);
	else
		_print(result);

	free(result);
	return (0);
}

/**
 * _malloc - allocate space for a char array and set the values to 0
 *
 * @len: the len of the array
 *
 * Return: the pointer of the allocated array
 */
char *_malloc(int len)
{
	int i;

	char *result = malloc(len);

	if (!result)
	{
		_print("Error\n");
		exit(98);
	}

	for (i = 0; i < len; i++)
		result[i] = '0';

	return (result);
}

/**
 * _multiply - multiplies
 *
 * @num1: first number
 * @num2: second number
 * @n1_len: length of num1
 * @n2_len: length of num2
 *
 * Return: result of multiplies
 */
char *_multiply(char *num1, char *num2, int n1_len, int n2_len)
{
	int i, j, carry;
	char *result = _malloc(n1_len + n2_len);

	for (i = n1_len - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = n2_len - 1; j >= 0; j--)
		{
			carry += (num1[i] - '0') * (num2[j] - '0');
			carry += result[i + j + 1] - '0';
			result[i + j + 1] = (carry % 10) + '0';
			carry /= 10;
		}

		if (carry)
			result[i + j + 1] = (carry % 10) + '0';
	}

	return (result);
}

/**
 * _print - print a string and a new line
 *
 * @string: pointer to the string
 */
void _print(char *string)
{
	while (*string != '\0')
	{
		_putchar(*string);
		string += 1;
	}

	_putchar('\n');
}

/**
 * valid_integer - check whether all characters of 'string' are digits or not
 *
 * @string: pointer to the first character of the *char
 *
 * Return: the lenth of 'string' or -1 on error.
 */
int valid_integer(char *string)
{
	int length = 0;

	while (*string != '\0')
	{
		if (*string >= 48 && *string <= 57)
			length += 1;
		else
			return (-1);

		string += 1;
	}

	return (length);
}
