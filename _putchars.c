#include "holberton.h"
/**
 * _putchar - writes the character c to stdout
 * @c: an arg_list containing the character to be printed
 * @format: the format to use to prepare the string
 * Return: On success 1.
 * On error, return -1
 */
char *_putchar(va_list c, __attribute__((unused)) printing_format * format)
{
	char a = va_arg(c, int), *s = malloc(sizeof(char) * 2);

	if (!s)
		return (NULL);
	s[0] = a;
	s[1] = '\0';

	return (s);
}

/**
 * _putstr - writes the character c to stdout
 * @c: an arg list containing the string to be printed
 * @format: the format to use to prepare the string
 * Return: On success the lenght of the string printed
 * -1 on failure
 */
char *_putstr(va_list c, __attribute__((unused))printing_format * format)
{
	char *s = va_arg(c, char *), *s2 = malloc(sizeof(char) * _strlen(s) + 1);

	if (!s2 || !s)
		return (NULL);
	_strcpy(s2, s);
	return (s2);
}
