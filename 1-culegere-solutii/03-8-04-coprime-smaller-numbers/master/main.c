/* CULEGERE III.8.4 - COPRIME NUMBERS SMALLER THAN N
 * PRINT ALL THE NUMBERS SMALLER THAN N THAT ARE COPRIME WITH N (THEIR GCD WITH N IS 1)
 * EXAMPLE: N=10 -> 1 3 7 9 */
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
	int n = 0, i;
	int count = 0;

	printf("n = ");
	scanf("%d", &n);

	for (i = 1; i < n; i++)
	{
		if (gcd(i, n) == 1) /* NO COMMON DIVISOR EXCEPT 1 */
		{
			printf("%d ", i);
			count++;
		}
	}
	if (count == 0)
	{
		printf("None");
	}
	printf("\n");

	return 0;
}
