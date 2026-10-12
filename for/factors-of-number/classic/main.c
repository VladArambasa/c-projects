/* ALL FACTORS (DIVISORS) OF A NUMBER */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0, i;

	printf("Enter a number: ");
	scanf("%d", &n);

	printf("Factors of %d:", n);
	for (i = 1; i <= n; i++)
	{
		if (n % i == 0) /* I DIVIDES N EXACTLY */
		{
			printf(" %d", i);
		}
	}
	printf("\n");

	return 0;
}
