/* CULEGERE XIII.1.10 - PRIME, COUNT AND INSERT
 * A IS A SEQUENCE OF N NATURAL NUMBERS (8 <= N <= 256) AND P IS A NATURAL NUMBER
 * A) SAY WHETHER P IS PRIME
 * B) PRINT HOW MANY TIMES P APPEARS IN A AND ON WHICH POSITIONS
 * C) IF P DOES NOT APPEAR IN A, INSERT IT ON POSITION K (1 <= K <= N, READ FROM THE KEYBOARD),
 *    MOVING THE ELEMENTS FROM POSITION K ONWARD ONE PLACE TO THE RIGHT
 * EXAMPLE: A = 4 7 10 7 3 15 7 2, P=7 -> A) 7 IS PRIME  B) 3 TIMES, ON POSITIONS 2 4 7
 *          SAME A, P=9, K=3 -> A) 9 IS NOT PRIME  B) 0 TIMES  C) 4 7 9 10 7 3 15 7 2 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 256

/* 1 IF X IS PRIME, 0 OTHERWISE */
int is_prime(int x)
{
	int d;

	if (x < 2)
	{
		return 0;
	}
	for (d = 2; d * d <= x; d++) /* A DIVISOR, IF ANY, SHOWS UP BY THE SQUARE ROOT */
	{
		if (x % d == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main(void)
{
	int a[MAX + 2]; /* POSITIONS 1..N, PLUS ONE PLACE FOR THE INSERTED NUMBER */
	int n = 0, p = 0, k = 0, i, count = 0;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("p = ");
	scanf("%d", &p);

	if (is_prime(p) == 1) /* A) */
	{
		printf("a) %d is prime\n", p);
	}
	else
	{
		printf("a) %d is not prime\n", p);
	}

	for (i = 1; i <= n; i++) /* B) COUNT FIRST, THEN SHOW THE POSITIONS */
	{
		if (a[i] == p)
		{
			count++;
		}
	}
	printf("b) occurrences: %d", count);
	if (count > 0)
	{
		printf(", positions:");
		for (i = 1; i <= n; i++)
		{
			if (a[i] == p)
			{
				printf(" %d", i);
			}
		}
	}
	printf("\n");

	if (count == 0) /* C) */
	{
		printf("k = ");
		scanf("%d", &k);
		/* FROM THE END DOWN TO K, EVERY ELEMENT MOVES ONE PLACE TO THE RIGHT */
		for (i = n; i >= k; i--)
		{
			a[i + 1] = a[i];
		}
		a[k] = p;
		n++;

		printf("c)");
		for (i = 1; i <= n; i++)
		{
			printf(" %d", a[i]);
		}
		printf("\n");
	}

	return 0;
}
