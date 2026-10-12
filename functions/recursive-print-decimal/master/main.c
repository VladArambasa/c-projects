/* PRINT A NUMBER DIGIT BY DIGIT WITH RECURSION: FIRST THE LEADING DIGITS, THEN THE LAST ONE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

void print_decimal(int n)
{
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	if (n / 10 != 0) /* MORE THAN ONE DIGIT: PRINT THE OTHERS FIRST */
	{
		print_decimal(n / 10);
	}
	putchar(n % 10 + '0'); /* DIGIT TO CHARACTER: 7 + '0' IS '7' */
}

int main(void)
{
	int n = 0;

	printf("Enter a number: ");
	scanf("%d", &n);

	print_decimal(n);
	putchar('\n');

	return 0;
}
