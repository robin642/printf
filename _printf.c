#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - The printf function
 * @format: The format.
 * Return: The printed chars.
 */

int _printf(const char *format, ...)

{
		int r, prints = 0, printed_charz = 0;
		int flags, width, precision, size, buff_ind = 0;
		va_list list;
		char buffer[BUFF_SIZE];

		if (format == NULL)
			return (-1);

		va_start(list, format);

		for (r = 0; format && format[r] != '\0'; r++)
		{
			if (format[r] != '%')
			{	
				buffer[buff_ind++] = format[r];
				if (buff_ind == BUFF_SIZE)
					print_buffer(buffer, &buff_ind);
				/* write(1, &format[i], 1);*/
				printed_charz++;
			}
			else
			{
				print_buffer(buffer, &buff_ind);
				flags = get_flags(format, &r);
				width = get_width(format, &r, list);
				precision = get_precision(format, &r, list);
				size = get_size(format, &r);
				++r;
				prints = handle_print(format, &r, list, buffer,
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
 * print_buffer - It prints the contents of the buffer if it exist
 * @buffer: The array of chars
 * @buff_ind: The index at which to add next char, represents the length.
 */

void print_buffer(char buffer[], int *buff_ind)

{
		if (*buff_ind > 0)
			write(1, &buffer[0], *buff_ind);

		*buff_ind = 0;
}