/* CULEGERE III.1.10 - DIVISORS OF A NUMBER
 * PRINT ALL THE DIVISORS OF A NATURAL NUMBER
 * IMPROVEMENT: SEARCH ONLY UP TO THE SQUARE ROOT; EVERY SMALL DIVISOR D GIVES A BIG ONE, N / D
 * EXAMPLE: 12 -> 1 2 3 4 6 12 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0, d;

	printf("Number: ");
	scanf("%d", &n);

	/* THE SMALL DIVISORS: THOSE WITH D * D <= N, WRITTEN AS D <= N / D SO THAT
	 * D * D CANNOT GET TOO BIG FOR AN INT WHEN N IS CLOSE TO THE INT LIMIT */
	for (d = 1; d <= n / d; d++)
	{
		if (n % d == 0)
		{
			printf("%d ", d);
		}
	}
	/* THE BIG DIVISORS ARE N / D: D GOES BACK DOWN FROM WHERE THE FIRST LOOP STOPPED,
	 * SO THEY COME OUT IN INCREASING ORDER */
	for (d = d - 1; d >= 1; d--)
	{
		if (n % d == 0 && d * d != n) /* THE SQUARE ROOT OF N WAS ALREADY PRINTED */
		{
			printf("%d ", n / d);
		}
	}
	printf("\n");

	return 0;
}
