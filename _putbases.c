#include "holberton.h"
/**
 * _putbin - prints the binary representation of a number
 * @num: input integer
 * @format: the format to use to prepare the string
 * Return: length of binary
 */
char *_putbin(va_list num, __attribute__((unused)) printing_format * format)
{
	unsigned int n = va_arg(num, unsigned int);
	unsigned int test = _pow(2, sizeof(unsigned int) * BIT_SIZE - 1);
	bool start = false;
	char *bin = malloc(sizeof(char) * (1 + n / 2) + 1), *_bin;

	if (!bin)
		return (NULL);
	_bin = bin;
	if (n == 0)
		*bin = '0';
	else
		while (test)
		{
			if (!(test & n) && start)
				*_bin = '0', _bin += 1;
			else if (test & n)
				*_bin = '1', start = true, _bin += 1;
			test = test >> 1;
		}

	*_bin = '\0';
	return (bin);
}

/**
 * _puthex - prints the lowercase hex representation of a number
 * @num: input integer
 * @format: the format to use to prepare the string
 * Return: length of hex
 */
char *_puthex(va_list num, printing_format *format)
{
	unsigned long int n;
	char *nums, mod = format->mod;
	int i = 0, tmp;

	if (mod == 'l')
		n = va_arg(num, unsigned long);
	else
		n = va_arg(num, unsigned int);
	nums  =  malloc(sizeof(char) * ((n == 0) ? _numLen(n) + 1 : _numLen(n)) + 3);
	if (!nums)
		return (NULL);
	if (n == 0)
	{
		nums[0] = '0', nums[1] = '0', nums[2] = '\0';
		return (nums);
	}
	if (format->flag == '#')
		nums[0] = '0', nums[1] = 'x', i += 2;
	while (n != 0)
	{
		tmp = n % 16;
		if (tmp < 10)
			nums[i] = tmp + 48;
		else
			nums[i] = tmp + 87;
		n = n / 16;
		i++;
	}
	nums[i] = '\0';
	if (format->flag == '#')
		rev_string(nums + 2);
	else
		rev_string(nums);
	return (nums);
}


/**
 * _putHex - prints the uppercase hex representation of a number
 * @num: input integer
 * @format: the format to use to prepare the string
 * Return: length of hex
 */
char *_putHex(va_list num, printing_format *format)
{
	unsigned long int n;
	char *nums, mod = format->mod;
	int i = 0, tmp;


	if (mod == 'l')
		n = va_arg(num, unsigned long);
	else
		n = va_arg(num, unsigned int);
	nums =  malloc(sizeof(char) * ((n == 0) ? _numLen(n) + 1 : _numLen(n)) + 3);
	if (!nums)
		return (NULL);

	if (n == 0)
	{
		nums[0] = '0', nums[1] = '0', nums[2] = '\0';
		return (nums);
	}

	if (format->flag == '#')
		nums[0] = '0', nums[1] = 'x', i += 2;

	while (n != 0)
	{
		tmp = n % 16;

		if (tmp < 10)
			nums[i] = tmp + 48;
		else
			nums[i] = tmp + 55;
		n = n / 16;
		i++;
	}
	nums[i] = '\0';
	if (format->flag == '#')
		rev_string(nums + 2);
	else

		rev_string(nums);
	return (nums);
}

/**
 * _putoct - prints the octal representation of a number
 * @num: input integer
 * @format: the format to use to prepare the string
 * Return: length of octal
 */
char *_putoct(va_list num, printing_format *format)
{
	unsigned long int n;
	char *nums, mod = format->mod;
	int i = 0, tmp;


	if (mod == 'l')
		n = va_arg(num, unsigned long);
	else
		n = va_arg(num, unsigned int);

	nums =  malloc(sizeof(char) * _numLen(n) * 2 + 3);
	if (!nums)
		return (NULL);

	while (n != 0)
	{
		tmp = n % 8;
		nums[i] = tmp + 48;
		n = n / 8;
		i++;
	}
	nums[i] = '\0';
	switch (format->flag)
	{
		case '#':
			rev_string(nums + 2);
			break;
		default:

			rev_string(nums);
			break;
	}
	return (nums);
}
