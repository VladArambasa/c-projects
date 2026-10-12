/* VARIABLE NUMBER OF ARGUMENTS: THE FIRST ONE TELLS HOW MANY FOLLOW */
#include <stdio.h>  /* PRINTF */
#include <stdarg.h> /* VA_LIST, VA_START, VA_ARG, VA_END */

int add(int n, ...) /* THE THREE DOTS MEAN: MORE ARGUMENTS MAY FOLLOW */
{
	va_list args;
	int i;
	int sum = 0;

	va_start(args, n); /* START RIGHT AFTER THE LAST NAMED PARAMETER */
	for (i = 0; i < n; i++)
	{
		sum = sum + va_arg(args, int); /* TAKE THE NEXT ARGUMENT AS AN INT */
	}
	va_end(args); /* ALWAYS CLOSE WHAT VA_START OPENED */

	return sum;
}

int main(void)
{
	printf("add(3, -5, 27, 12) = %d\n", add(3, -5, 27, 12));
	printf("add(2, 257, -25)   = %d\n", add(2, 257, -25));
	printf("add(0)             = %d\n", add(0));

	return 0;
}
