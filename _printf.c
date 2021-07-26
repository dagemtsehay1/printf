#include "holberton.h"
/**
 * _printf - a function that prints anything using
 *           posix callex via the write function
 * @format: formated string to be printed
 * Return: the number of things printed
 */
int _printf(const char *format, ...)
{
	va_list items;
	int i = 0, len = 0, *printed, *buffindex = malloc(sizeof(int));
	char buffer[BUFFER_SIZE];

	if (!format || !buffindex)
		return (-1);
	if (*format == '%' && _strlen((char *)format) == 1)
		return (-1);

	*buffindex = 0;
	va_start(items, format);
	while (*(format + i))
	{
		printed = print(format + i, items, buffindex, buffer);
		if (!printed)
			return (-1);
		len += printed[1];
		i += printed[0];
		free(printed);
	}
	if (*buffindex)
	{
		i = write(1, buffer, *buffindex);
		if (i == -1)
			return (-1);
		len += i;
	}
	va_end(items);
	free(buffindex);
	return (len);
}

/**
 *parse_format - takes a string and parse it in a printing format
 *for example if the str starts with %34f, this will be parse as
 *a float of length 34. This function always assums that the str
 *passed starts with %
 *@s: the string to be parsed that starts with %
 *Return:a struct containg the parsed values
 */
printing_format *parse_format(const char *s)
{
	int i = 1;
	char tmp;
	printing_format *format = malloc(sizeof(printing_format));

	if (!format)
		return (NULL);
	format->replaced = 0, format->width = 0, format->validity = false;

	i += checkflag(format, *(s + i));
	i += checkwidth(format, s + i);

	/*make sure that no usless character in between exists*/
	tmp = *(s + i);
	if (tmp == '.' || is_valid_id(tmp) || tmp == 'l' || tmp == 'h')
	{
		if (*(s + i) == '.')
		{
			i++;
			i += checkprecision(format, s + i);
		}
		i += checkmod(format, s + i);

		if (is_valid_id(*(s + i)))
		{
			format->printer = get_printer(*(s + i));
			format->replaced += 1;
			i++;
		}
		else
		{
			format->validity = false;
			return (format);
		}
		format->validity = true;
		format->replaced += 1;
	}
	return (format);
}
/**
 *buf_push - saves a string to a temporaty printing buffer
 *and returns the length of things compied or -1 on failure
 *@str:string top be copied
 *@buffindex: the current index of the buffer
 *@buffer: the printint que
 *Return: the length of string printed (the once that overflowed)
 *from the buffer
 */
int buf_push(char *str, int *buffindex, char *buffer)
{
	int tmplen = _strlen(str), k = 0, printed = 0;
	char null[] = "(null)";

	if (str == NULL)
		return (buf_push(null, buffindex, buffer));
	if (str == '\0')
		return (printed);
	while (tmplen)
	{
		while (*buffindex + 1 < BUFFER_SIZE && *str)
		{

			buffer[*buffindex] = *(str);
			*buffindex += 1, str += 1, tmplen -= 1;
		}
		if (*buffindex + 1 >= BUFFER_SIZE)
		{
			k = write(1, buffer, BUFFER_SIZE);
			if (k == -1)
				return (-1);
			*buffindex = 0;
			printed += k;
		}

	}
	return (printed);
}

/**
 *print - stores an element into a buffer based on a formated string
 *it also takes va_list incase the formated strin refers to an element
 *  a printer function that is passed as an argment, if buffer is full
 * prints and reinitializes the buffer
 *@str:  format string
 *@items: va_list containing the item to be printed accouring to the format
 *@buffindex: the current index of the printe queue
 *@buffer: printing queue
 *Return: [replaced formate string, len of printed]
 * replaced or [-1, -1] on error
 */
int *print(const char *str, va_list items, int *buffindex, char *buffer)
{
	char *tmp = NULL, perstr[] = "%", *tmpstr = malloc(sizeof(char) * 2);
	int *buf_stat = malloc(sizeof(int) * 2);
	printing_format *format = NULL;

	if (!tmpstr || !buf_stat)
		return (NULL);
	tmpstr[1] = '\0', buf_stat[0] = buf_stat[1] = -1;
	if (*(str) != '%')
	{
		tmpstr[0] = *str;
		buf_stat[1] = buf_push(tmpstr, buffindex, buffer), buf_stat[0] = 1;
	}
	else
	{
		format = parse_format(str);
		if (format)
		{
			if (format->validity)
			{
				tmp = (format->printer)(items, format);
				if (!tmp)
					tmp = NULL;
				buf_stat[1] = buf_push(tmp, buffindex, buffer);
				buf_stat[0] = format->replaced;
				free(tmp);
			}
			else
			{
				buf_stat[1] = buf_push(perstr, buffindex, buffer);
				/*incase I have %% the second one must be ignored*/
				if (*(str + 1) == '%')
					buf_stat[0] = 2;
				else
					buf_stat[0] = 1;
			}
		}
	}
	free(format);
	free(tmpstr);
	return (buf_stat);
}
