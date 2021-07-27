#include "holberton.h"

/**
 * _str_positing - postrion of a string
 * @str: input string
 * Return: returns a basic position of a atring
 */

int _position(const char *str, int n)
{
	int i;

	i = 0;

	while (*str)
	{
		if (str[n + 1] != ' ')
		{
			return (i);
		}
		n++;
		i++;
	}
	return (0);
}

/**
 * _strlen -print the length oa string
 * @str: input string
 * Return: length of the string
 */

int _strlen(char *str)
{
	register int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _numlen - prints the len of a number
 * @num: input integer
 * Return: lenght of a number
 */

int _numlen(int num)
{
	register int len;

	len = 0;
	while (num / 10 != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

/**
 * _strcat - concatenate two strings
 * @dest: string destination
 * @str: input string
 * @n: input integer
 * Return: concatenated atring
 */

char *_strcat(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[n + i] = src[i];
		i++;
	}
	return (dest);
}

/**
 * _abs - prints an absolute of a number
 * @n: input integer
 * Return: absolute values
 */

int _abs(int n)
{
	if (n < 0)
	{
		n *= -1;
	}
	return (n);
}

/**
 * str_rev - reverses atring
 * @str: input string to be reversed
 * Return: returns a reversed string
 */

void *rev_string(char *s)
{
	char ltemp;

	int i = 0;
	int aux = 0;
	while (*(s + i) != '\0')
	{
		i += 1;
	}
	i -= 1;
	while (aux < i)
	{
		ltemp = s[i];
		s[i] = s[aux];
		s[aux] = ltemp;
		aux++;
		i--;
	}
	return (s);
}
