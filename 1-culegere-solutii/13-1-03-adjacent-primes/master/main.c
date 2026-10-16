/* CULEGERE XIII.1.3 - FIRST TWO NEIGHBOURING PRIMES
 * AMONG N INTEGERS (N <= 20), PRINT THE FIRST TWO PRIME NUMBERS THAT STAND NEXT TO EACH OTHER;
 * IF THERE ARE NONE, PRINT "NO SOLUTION"
 * EXAMPLE: 1 18 41 13 9 7 5 -> 41 13;  2 8 7 2 5 4 -> 7 2;  4 12 8 5 4 -> NO SOLUTION */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 20

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
	int a[MAX];
	int n = 0, i, found = 0;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	/* CHECK EVERY PAIR OF NEIGHBOURS FROM LEFT TO RIGHT AND STOP AT THE FIRST GOOD ONE */
	for (i = 0; i + 1 < n && found == 0; i++)
	{
		if (is_prime(a[i]) == 1 && is_prime(a[i + 1]) == 1)
		{
			printf("%d %d\n", a[i], a[i + 1]);
			found = 1;
		}
	}
	if (found == 0)
	{
		printf("No solution\n");
	}

	return 0;
}
