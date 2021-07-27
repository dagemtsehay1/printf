#include "holberton.h"

/**
 * print_c - prints char
 * @list: arguement char
 * Return: pointer args
 */

char *print_c(va_list list)
{
	static char s[2] = {0, '\0'};

	s[0] = va_arg(list, int);
	if (s[0] == '\0')
	{
		return (" ");
	}
	return (s);
}

/**
 * print_s - prints string
 * @list: list to print
 * Return: pointer args
 */

char *print_s(va_list list)
{
	char *s;

	s = va_arg(list, char *);
	if (s == NULL)
	{
		return (s = "(null)");
	}
	return (s);
}

/**
 * print_i - Prints an integer
 * @list: list of arguments
 * Return: pointer args
 */

char *print_i(va_list list)
{
	char *output;

	int divisor = 1000000000;
	int digit = 0, i = 0, neg = 0;
	int num = va_arg(list, int);
	int len = _numlen(num);
	output = malloc(len * sizeof(char) + 1 + neg);
	if (output == NULL)
	{
		free(output);
		return (0);
	}
	if (num < 0)
	{
		neg++;
	}
	if (num < 0)
	{
		output[i] = '-';
		i++;
	}
	if (num > -10 && num < 10)
	{
		output[i] = _abs(0num) + '0';
		return (output);
	}
	while (divisor)
	{
		digit = (num / divisor) % 10;
		if (num < 0)
		{
			digit = _abs(digit);
		}
		if (digit != 0 || (len >= 0  && output[i - 1] >= '0'))
		{
			output[i] = digit + '0';
			i++;
			len--;
		}
		divisor /= 10;
	}
	output[i] = '\0';
	return (output);
}
