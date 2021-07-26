#include "holberton.h"
/**
*is_valid_id - checks if id is part of the allowed identifiers
*@id: identifier
*Return: true if it is a valid identifier or false if it isn't
*/
bool is_valid_id(char id)
{
	if (id == 'c' || id == 's' || id == 'd' || id == 'i'
			|| id == 'u' || id == 'b' || id == 'o'
			|| id == 'X' || id == 'R' || id == 'x'
			|| id == 'p' || id == 'r' || id == 'S')

		return (true);

	return (false);
}

/**
 *checkflag - takes a format string and puts it in side a printing
 *format struct if it is valid
 *@format: the struct to store the flag
 *@flag: the character to be compared with
 *Return: the length of the flag
 */
int checkflag(printing_format *format, char flag)
{

	/*check for flages*/
	if (flag == ' ' || flag == '+' || flag == '#')
	{
		format->flag = flag;
		format->replaced += 1;
		return (true);
	}
	format->flag = '\0';
	return (false);
}

/**
 *checkwidth - takes a formated string and gets the width of
 *to be printed
 *@format: the struct to store the width
 *@s: the character to be compared with
 *Return: length of the the number string
 */
int checkwidth(printing_format *format, const char *s)
{
	int i = 0;


	/*check for width*/
	while (*(s + i) > 47 && *(s + i) < 58)
	{
		format->width = format->width * 10 + (int)(*(s + i) - 48);
		format->replaced += 1;
		i++;
	}
	return (i);
}

/**
 *checkprecision - takes a format string and stores the precision in the
 *struct if it is valid
 *@format: the struct to store the flag
 *@s: the character to be compared with
 *Return: the length of the precision string
 */
int checkprecision(printing_format *format, const char *s)
{
	int i = 0;

	/*check for precision*/

	while (*(s + i) > 47 && *(s + i) < 58)
	{
		format->precision = format->precision * 10 + (int)(*(s + i) - 48);
		format->replaced += 1;
		i++;
	}
	return (i);
}

/**
 *checkmod - takes a format string and stores the precision in the
 *struct if it is valid
 *@format: the struct to store the flag
 *@s: the character to be compared with
 *Return: the length of the precision string
 */
int checkmod(printing_format *format, const char *s)
{
	int i = 0;

	if (*(s) == 'h' || *(s) == 'l')
	{
		format->mod = *(s);
		format->replaced += 1;
		i++;
	}

	else
		format->mod = '\0';
	return (i);
}
