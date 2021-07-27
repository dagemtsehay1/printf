#include "holberton.h"

/**
 * int p_binary - prints an int int binary (handles b)
 * @ap: the int to be printed
 *
 * Return: number of chars printed.
 */

int p_binary(va_list ap)
{
	unsigned int n, arr[33], len = 0;
	int i = 0;

	n = va_arg(ap, unsigned int);
	
	if (!n)
		i++;	
	while (n > 0)
	{
		arr[i] = n % 2;
		n /= 2;
		i++;
	}
	i--;

	while (i >= 0)
	{
		_putchar(arr[i] + '0');
		i--;
		len++;
	}

	return (len);
}

/**
 * p_udec - prints an unsigned int in dec (handles u)
 * @ap: uint to be printed.
 *
 * Return: number of chars printed.
 */

int p_udec(va_list ap)
{
	unsigned int n, arr[10], len = 0;
	int i = 0;

	n = va_arg(ap, unsigned int);

	if(!n)
	{
		i++;
		arr[0] = 0;
	}
	while (n > 0)
	{
		arr[i] = n % 10;
		n /= 10;
		i++;
	}
	i--;

	while (i >= 0)
	{
		_putchar(arr[i] + '0');
		i--;
		len++;
	}

	return (len);
}
		
/**
 * p_oct - prints an unsigned int in octal (handles o)
 * @ap: uint to be printed.
 *
 * Return: number of chars printed.
 */

int p_oct(va_list ap)
{
	unsigned int n, arr[11], len = 0;
	int i = 0;

	n = va_arg(ap, unsigned int);
	
	if (!n)
	{
		i++;
		arr[0] = 0;
	}	
	while (n > 0)
	{
		arr[i] = n % 8;
		n /= 8;
		i++;
	}
	i--;

	while (i >= 0)
	{
		_putchar(arr[i] + '0');
		i--;
		len++;
	}

	return (len);
}

/**
 * int p_xhex - prints a uint in lowercase hex
 * @ap: the int to be printed
 *
 * Return: number of chars printed.
 */

int p_xhex(va_list ap)
{
	unsigned int n, arr[8], len = 0;
	int i = 0;

	n = va_arg(ap, unsigned int);
	
	if (!n)
	{
		i++;
		arr[0] = 0;
	}	
	while (n > 0)
	{
		arr[i] = n % 16;
		n /= 16;
		i++;
	}
	i--;

	while (i >= 0)
	{
		if (arr[i] < 10)
			_putchar(arr[i] + '0');
		else
			_putchar(arr[i] + '0' + 'a' - ':');
		i--;
		len++;
	}

	return (len);
}
/**
 * p_Xhex - prints a uint in uppercase hex notation.
 * @ap: the uint to be printed.
 *
 * Return: no. of chars printed.
 */
int p_Xhex(va_list ap)
{
	unsigned int n, arr[8], len = 0;
	int i = 0;

	n = va_arg(ap, unsigned int);

	if (!n)
	{
		i++;
		arr[0] = 0;
	}
	while (n > 0)
	{
		arr[i] = n % 16;
		n /= 16;
		i++;
	}
	i--;

	while (i >= 0)
	{
		if (arr[i] < 10)
			_putchar(arr[i] + '0');
		else
			_putchar(arr[i] + '0' + 'A' - ':');
		i--;
		len++;
	}

	return (len);
}
