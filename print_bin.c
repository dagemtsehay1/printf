#include "holberton.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_bin - print binary
 * @list: va_list
 * Return: pointer to string of binary
 */

char *print_bin(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	char str[1024];
	char *binary;
	int i;

	binary = str;
	i = 0;

	if (num == 0)
	{
		str[++i] = '0';
	}
	while (num != 0)
	{
		str[i] = (num % 2) + '0';
		i++;
		num /= 2;
	}
	rev_string(str);
	str[i] = '\0';
	return (binary);
}
