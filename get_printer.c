#include "holberton.h"
/**
 *get_printer - returns the correct pointer
 *to function based on a specifier character
 *@id: a delimeter
 *Return: a function pointer,
 *
 */
char *(*get_printer(char id))(va_list, printing_format *)
{

	char *(*printer)(va_list, printing_format *);

	switch (id)
	{
		case 'c':
			printer = _putchar;
			break;

		case 's':
			printer = _putstr;
			break;

		case 'd':
			printer = _putint;
			break;

		case 'i':
			printer = _putint;
			break;

		case 'u':
			printer = _putuint;
			break;

		case 'b':
			printer = _putbin;
			break;
		case 'o':
			printer = _putoct;
			break;

		case 'x':
			printer = _puthex;
			break;

		case 'X':
			printer = _putHex;
			break;

		case 'p':
			printer = _putadress;
			break;

		case 'r':
			printer = _putrts;
			break;

		case 'R':
			printer = _putrot13;
			break;

		case 'S':
			printer = _putS;
			break;

		default:
			printer = NULL;
			break;
	}

	return (printer);
}
 
