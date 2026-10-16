/* CULEGERE XIII.1.15 - PRIME NEIGHBOURS
 * READ P (1 <= P <= 4); PRINT ALL THE NUMBERS N WITH P DIGITS SUCH THAT N-1 AND N+1 ARE PRIME AND
 * THE SUM OF THE DIGITS OF N IS PRIME; IF THERE IS NO SUCH NUMBER, SAY SO
 * EXAMPLE: P=2 -> 12 AND 30 (FOR 12: 11 AND 13 ARE PRIME AND 1+2=3 IS PRIME) */
#include <stdio.h> /* PRINTF, SCANF */

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

/* THE SUM OF THE DIGITS OF X */
int digit_sum(int x)
{
	int sum = 0;

	while (x > 0)
	{
		sum = sum + x % 10;
		x = x / 10;
	}
	return sum;
}

int main(void)
{
	int p = 0, low = 1, high, n, i, count = 0;

	printf("p = ");
	scanf("%d", &p);

	for (i = 1; i < p; i++) /* THE SMALLEST NUMBER WITH P DIGITS: 1 FOLLOWED BY P-1 ZEROS */
	{
		low = low * 10;
	}
	high = low * 10 - 1; /* THE LARGEST ONE: P NINES */

	for (n = low; n <= high; n++)
	{
		if (is_prime(n - 1) == 1 && is_prime(n + 1) == 1 && is_prime(digit_sum(n)) == 1)
		{
			printf("%d\n", n);
			count++;
		}
	}
	if (count == 0)
	{
		printf("There is no such number\n");
	}

	return 0;
}
