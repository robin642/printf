#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */

int get_precision(const char *format, int *i, va_list list)

{
	int curr_d = *i + 1;
	int precision = -1;

	if (format[curr_d] != '.')
		return (precision);

	precision = 0;

	for (curr_d += 1; format[curr_d] != '\0'; curr_d++)
	{
		if (is_digit(format[curr_d]))
		{
			precision *= 10;
			precision += format[curr_d] - '0';
		}
		else if (format[curr_d] == '*')
		{
			curr_d++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_d - 1;

	return (precision);
}
