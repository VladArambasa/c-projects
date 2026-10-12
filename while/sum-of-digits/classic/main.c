/* SUM OF THE DIGITS OF A NUMBER */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0;
	int sum = 0;

	printf("Enter a number: ");
	scanf("%d", &n);

	if (n < 0)
	{
		n = -n; /* THE SIGN DOES NOT MATTER */
	}

	while (n > 0)
	{
		sum = sum + n % 10; /* LAST DIGIT */
		n = n / 10;         /* DROP IT */
	}

	printf("Sum of digits = %d\n", sum);

	return 0;
}
