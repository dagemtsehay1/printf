#include "holberton.h"

/**
 * _strlen - returns the length of a string
 * @s: string s
 * Return: length of string
 */
int _strlen(char *s)
{
	int length = 0;

	if (!s)
		return (0);
	while (*s)
	{
		s++;
		length++;
	}
	return (length);
}

/**
 * rev_string - reverses a string
 * @s: string to be reversed
 */
void rev_string(char *s)
{
	int length = _strlen(s);
	int counter = 0;
	char tmp;

	while (counter < length / 2)
	{
		tmp = *(s + counter);
		*(s + counter) = *(s + length - 1 - counter);
		*(s + length - 1 - counter) = tmp;
		counter++;
	}

}


/**
 * _toStr - changes an int to a a string and saves it in nums
 * @n:num
* @nums:pointer to store the number
*/
void _toStr(unsigned long int n, char *nums)
{
	if (n < 10)
	{
		*nums = (char)(n % 10 + 48);
		return;
	}
	*nums = (char)(n % 10 + 48);
	nums++;
	_toStr(n / 10, nums);
}

/**
 * _strcpy - copies the string pointed to by src,
 * including the terminating null byte
 * @dest: copied string
 * @src: string to be copied
 * Return: pointer to new copied string
 */
char *_strcpy(char *dest, char *src)
{
	char *ptr = dest;

	if (!src)
	{
		dest = NULL;
		return (NULL);
	}

	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (ptr);
}

/**
 * rot13 - encodes a string using rot13
 * @s: input string
 * Return: encoded string
 */
char *rot13(char *s)
{
	int i;

	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *ptr = s;


	while (*s)
	{
		for (i = 0; i <= 52; i++)
		{
			if (*s == rot13[i])
			{
				*s = ROT13[i];
				break;
			}
		}
		s++;
	}
	return (ptr);
}
