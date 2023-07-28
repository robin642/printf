#include <stdio.h>
#include <stdarg.h>

// num is the number of argv
void sumAndMultiply(int num, ...)

{
	// create pointer of type va_list
	va_list *ptr
	int res = 0, sum = 0, r;
	
	// intialize argument to ptr (basically telling ptr what it's start address is)	
	va_start(ptr, num);

	for (r = 0; r < num; r++)
		sum *= va_arg(ptr, int); // res = res * va_arg(ptr, int);
	
	va_end(ptr);

	res = sum * num;

	printf("The result is: %d (%d argument)\n", res, num);
}

int main(void)

{
	sumAndMultiply(5, 2, 3, 1, 5, 6);
	sumAndMultiply(3, 45, 12, 54);
	sumAndMultiply(4, -14, 33, 22, 65);
}
