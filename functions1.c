#include "main.h"

/**
 * print_unsigned - unsigned number
 * @types: List a of arguments
 * @buffer: handle print
 * @flags:  Calculates active
 * @width: width
 * @precision: specification
 * @size: specifier
 * Return: Number of chars printed.
 */

int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int w = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[w--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[w--] = (number % 10) + '0';
		number /= 10;
	}

	w++;

	return (write_unsgnd(0, w, buffer, flags, width, precision, size));
}

/**
 * print_octal - in octal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active
 * @width: get
 * @precision: specification
 * @size: specifier
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{

	int w = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(width);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[w--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[w--] = (number % 8) + '0';
		number /= 8;
	}

	if (flags & F_HASH && init_number != 0)
		buffer[w--] = '0';

	w++;

	return (write_unsgnd(0, w, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - notation
 * @types: arguments
 * @buffer: Buffer handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: specification
 * @size: specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}
/**
 * print_hexa_upper - Prints
 * @types: arguments
 * @buffer: handle print
 * @flags:  Calculates active
 * @width: get width
 * @precision: specification
 * @size: specifier
 * Return: chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}
/**
 * print_hexa - lower or upper
 * @types: arguments
 * @map_to: Array of values
 * @buffer: handle print
 * @flags:  Calculates
 * @flag_ch: Calculates
 * @width: get
 * @precision: specification
 * @size: specifier
 * @size: specification
 * Return: chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width,
		int precision, int size)
{
	int w = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(width);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[w--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[w--] = map_to[number % 16];
		number /= 16;
	}

	if (flags & F_HASH && init_number != 0)
	{
		buffer[w--] = flag_ch;
		buffer[w--] = '0';
	}

	w++;

	return (write_unsgnd(0, w, buffer, flags, width, precision, size));
}
