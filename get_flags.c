#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */

int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int w, curr_d;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_d = *i + 1; format[curr_d] != '\0'; curr_d++)
	{
		for (w = 0; FLAGS_CH[w] != '\0'; w++)
			if (format[curr_d] == FLAGS_CH[w])
			{
				flags |= FLAGS_ARR[w];
				break;
			}

		if (FLAGS_CH[w] == 0)
			break;
	}

	*i = curr_d - 1;

	return (flags);
}
