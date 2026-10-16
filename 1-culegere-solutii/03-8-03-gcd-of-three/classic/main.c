/* CULEGERE III.8.3 - GCD OF THREE NUMBERS
 * THREE NATURAL NUMBERS ARE READ; PRINT THEIR GREATEST COMMON DIVISOR
 * EXAMPLE: 12 32 38 -> 2 */
#include <stdio.h> /* PRINTF, SCANF */

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
	int a = 0, b = 0, c = 0, g;

	printf("The 3 numbers: ");
	scanf("%d %d %d", &a, &b, &c);

	g = gcd(gcd(a, b), c); /* GCD(A, B, C) = GCD(GCD(A, B), C) */

	printf("%d\n", g);

	return 0;
}
