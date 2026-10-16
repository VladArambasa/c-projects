/* CULEGERE III.5.3 - PRIME FACTORIZATION
 * PRINT THE DECOMPOSITION OF A NUMBER INTO PRIME FACTORS
 * ASSUMPTION: THE NUMBER IS AT LEAST 2 (1 HAS NO PRIME FACTORS)
 * IMPROVEMENT: D STOPS AT THE SQUARE ROOT OF WHAT IS LEFT; ANYTHING LEFT AFTER THAT IS PRIME
 * EXAMPLE: 12 -> 12 = 2^2 3^1 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0, d, power;

	printf("Number: ");
	scanf("%d", &n);

	printf("%d =", n);
	d = 2;
	/* WHILE D * D <= N, N MAY STILL HAVE A FACTOR D OR BIGGER;
	 * D <= N / D MEANS THE SAME, BUT D * D COULD GET TOO BIG FOR AN INT */
	while (d <= n / d)
	{
		power = 0;
		while (n % d == 0) /* TAKE D OUT AS MANY TIMES AS POSSIBLE */
		{
			n = n / d;
			power++;
		}
		if (power > 0)
		{
			printf(" %d^%d", d, power);
		}
		d++;
	}
	/* A NUMBER WITH NO DIVISOR UP TO ITS SQUARE ROOT IS PRIME: IT IS THE LAST FACTOR */
	if (n > 1)
	{
		printf(" %d^1", n);
	}
	printf("\n");

	return 0;
}
