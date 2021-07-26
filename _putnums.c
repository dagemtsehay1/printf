#include "holberton.h"

/**
 *_putint - Print a number of any digit
 *@num: takes a varadic list containing the number to be printed
 *@format: the format to use to prepare the string
 *Return: the lenght of the integer printed
 */
char *_putint(va_list num, printing_format *format)
{
	char *nums, *_nums, mod = format->mod;
	long int n;
	int len, strwid;

	/*since shorts are auto casted to int on appending to va_list*/
	if (mod == 'l')
		n = va_arg(num, long);
	else
		n = va_arg(num, int);

	len = _numLen(n >= 0 ? n : -1 * n);
	nums = malloc(sizeof(char) * max(len, format->width) + 2);
	/*create a manipulating pointer*/
	_nums = nums;

	strwid = len;
	if (n < 0 || format->flag == '+')
		strwid += 1;
	while (format->width > strwid)
		*_nums = ' ', _nums += 1, strwid += 1;

	if (!nums)
		return (NULL);
	if (n < 0)
		*_nums = '-', _nums += 1;

	if (format->flag == '+')
	{
		if (n > 0)
			*_nums = '+', _nums += 1;
	}
	else if (format->flag == ' ')
		if (n > 0)
			*_nums = ' ', _nums += 1;

	/*change the number to a reversed string and reverse it*/
	_toStr(n >= 0 ? n : -1 * n, _nums);
	*(_nums + len) = '\0';
	rev_string(_nums);
	return (nums);
}


/**
 *_putuint - Print a unsigned int of any digit
 *@num : a va_list containing the unsigned int to be printed as the first item
 *@format: the format to use to prepare the string
 *Return: the lenght of the unsigned integer printed
 */
char *_putuint(va_list num, printing_format *format)
{
	char *nums, mod = format->mod, *_nums;
	unsigned long int n;
	int len, strwid;

	/*since shorts are auto casted to int on appending to va_list*/
	if (mod == 'l')
		n = va_arg(num, unsigned long);
	else
		n = va_arg(num, unsigned int);

	len = _numLen(n);
	nums = malloc(sizeof(char) * max(len, format->width) + 2);
	if (!nums)
		return (NULL);
	_nums = nums;
	strwid = len;

	if (format->flag == '+')
		strwid += 1;
	while (format->width > strwid)
		*_nums = ' ', _nums += 1, strwid += 1;

	if (format->flag == '+')
		*_nums = '+', _nums += 1;
	else if (format->flag == ' ')
		*_nums = ' ', _nums += 1;

	_toStr(n, _nums);
	*(_nums + len) = '\0';
	rev_string(_nums);
	return (nums);
}
