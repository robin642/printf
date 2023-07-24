#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - It prints a char
 * @types: The list a of arguments
 * @buffer: The buffer array to handle print
 * @flags:  It calculates active flags
 * @width: The width
 * @precision: The precision specification
 * @size: The size specifier
 * Return: The number of chars printed
 */

int print_char(va_list types, char buffer[], int flags, int width, int precision, int size)

{
		char c = va_arg(types, int);

		return (handle_write_char(c, buffer, flags, width, precision, size));
}

/************************* PRINT A STRING *************************/
/**
 * print_string - It prints a string
 * @types: The list a of arguments
 * @buffer: The buffer array to handle print
 * @flags:  It calculates active flags
 * @width: The get width.
 * @precision: The precision specification
 * @size: The size specifier
 * Return: The number of chars printed
 */

int print_string(va_list types, char buffer[], int flags, int width, int precision, int size)

{
		int lengthz = 0, r;
		char *string = va_arg(types, char *);

		UNUSED(buffer);
		UNUSED(flags);
		UNUSED(width);
		UNUSED(precision);
		UNUSED(size);
		if (string == NULL)
		{
			string = "(null)";
			if (precision >= 6)
				string = "      ";      
		}

		while (string[lengthz] != '\0')
			lengthz++;

		if (precision >= 0 && precision < lengthz)
			lengthz = precision;

		if (width > lengthz)
		{
			if (flags & F_MINUS)
			{
				write(1, &string[0], lengthz);
				for (r = width - lengthz; r > 0; r--)
					write(1, " ", 1); 
				return (width);
			}
			else
			{
				for (r = width - lengthz; r > 0; r--)
					write(1, " ", 1);
				write(1, &string[0], lengthz);
				return (width);
			}
		}

		return (write(1, string, lengthz));

}

/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - It prints a percent sign
 * @types: The lista of arguments
 * @buffer: The buffer array to handle print
 * @flags:  It calculates active flags
 * @width: The get width.
 * @precision: The precision specification
 * @size: The size specifier
 * Return: The number of chars printed
 */

int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size)

{
		UNUSED(types);
		UNUSED(buffer);
		UNUSED(flags);
		UNUSED(width);
		UNUSED(precision);
		UNUSED(size);
		return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - The print int
 * @types: The lista of arguments
 * @buffer: The buffer array to handle print
 * @flags:  It calculates active flags
 * @width: The get width.
 * @precision: The precision specification
 * @size: The size specifier
 * Return: The number of chars printed
 */

int print_int(va_list types, char buffer[], int flags, int width, int precision, int size)

{
		int r = BUFF_SIZE - 2;
		int is_negativity = 0;
		long int w = va_arg(types, long int);
		unsigned long int number;

		w = convert_size_number(w, size);

		if (w == 0)
			buffer[r--] = '0';

		buffer[BUFF_SIZE - 1] = '\0';
		number = (unsigned long int)w;

		if (w < 0)
		{
			number = (unsigned long int)((-1) * w);
			is_negativity = 1;
		}

		while (number > 0)
		{
			buffer[r--] = (number % 10) + '0';
		}

		r++;

		return (write_number(is_negativity, r, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - It prints an unsigned number
 * @types: The lista of arguments
 * @buffer: The buffer array to handle print
 * @flags:  It calculates active flags
 * @width: The get width.
 * @precision: The precision specification
 * @size: The size specifier
 * Return: The numbers of char printed.
 */

int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size)

{
		unsigned int w, d, r, sums;
		unsigned int b[32];
		int counting;

		UNUSED(buffer);
		UNUSED(flags);
		UNUSED(width);
		UNUSED(precision);
		UNUSED(size);

		w = va_arg(types, unsigned int);
		d = 2147483648; /* (2 ^ 31) */
		b[0] = w / d;
		for (r = 1; r < 32; r++)
		{
			d /= 2;
			b[r] = (w / d) % 2;
		}
		for (r = 0, sums = 0, counting = 0; r < 32; r++)
		{
			sums += b[r];
			if (sums || r == 31)
			{
				char y = '0' + b[r];

				write(1, &y, 1);
				counting++;
			}
		}
		return (counting);
}

