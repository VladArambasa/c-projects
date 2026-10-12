/* CULEGERE III.9.4 - EXPONENT OF K IN 1*2*...*N (V2)
 * A NATURAL NUMBER N <= 100 AND A DIGIT K FROM {2, 3, 5, 7} ARE READ; PRINT THE EXPONENT OF K
 * IN THE PRIME FACTORIZATION OF THE PRODUCT 1*2*3*...*N
 * V2: LEGENDRE'S FORMULA N/K + N/(K*K) + N/(K*K*K) + ..., ONLY A FEW STEPS INSTEAD OF N
 * EXAMPLE: N=8 K=2 -> 7 (8/2 + 8/4 + 8/8 = 4 + 2 + 1) */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0, k = 0;
	int power;
	int exponent = 0;

	printf("n = ");
	scanf("%d", &n);
	printf("k = ");
	scanf("%d", &k);

	/* FROM 1 TO N, N / K NUMBERS ARE MULTIPLES OF K AND GIVE ONE K EACH; N / (K*K) OF THEM
	 * ARE MULTIPLES OF K*K AND GIVE A SECOND K; N / (K*K*K) GIVE A THIRD ONE, AND SO ON */
	power = k;
	while (power <= n)
	{
		exponent = exponent + n / power;
		power = power * k; /* K, K*K, K*K*K, ... */
	}

	printf("%d\n", exponent);

	return 0;
}
