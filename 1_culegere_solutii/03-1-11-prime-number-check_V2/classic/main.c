/* CULEGERE III.1.11 - PRIME NUMBER CHECK
 * READ A NUMBER AND CHECK WHETHER IT IS A PRIME NUMBER
 * IMPROVEMENT: TRY DIVISORS ONLY UP TO THE SQUARE ROOT AND STOP AT THE FIRST ONE FOUND
 * EXAMPLES: 23 -> PRIME; 45 -> NOT PRIME */
#include <stdio.h> /* PRINTF, SCANF */

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
	/* A DIVISOR ABOVE THE SQUARE ROOT HAS A PARTNER BELOW IT (45 = 5 * 9),
	 * SO IT IS ENOUGH TO TRY D WHILE D * D <= N; STOP AS SOON AS A DIVISOR IS FOUND.
	 * D <= N / D MEANS THE SAME AS D * D <= N, BUT D * D COULD GET TOO BIG FOR AN INT */
	for (d = 2; d <= n / d && prime == 1; d++)
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
