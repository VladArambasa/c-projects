/* CULEGERE VI.7.9 - COPRIME NUMBERS BELOW N
 * A NUMBER N IS READ; STORE IN A VECTOR ALL THE NUMBERS SMALLER THAN N THAT ARE COPRIME WITH N
 * (THEIR GREATEST COMMON DIVISOR WITH N IS 1), THEN PRINT THEM IN DESCENDING ORDER
 * NOTE: THE BOOK'S EXAMPLE SAYS 9 7 3; THE CORRECT RESULT IS 9 7 3 1
 * (1 IS COPRIME WITH EVERY NUMBER)
 * EXAMPLE: N=10 -> 9 7 3 1 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 10000 /* N <= 10000 */

/* GREATEST COMMON DIVISOR, WITH EUCLID'S ALGORITHM */
int gcd(int a, int b)
{
	int r;

	while (b != 0) /* (A, B) BECOMES (B, A % B) UNTIL B IS 0 */
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main(void)
{
	int v[MAX];
	int n = 0, m, i;

	printf("n = ");
	scanf("%d", &n);

	m = 0; /* HOW MANY NUMBERS THE VECTOR HOLDS */
	for (i = 1; i < n; i++)
	{
		if (gcd(n, i) == 1) /* COPRIME: THEIR ONLY COMMON DIVISOR IS 1 */
		{
			v[m] = i;
			m++;
		}
	}

	/* THE VECTOR WAS FILLED IN ASCENDING ORDER, SO PRINT IT FROM THE END */
	for (i = m - 1; i >= 0; i--)
	{
		printf("%d ", v[i]);
	}
	printf("\n");

	return 0;
}
