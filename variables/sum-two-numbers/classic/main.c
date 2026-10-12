/* SUM OF TWO NUMBERS */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int a = 0, b = 0;

	printf("Enter two numbers: ");
	scanf("%d %d", &a, &b);

	printf("Sum = %d\n", a + b);

	return 0;
}
