/* CULEGERE III.5.2 - POWER OF A PRIME FACTOR
 * READ A NUMBER N AND A PRIME NUMBER K; PRINT THE POWER OF K IN THE PRIME FACTORIZATION OF N
 * EXAMPLE: N=12 K=2 -> 2 (BECAUSE 12 = 2^2 * 3) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0, k = 0, power;

	printf("n = ");
	scanf("%d", &n);
	printf("k = ");
	scanf("%d", &k);

	power = 0;
	/* DIVIDE N BY K AS LONG AS IT GOES AND COUNT THE DIVISIONS */
	while (n % k == 0)
	{
		n = n / k;
		power++;
	}
	printf("%d\n", power);

	return 0;
}
