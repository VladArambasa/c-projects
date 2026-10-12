/* CULEGERE III.9.11 - PAGES WITH PICTURES (V2)
 * A BOOK HAS N PAGES; THE PAGES WHOSE NUMBER IS DIVISIBLE BY K BUT NOT BY H HAVE PICTURES.
 * READ N, K, H AND PRINT THE LAST DIGIT OF THE SUM OF THE NUMBERS OF THE PAGES WITH PICTURES,
 * OR IMPOSSIBLE! IF NO PAGE HAS A PICTURE. LIMITS: 0 < N <= 1000000000, 0 < K, H <= N
 * V2: NO LOOP OVER THE PAGES: SUM OF THE MULTIPLES OF K MINUS SUM OF THE MULTIPLES OF LCM(K, H)
 * EXAMPLE: N=20 K=3 H=2 -> 7 (PAGES 3, 9 AND 15; 3 + 9 + 15 = 27) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

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
	int n = 0, k = 0, h = 0;
	long long m, lcm, q, sum; /* LONG LONG: THE SUMS GO UP TO ABOUT 5 * 10^17 */

	printf("N = ");
	scanf("%d", &n);
	printf("K = ");
	scanf("%d", &k);
	printf("H = ");
	scanf("%d", &h);

	m = n / k;                          /* PAGES K, 2K, ..., MK ARE THE MULTIPLES OF K */
	lcm = (long long)k / gcd(k, h) * h; /* DIVISIBLE BY K AND H = MULTIPLE OF LCM(K, H) */
	q = n / lcm;                        /* PAGES LCM, 2LCM, ..., Q*LCM ARE DIVISIBLE BY BOTH */

	if (m == q) /* EVERY MULTIPLE OF K IS ALSO DIVISIBLE BY H: NO PICTURES */
	{
		printf("Impossible!\n");
	}
	else
	{
		/* K + 2K + ... + MK = K * (1 + 2 + ... + M) = K * M * (M + 1) / 2;
		 * THE SAME FORMULA WITH LCM AND Q GIVES THE PAGES TO TAKE AWAY */
		sum = k * m * (m + 1) / 2 - lcm * q * (q + 1) / 2;
		printf("%lld\n", sum % 10);
	}

	return 0;
}
