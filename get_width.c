#include "main.h"

/**
 * get_width - The calculates the width for printing
 * @format: The formatted string in which to print the arguments.
 * @i: The list of arguments to be printed.
 * @list: The list of arguments.
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int connect_r;
	int width = 0;

	for (connect_r = *i + 1; format[connect_r] != '\0'; connect_r++)
	{
		if (is_digit(format[connect_r]))
		{
			width *= 10;
			width += format[connect_r] - '0';
		}
		else if (format[connect_r] == '*')
		{
			connect_r++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = connect_r - 1;

	return (width);
}
