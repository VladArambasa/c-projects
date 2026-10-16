/* CULEGERE XIII.1.12 - PRIMES IN THE MIDDLE (V2)
 * LIST THE PRIMES OF THE INTERVAL [1, N]; IF THEIR COUNT IS EVEN, PRINT THE 2*K PRIMES IN THE
 * MIDDLE OF THE LIST, IF IT IS ODD, THE 2*K-1 PRIMES IN THE MIDDLE; IF THERE ARE FEWER PRIMES
 * THAN THAT, PRINT THEM ALL (1 <= N <= 10000, 1 <= K <= 30, K < N)
 * EXAMPLE: N=21 K=2 -> 5 7 11 13 (THE PRIMES ARE 2 3 5 7 11 13 17 19)
 * V2: SIEVE OF ERATOSTHENES: CROSS OUT THE MULTIPLES OF EVERY PRIME, NO DIVISIONS AT ALL */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAXN 10000 /* LARGEST N */
#define MAXP 1229  /* THERE ARE 1229 PRIMES UP TO 10000 */

int main(void)
{
	int crossed[MAXN + 1]; /* CROSSED[X] = 1 WHEN X IS A MULTIPLE OF A SMALLER PRIME */
	int primes[MAXP + 1];  /* PRIMES[1..M], IN INCREASING ORDER */
	int n = 0, k = 0, m = 0, x, j, i, want, first, last, middle;

	printf("n = ");
	scanf("%d", &n);
	printf("k = ");
	scanf("%d", &k);

	for (x = 2; x <= n; x++)
	{
		crossed[x] = 0;
	}
	for (x = 2; x * x <= n; x++)
	{
		if (crossed[x] == 0) /* X IS PRIME: CROSS OUT ITS MULTIPLES */
		{
			/* FROM X * X: SMALLER MULTIPLES ARE CROSSED OUT ALREADY */
			for (j = x * x; j <= n; j = j + x)
			{
				crossed[j] = 1;
			}
		}
	}
	for (x = 2; x <= n; x++) /* WHAT STAYS UNCROSSED IS PRIME */
	{
		if (crossed[x] == 0)
		{
			m++;
			primes[m] = x;
		}
	}

	if (m % 2 == 0)
	{
		want = 2 * k;
	}
	else
	{
		want = 2 * k - 1;
	}

	if (want > m) /* NOT ENOUGH PRIMES: ALL OF THEM */
	{
		first = 1;
		last = m;
	}
	else if (m % 2 == 0) /* EVEN COUNT: K PRIMES ON EACH SIDE OF THE MIDDLE */
	{
		first = m / 2 - k + 1;
		last = m / 2 + k;
	}
	else /* ODD COUNT: THE MIDDLE PRIME AND K - 1 PRIMES ON EACH SIDE OF IT */
	{
		middle = (m + 1) / 2;
		first = middle - k + 1;
		last = middle + k - 1;
	}

	printf("Primes in the middle:");
	for (i = first; i <= last; i++)
	{
		printf(" %d", primes[i]);
	}
	printf("\n");

	return 0;
}
