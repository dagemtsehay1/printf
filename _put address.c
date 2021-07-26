#include "holberton.h"

/**
 * _putadress - prints the adress of a memory in hex form
 * @num: input integer (memory location as ui insided a va_list)
 * @format: the format the string must be returned with
 * Return: length of hex
 */
char *_putadress(va_list num, __attribute__((unused)) printing_format * format)
{
	unsigned long int n = va_arg(num, unsigned long int);
	char *nums =  malloc(sizeof(char) * _numLen(n) * 2 + 3);
	int i = 0, tmp;

	if (!nums)
		return (NULL);
	if (!n)
	{
		nums[0] = '(', nums[1] = 'n', nums[2] = 'i', nums[3] = 'l';
		nums[4] = ')', nums[5] = '\0';
		return (nums);

	}
	nums[0] = '0', nums[1] = 'x';
	nums += 2;

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
	rev_string(nums);
	nums -= 2;
	return (nums);
}
