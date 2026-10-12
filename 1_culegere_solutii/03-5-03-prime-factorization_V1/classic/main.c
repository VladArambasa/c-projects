/* CULEGERE III.5.3 - PRIME FACTORIZATION
 * PRINT THE DECOMPOSITION OF A NUMBER INTO PRIME FACTORS
 * ASSUMPTION: THE NUMBER IS AT LEAST 2 (1 HAS NO PRIME FACTORS)
 * EXAMPLE: 12 -> 12 = 2^2 3^1 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0, d, power;

	printf("Number: ");
	scanf("%d", &n);

	printf("%d =", n);
	d = 2;
	/* TRY D = 2, 3, 4, ... UNTIL NOTHING IS LEFT OF N; D = 4, 6, ... NEVER DIVIDE ANY MORE,
	 * BECAUSE THEIR PRIME FACTORS HAVE ALREADY BEEN TAKEN OUT */
	while (n > 1)
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
	printf("\n");

	return 0;
}
