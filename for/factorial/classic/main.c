/* FACTORIAL: N! = 1 * 2 * 3 * ... * N */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0, i;
	long long fact = 1; /* 20! STILL FITS IN A LONG LONG */

	printf("Enter n: ");
	scanf("%d", &n);

	if (n < 0)
	{
		printf("Factorial is not defined for negative numbers\n");
		return 1;
	}
	if (n > 20) /* 21! DOES NOT FIT IN A LONG LONG */
	{
		printf("n is too large (at most 20)\n");
		return 1;
	}

	for (i = 2; i <= n; i++)
	{
		fact = fact * i;
	}

	printf("%d! = %lld\n", n, fact);

	return 0;
}
