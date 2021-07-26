#include "holberton.h"
/**
 * _putrts - reverses string inside a va_list
 * @list: the variadic list to extract it from
 * @format: the format to use to prepare it
 * Return: a character pointer to the reversed string
 */
char *_putrts(va_list list, __attribute__((unused)) printing_format * format)
{
	char *s = va_arg(list, char *);
	char *s2 = malloc(sizeof(char) * _strlen(s) + 1);

	if (!s2)
		return (NULL);

	_strcpy(s2, s);
	rev_string(s2);
	return (s2);

}
/**
 * _putrot13 - a rot13 encrypted string from the va_list
 *@list: the variadic list to extract it from
 *@format: the format to use to prepare it
 *Return: a character pointer to the the encrypted string
 */
char *_putrot13(va_list list, __attribute__((unused)) printing_format * format)
{

	char *s = va_arg(list, char *);
	char *s2 = malloc(sizeof(char) * _strlen(s) + 1);

	if (!s2)
		return (NULL);

	_strcpy(s2, s);
	rot13(s2);
	return (s2);

}
/**
 * _putS - Non printable characters
 * (0 < ASCII value < 32 or >= 127) are
 * printed this way: \x, followed by the ASCII code
 * value in hexadecimal (upper case - always 2 characters)
 * @l: va_list arguments from _printf
 * @format: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */
char *_putS(va_list l, __attribute__((unused)) printing_format * format)
{
	char *_s2, *s2, *hex, *_hex, *s = va_arg(l, char *);
	int n;

	if (!s)
		return (NULL);
	s2 = malloc(sizeof(char) * _strlen(s) * 4 + 1);
	if (!s2)
		return (NULL);
	_s2 = s2;
	while (*s)
	{
		n = *s;
		if ((n > 0 && n < 32) || n >= 127)
		{
			*_s2 = '\\', *(_s2 + 1) = 'x';
			_s2 += 2;
			if (n < 16)
				*_s2 = '0', _s2 += 1;
			hex = to_hex(n);
			if (!hex)
				return (NULL);
			_hex = hex;
			while (*_hex)
				*_s2 = *_hex, _s2 += 1, _hex += 1;
			free(hex);
		}
		else
			*_s2 = *s, _s2 += 1;
		s++;
	}
	_s2 = '\0';
	return (s2);
}
