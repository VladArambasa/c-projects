/* CULEGERE III.9.4 - EXPONENT OF K IN 1*2*...*N (V1)
 * A NATURAL NUMBER N <= 100 AND A DIGIT K FROM {2, 3, 5, 7} ARE READ; PRINT THE EXPONENT OF K
 * IN THE PRIME FACTORIZATION OF THE PRODUCT 1*2*3*...*N
 * V1: TAKE EVERY FACTOR FROM 1 TO N AND COUNT HOW MANY TIMES IT CAN BE DIVIDED BY K
 * EXAMPLE: N=8 K=2 -> 7 (1*2*...*8 = 40320 = 2^7 * 315) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0, k = 0, i, x;
	int exponent = 0;

	printf("n = ");
	scanf("%d", &n);
	printf("k = ");
	scanf("%d", &k);

	for (i = 1; i <= n; i++)
	{
		x = i;
		while (x % k == 0) /* EVERY DIVISION BY K IS ONE MORE K IN THE PRODUCT */
		{
			exponent++;
			x = x / k;
		}
	}

	printf("%d\n", exponent);

	return 0;
}
