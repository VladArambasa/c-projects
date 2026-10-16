/* CULEGERE XIII.2.10 - SUM OF FRACTIONS
 * N FRACTIONS A[I]/B[I] ARE GIVEN (1 <= N <= 5, 0 <= A[I] <= 255, 1 <= B[I] <= 8).
 * A) SIMPLIFY THE FRACTION ON POSITION K (K IS READ); B) ADD ALL THE FRACTIONS, THE RESULT BEING
 * THE IRREDUCIBLE FRACTION P/Q; C) PRINT WHAT PERCENT OF THE SUM P+Q THE NUMBER Q IS
 * EXAMPLE: 1/2 6/8 2/3 AND K=2 -> A) 3/4  B) 23/12  C) 34.29% */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 5

/* GREATEST COMMON DIVISOR (EUCLID) */
int gcd(int a, int b)
{
	int r;

	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main(void)
{
	int a[MAX + 1] = {0}, b[MAX + 1] = {0};
	int n = 0, k = 0, i, g;
	int p = 0, q = 1; /* THE SUM STARTS AS 0/1 */

	printf("n = ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		printf("Fraction %d (numerator denominator): ", i);
		scanf("%d %d", &a[i], &b[i]);
	}
	printf("k = ");
	scanf("%d", &k);

	/* A) DIVIDE BOTH TERMS BY THEIR GREATEST COMMON DIVISOR */
	g = gcd(a[k], b[k]);
	printf("a) %d/%d = %d/%d\n", a[k], b[k], a[k] / g, b[k] / g);

	/* B) P/Q + A/B = (P*B + A*Q) / (Q*B), SIMPLIFIED AT EVERY STEP SO THE NUMBERS STAY SMALL */
	for (i = 1; i <= n; i++)
	{
		p = p * b[i] + a[i] * q;
		q = q * b[i];
		g = gcd(p, q);
		p = p / g;
		q = q / g;
	}
	printf("b) p/q = %d/%d\n", p, q);

	/* C) Q OUT OF P+Q, AS A PERCENT */
	printf("c) q is %.2f%% of p+q\n", 100.0 * q / (p + q));

	return 0;
}
