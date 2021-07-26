#include "holberton.h"
/**
 * print_character - prints character
 * @arg: va_list parameter
 * Description: print character
 * Return: 1
 */
int print_character(va_list arg)
{
	int i;

	i = va_arg(arg, int);
	_putchar(i);

	return (1);
}
/**
 * print_sign - print sign
 * @arg: va_list parameter
 * @base: base 10, 8, 16, 2 etc..
 * Description: print numbers and signed
 * Return: num of characters
 */
int print_sign(va_list arg, int base)
{
	int i = 0, cont = 0;
	char *s;

	i = va_arg(arg, int);
	if (i < 0)
	{
		i = -(i);
		_putchar('-');
		cont += 1;
	}
	s = convert_to("0123456789ABCDEF", i, base);
	_puts(s);
	cont += _strlen(s);
	return (cont);
}
/**
 * print_unsign - print_unsign
 * @arg: va_list parameter
 * @base: base 10, 8, 16 etc..
 * Description: print numbers without signed
 * Return: num of characters
 */
int print_unsign(va_list arg, int base)
{
	int cont = 0;
	unsigned int i;
	char *s;

	i = va_arg(arg, unsigned int);
	s = convert_to("0123456789ABCDEF", i, base);
	_puts(s);
	cont = _strlen(s);

	return (cont);

}
/**
 * print_string - print string
 * @arg: va_list parameter
 * Description: print string
 * Return: num of characters
 */
int print_string(va_list arg)
{
	char *s;
	int cont = 0;

	s = va_arg(arg, char *);
	if (!s)
	{
		s = "(null)";
		_puts(s);

		return (_strlen(s));
	}
	_puts(s);
	cont = _strlen(s);
	return (cont);
}
/**
 * print_base16_upper_lower - print_base16_upper_lower
 * @arg: va_list parameter
 *@representation: pointer parameter
 * Description: This function takes 0123456789ABCDEF or 0123456789abcdef
 * in representation parameter for print hexadecimal format
 * Return: num of characters
 */
int print_base16_upper_lower(va_list arg, char *representation)
{
	unsigned int i = 0, cont = 0;
	char *s;

	i = va_arg(arg, unsigned int);
	s = convert_to(representation, i, 16);
	_puts(s);
	cont = _strlen(s);
	return (cont);

}
