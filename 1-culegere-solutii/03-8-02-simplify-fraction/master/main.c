/* CULEGERE III.8.2 - SIMPLIFY A FRACTION
 * THE NUMERATOR AND THE DENOMINATOR OF A FRACTION ARE READ; SIMPLIFY IT, IF POSSIBLE,
 * AND PRINT THE SIMPLIFIED FRACTION
 * ASSUMPTION: THE NUMERATOR IS READ FIRST, AS THE EXAMPLE SHOWS (12 32 -> 3/8)
 * EXAMPLE: 12 32 -> 3/8 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int gcd(int a, int b) /* EUCLID'S ALGORITHM */
{
	int r;

	while (b != 0)
	{
		r = a % b; /* REPLACE (A, B) WITH (B, A % B) */
		a = b;
		b = r;
	}
	return a; /* WHEN THE REMAINDER IS 0, A IS THE GCD */
}

int main(void)
{
	int num = 0, den = 0, g;

	printf("Numerator: ");
	scanf("%d", &num);
	printf("Denominator: ");
	scanf("%d", &den);

	g = gcd(num, den);
	if (g == 1) /* NO COMMON DIVISOR BIGGER THAN 1 */
	{
		printf("%d/%d cannot be simplified\n", num, den);
	}
	else
	{
		printf("%d/%d\n", num / g, den / g); /* DIVIDE BOTH BY THE GCD: THE SHORTEST FORM */
	}

	return 0;
}
