#include "main.h"

/**
 * print_pointer - Prints variable
 * @types: arguments
 * @buffer: handle print
 * @flags:  Calculates active
 * @width: get
 * @precision: specification
 * @size: specifier
 * Return: chars printed.
 */
int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/**
 * print_non_printable - ascii codes
 * @types: arguments
 * @buffer: handle print
 * @flags:  Calculates active
 * @width: get
 * @precision: specification
 * @size: specifier
 * Return: chars printed
 */
int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int w = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[w] != '\0')
	{
		if (is_printable(str[w]))
			buffer[w + offset] = str[w];
		else
			offset += append_hexa_code(str[w], buffer, w + offset);

		w++;
	}

	buffer[w + offset] = '\0';

	return (write(1, buffer, w + offset));
}

/**
 * print_reverse - string.
 * @types: arguments
 * @buffer: handle print
 * @flags:  Calculates active
 * @width: get
 * @precision: specification
 * @size: specifier
 * Return: chars printed
 */

int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char *str;
	int w, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (w = 0; str[w]; w++)
		;

	for (w = w - 1; w >= 0; w--)
	{
		char z = str[w];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/**
 * print_rot13string - string in rot13.
 * @types: arguments
 * @buffer: handle print
 * @flags:  Calculates active
 * @width: get
 * @precision: specification
 * @size: specifier
 * Return: chars printed
 */
int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int w, d;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (w = 0; str[w]; w++)
	{
		for (d = 0; in[d]; d++)
		{
			if (in[d] == str[w])
			{
				x = out[d];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[d])
		{
			x = str[w];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
