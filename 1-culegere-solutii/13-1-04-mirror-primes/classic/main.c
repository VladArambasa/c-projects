/* CULEGERE XIII.1.4 - PRIMES WITH A PRIME MIRROR
 * FOR A NATURAL NUMBER N (N < 100), PRINT ALL THE PRIMES UP TO N WHOSE MIRROR (THE NUMBER WRITTEN
 * BACKWARDS) IS PRIME TOO
 * EXAMPLE: N=20 -> 2 3 5 7 11 13 17
 *   (13 -> 31 AND 17 -> 71 ARE PRIME, BUT 19 -> 91 = 7 * 13 IS NOT) */
#include <stdio.h> /* PRINTF, SCANF */

/* 1 IF X IS PRIME, 0 OTHERWISE */
int is_prime(int x)
{
	int d;

	if (x < 2)
	{
		return 0;
	}
	for (d = 2; d * d <= x; d++) /* A DIVISOR, IF ANY, SHOWS UP BY THE SQUARE ROOT */
	{
		if (x % d == 0)
		{
			return 0;
		}
	}
	return 1;
}

/* THE NUMBER WRITTEN BACKWARDS: 17 -> 71 */
int mirror(int x)
{
	int m = 0;

	while (x > 0)
	{
		m = m * 10 + x % 10; /* THE LAST DIGIT OF X IS ADDED AT THE END OF M */
		x = x / 10;
	}
	return m;
}

int main(void)
{
	int n = 0, x, found = 0;

	printf("n = ");
	scanf("%d", &n);

	printf("Primes with a prime mirror:");
	for (x = 2; x <= n; x++)
	{
		if (is_prime(x) == 1 && is_prime(mirror(x)) == 1)
		{
			printf(" %d", x);
			found = 1;
		}
	}
	if (found == 0)
	{
		printf(" none");
	}
	printf("\n");

	return 0;
}
