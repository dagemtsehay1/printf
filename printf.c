#include "holberton.h"

/**
 * _printf - a function that display a txt
 * @format: pointer to the string
 * @...:  to accept unlimited variable
 * Return: 0
 **/

int _printf(const char * format, ...)
{
  char *traveres;

  for (traveres = format; *traveres != '\0'; traveres++)
    {
      while (*traveres != '%')
	{
	  putchar (*traveres);
	  traveres++;
	}
