#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>
#include "main.h"

 int _printf(const char *format, ...)

{
		  int r = 0;
            int *length = 0; 
            int amount = 0;

            va_list list;

            va_start(list, *format);

            while (*format)
            {
                if (*format == '%')
                {
                    if (*format != '\0')
                    break;
                    format++;
                switch (*format)
                {
                case 'c':
                     printf("%s%c", va_arg(list, int));
                     amount++;
                    break;
                case 'i':
                     printf("%s%d", va_arg(list, int));
                     amount++;
                    break;
                case 'f':
                     printf("%s%f", va_arg(list, double));
                     amount++;
                    break;
                case 's':
                    *length = va_arg(list, int);
                    printf("%s%s", length);
                    amount++;
                    break;
                
                default:
                        r++;
                        continue;

                }
                
                
            }
            format++;
        }
        va_end(list);
        return amount;
        
}
