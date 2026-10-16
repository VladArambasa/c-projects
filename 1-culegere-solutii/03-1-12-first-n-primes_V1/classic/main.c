/* CULEGERE III.1.12 - FIRST N PRIME NUMBERS
 * PRINT THE FIRST N PRIME NUMBERS
 * EXAMPLE: N=6 -> 2 3 5 7 11 13 */
#include <stdio.h> /* PRINTF, SCANF */

/* RETURNS 1 IF X IS PRIME: IT HAS NO DIVISOR FROM 2 TO X - 1 */
int is_prime(int x)
{
	int d;

	if (x < 2)
	{
		return 0;
	}
	for (d = 2; d < x; d++)
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
	int n = 0, count, x;

	printf("n = ");
	scanf("%d", &n);

	count = 0; /* HOW MANY PRIMES HAVE BEEN PRINTED SO FAR */
	x = 2;
	/* CHECK THE NUMBERS 2, 3, 4, ... ONE BY ONE UNTIL N PRIMES ARE FOUND */
	while (count < n)
	{
		if (is_prime(x) == 1)
		{
			printf("%d ", x);
			count++;
		}
		x++;
	}
	printf("\n");

	return 0;
}
