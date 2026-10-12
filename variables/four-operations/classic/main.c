/* SUM, DIFFERENCE, PRODUCT AND QUOTIENT OF TWO NUMBERS */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int a = 0, b = 0;

	printf("Enter two numbers: ");
	scanf("%d %d", &a, &b);

	printf("Sum = %d\n", a + b);
	printf("Difference = %d\n", a - b);
	printf("Product = %d\n", a * b);

	if (b != 0) /* DIVISION BY ZERO IS NOT ALLOWED */
	{
		printf("Quotient = %d\n", a / b);
	}
	else
	{
		printf("Quotient = cannot divide by zero\n");
	}

	return 0;
}
