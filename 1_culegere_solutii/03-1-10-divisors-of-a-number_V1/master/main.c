/* CULEGERE III.1.10 - DIVISORS OF A NUMBER
 * PRINT ALL THE DIVISORS OF A NATURAL NUMBER
 * EXAMPLE: 12 -> 1 2 3 4 6 12 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0, d;

	printf("Number: ");
	scanf("%d", &n);

	/* TRY EVERY NUMBER FROM 1 TO N */
	for (d = 1; d <= n; d++)
	{
		if (n % d == 0)
		{
			printf("%d ", d);
		}
	}
	printf("\n");

	return 0;
}
