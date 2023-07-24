#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */

int get_width(const char *format, int *i, va_list list)
{
	int curr_w;
	int width = 0;

	for (curr_w = *i + 1; format[curr_w] != '\0'; curr_w++)
	{
		if (is_digit(format[curr_w]))
		{
			width *= 10;
			width += format[curr_w] - '0';
		}
		else if (format[curr_w] == '*')
		{
			curr_w++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_w - 1;

	return (width);
}
