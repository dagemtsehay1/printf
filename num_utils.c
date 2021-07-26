#include "holberton.h"


/**
 *_pow - raises the number base to power power
 *@base : the base
 *@power : the power
 *Return: return the answer
 */
int _pow(unsigned int base, int power)
{
	int i, prod = 1;

	for (i = 0; i < power; i++)
	{
		prod = prod * base;
	}
	return (prod);
}

/**
 *_numLen - returns the lenth of string
 *@num : operand number
 *Return: number of digits
 */
int _numLen(unsigned int num)
{
	int length = 0;

	if (!num)
		return (1);

	while (num)
	{
		num = num / 10;
		length += 1;
	}

	return (length);
}

/**
 *max - returns max of two strings
 *@a : num 1
 *@b: num 2
 *Return: the great of a or b
 */
int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

/**
 *to_hex - change an in into a hex
 *@n: num
 *Return: hex string
 */
char *to_hex(int n)
{
	char *s = malloc(sizeof(char) * n / 16 + 2), *_s;
	int tmp;

	if (!s)
		return (NULL);
	if (!n)
	{
		s[0] = '0', s[1] = '\0';
		return (s);
	}
	_s = s;
	while (n != 0)
	{
		tmp = n % 16;

		if (tmp < 10)
			*_s = tmp + 48;
		else
			*_s = tmp + 55;
		n = n / 16;
		_s++;
	}
	*_s = '\0';
	rev_string(s);
	return (s);
}
