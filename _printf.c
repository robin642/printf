#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	int w, prints = 0, printed_charz = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (w = 0; format && format[w] != '\0'; w++)
	{
		if (format[w] != '%')
		{
			buffer[buff_ind++] = format[w];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_charz++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &w);
			width = get_width(format, &w, list);
			precision = get_precision(format, &w, list);
			size = get_size(format, &w);
			++w;
			prints = handle_print(format, &w, list, buffer,
				flags, width, precision, size);
			if (prints == -1)
				return (-1);
			printed_charz += prints;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_charz);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
