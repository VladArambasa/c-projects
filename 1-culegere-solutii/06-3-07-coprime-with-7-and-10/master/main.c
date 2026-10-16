/* CULEGERE VI.3.7 - COPRIME WITH 7 AND WITH 10
 * N NATURAL NUMBERS ARE GIVEN. HOW MANY ARE COPRIME WITH 7? AND HOW MANY WITH 10?
 * (TWO NUMBERS ARE COPRIME WHEN THEIR GREATEST COMMON DIVISOR IS 1)
 * EXAMPLE: N=6, 5 7 14 20 12 15 -> COPRIME WITH 7: 4,  COPRIME WITH 10: 1 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100

/* GREATEST COMMON DIVISOR, EUCLID'S ALGORITHM WITH REMAINDERS */
int gcd(int a, int b)
{
	int r;

	while (b != 0) /* THE PAIR (A, B) BECOMES (B, A % B) UNTIL B IS 0 */
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main(void)
{
	int x[MAX] = {0};
	int n = 0, i;
	int count7 = 0, count10 = 0;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
	}

	for (i = 0; i < n; i++)
	{
		if (gcd(x[i], 7) == 1) /* NO COMMON DIVISOR EXCEPT 1 */
		{
			count7++;
		}
		if (gcd(x[i], 10) == 1)
		{
			count10++;
		}
	}

	printf("coprime with 7: %d,  coprime with 10: %d\n", count7, count10);

	return 0;
}
