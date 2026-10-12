/* CULEGERE VI.7.3 - FIBONACCI VECTOR
 * BUILD THE VECTOR OF THE FIRST N TERMS OF THE FIBONACCI SEQUENCE
 * 0, 1, 1, 2, 3, 5, 8, 13, 21, ... WHERE F[1] = 0, F[2] = 1 AND F[I] = F[I - 1] + F[I - 2]
 * ASSUMPTION: N <= 93, SO EVERY TERM FITS IN A LONG LONG
 * EXAMPLE (NOT IN THE BOOK): N=10 -> 0 1 1 2 3 5 8 13 21 34 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 93 /* F[94] WOULD NOT FIT IN A LONG LONG ANY MORE */

int main(void)
{
	long long f[MAX + 1]; /* LONG LONG: THE TERMS GROW VERY FAST; F[0] IS NOT USED */
	int n = 0, i;

	printf("n = ");
	scanf("%d", &n);

	f[1] = 0;
	f[2] = 1;
	for (i = 3; i <= n; i++) /* EVERY TERM IS THE SUM OF THE TWO TERMS BEFORE IT */
	{
		f[i] = f[i - 1] + f[i - 2];
	}

	for (i = 1; i <= n; i++)
	{
		printf("%lld ", f[i]); /* %LLD PRINTS A LONG LONG */
	}
	printf("\n");

	return 0;
}
