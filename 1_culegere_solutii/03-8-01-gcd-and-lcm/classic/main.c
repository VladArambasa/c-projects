/* CULEGERE III.8.1 - GCD AND LCM
 * TWO NON-ZERO NATURAL NUMBERS ARE READ; PRINT THEIR GREATEST COMMON DIVISOR (GCD)
 * AND THEIR LEAST COMMON MULTIPLE (LCM)
 * EXAMPLE: 12 32 -> GCD=4 LCM=96 */
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
	int a = 0, b = 0, g;
	long long lcm; /* THE LCM CAN BE MUCH BIGGER THAN A AND B */

	printf("The 2 numbers: ");
	scanf("%d %d", &a, &b);

	g = gcd(a, b);
	lcm = (long long)a / g * b; /* A * B = GCD * LCM; DIVIDING FIRST KEEPS NUMBERS SMALL */

	printf("gcd=%d lcm=%lld\n", g, lcm);

	return 0;
}
