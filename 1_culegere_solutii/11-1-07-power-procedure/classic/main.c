/* CULEGERE XI.1.7 - POWER WITH A PROCEDURE
 * READ TWO NUMBERS N AND K; PRINT N TO THE POWER K, COMPUTED BY A PROCEDURE
 * EXAMPLE: N=2 K=10 -> 2^10 = 1024
 * ASSUMPTION: K IS A NATURAL NUMBER AND THE RESULT FITS IN A LONG LONG */
#include <stdio.h> /* PRINTF, SCANF */

/* THE PROCEDURE: THE ANSWER GOES BACK THROUGH THE POINTER RESULT */
void power(int n, int k, long long *result)
{
	long long p = 1;
	int i;

	for (i = 1; i <= k; i++) /* K MULTIPLICATIONS BY N */
	{
		p = p * n;
	}
	*result = p;
}

int main(void)
{
	int n = 0, k = 0;
	long long result = 0;

	printf("n = ");
	scanf("%d", &n);
	printf("k = ");
	scanf("%d", &k);

	power(n, k, &result); /* &RESULT: THE PROCEDURE WRITES INTO THIS VARIABLE */
	if (n < 0) /* (-3)^2 = 9, WHILE -3^2 WOULD MEAN -(3^2) = -9 */
	{
		printf("(%d)^%d = %lld\n", n, k, result);
	}
	else
	{
		printf("%d^%d = %lld\n", n, k, result);
	}

	return 0;
}
