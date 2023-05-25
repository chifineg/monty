#include <stdlib.h>

char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
		       char *buff, int buff_size);

/**
 * get_int - character pointer to new string that contains int
 * @num: this number is to convert to string
 *
 * Return: character pointer to new created string. Malloc fails, NULL
 */
char *get_int(int num)
{
	unsigned int tmp;
	int len = 0;
	long num_l = 0;
	char *ret;

	tmp = _abs(num);
	len = get_numbase_len(tmp, 10);

	if (num < 0 || num_l < 0)
		length++;
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);

	fill_numbase_buff(tmp, 10, ret, len);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * _abs - absolute value of integer
 * @i:
 *
 * Return: abs rep of i
 */
unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * get_numbase_len - length of buffer for an unsigned int
 * @num: get length needed
 * @base: number representation used by buffer
 *
 * Return: the integer that contains the length of the buffer needed (no null)
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * fill_numbase_buff - buffer filled with numbers only works up to base 36
 * @num: convert numbers to string given base
 * @base: numbers that only works up to base 36 in conversion
 * @buff: filled with result of conversion
 * @buff_size: buffer size in bytes
 *
 * Return: always void.
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
			char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9)
			buff[i] = rem + 87;
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}
