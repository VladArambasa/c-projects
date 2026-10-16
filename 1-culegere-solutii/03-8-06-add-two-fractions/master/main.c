/* CULEGERE III.8.6 - SUM OF TWO FRACTIONS
 * FOUR NON-ZERO INTEGERS ARE READ: THE NUMERATOR AND THE DENOMINATOR OF THE FIRST FRACTION,
 * THEN THOSE OF THE SECOND; ADD THE TWO FRACTIONS AND PRINT THE NUMERATOR AND THE DENOMINATOR
 * OF THE SUM
 * ASSUMPTION: THE SUM IS SIMPLIFIED (AS IN THE EXAMPLE) AND ITS DENOMINATOR IS MADE POSITIVE
 * EXAMPLE: 6 18 12 24 -> 5 6 (6/18 + 12/24 = 1/3 + 1/2 = 5/6) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int gcd(int a, int b) /* EUCLID'S ALGORITHM, ALSO FOR NEGATIVE NUMBERS */
{
	int r;

	if (a < 0) /* THE SIGNS DO NOT CHANGE THE GCD */
	{
		a = -a;
	}
	if (b < 0)
	{
		b = -b;
	}
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
	int a = 0, b = 0, c = 0, d = 0;
	int num, den, g;

	printf("First fraction (numerator denominator): ");
	scanf("%d %d", &a, &b);
	printf("Second fraction (numerator denominator): ");
	scanf("%d %d", &c, &d);

	/* A/B + C/D = (A*D + C*B) / (B*D): BOTH FRACTIONS GET THE DENOMINATOR B*D */
	num = a * d + c * b;
	den = b * d;

	g = gcd(num, den); /* SIMPLIFY BY THE GCD */
	num = num / g;
	den = den / g;

	if (den < 0) /* KEEP THE MINUS SIGN ON THE NUMERATOR: 1/-6 BECOMES -1/6 */
	{
		num = -num;
		den = -den;
	}

	printf("%d %d\n", num, den);

	return 0;
}
