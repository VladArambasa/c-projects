/* CULEGERE III.1.11 - PRIME NUMBER CHECK
 * READ A NUMBER AND CHECK WHETHER IT IS A PRIME NUMBER
 * EXAMPLES: 23 -> PRIME; 45 -> NOT PRIME */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0, d, prime;

	printf("Number: ");
	scanf("%d", &n);

	prime = 1; /* IT IS PRIME UNTIL A DIVISOR IS FOUND */
	if (n < 2)
	{
		prime = 0; /* 0 AND 1 ARE NOT PRIME */
	}
	/* TRY EVERY POSSIBLE DIVISOR FROM 2 TO N - 1 */
	for (d = 2; d < n; d++)
	{
		if (n % d == 0)
		{
			prime = 0;
		}
	}

	if (prime == 1)
	{
		printf("Prime\n");
	}
	else
	{
		printf("Not prime\n");
	}

	return 0;
}
