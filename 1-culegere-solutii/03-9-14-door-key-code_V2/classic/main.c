/* CULEGERE III.9.14 - THE KEY TO THE DOOR (V2)
 * FOR THE NUMBER WRITTEN ON THE DOOR, FIND THE SUM OF ITS DIVISORS. IF THAT SUM IS PRIME, THE KEY
 * IS THE SUM OF THE DIGITS OF THE NUMBER; OTHERWISE IT IS THE SUM OF ITS ODD DIGITS
 * ASSUMPTION: THE NUMBER IS A NON-ZERO NATURAL NUMBER WITH AT MOST 9 DIGITS
 * V2: DIVISORS COME IN PAIRS (D AND N / D), SO D ONLY GOES UP TO THE SQUARE ROOT OF N
 * EXAMPLES: 472 -> KEY 7 (THE DIVISORS ADD UP TO 900, NOT PRIME; THE ODD DIGITS: 7);
 *           4 -> KEY 4 (1 + 2 + 4 = 7, PRIME; THE DIGITS: 4) */
#include <stdio.h> /* PRINTF, SCANF */

int is_prime(long long x) /* 1 IF X IS PRIME, 0 OTHERWISE */
{
	long long d;

	if (x < 2)
	{
		return 0;
	}
	for (d = 2; d * d <= x; d++) /* A DIVISOR ABOVE THE SQUARE ROOT HAS A PARTNER BELOW IT */
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
	int n = 0, d, copy, digit;
	long long sum = 0; /* THE SUM OF THE DIVISORS CAN BE BIGGER THAN THE INT LIMIT */
	int sum_digits = 0, sum_odd = 0;

	printf("Number on the door: ");
	scanf("%d", &n);

	for (d = 1; d * d <= n; d++) /* N HAS AT MOST 9 DIGITS, SO D * D STAYS INSIDE AN INT */
	{
		if (n % d == 0)
		{
			sum = sum + d;
			if (d != n / d) /* ITS PARTNER N / D, UNLESS IT IS D ITSELF (N = D * D) */
			{
				sum = sum + n / d;
			}
		}
	}

	copy = n; /* THE DIGITS: ALL OF THEM, AND ONLY THE ODD ONES */
	while (copy > 0)
	{
		digit = copy % 10;
		sum_digits = sum_digits + digit;
		if (digit % 2 == 1)
		{
			sum_odd = sum_odd + digit;
		}
		copy = copy / 10;
	}

	if (is_prime(sum) == 1)
	{
		printf("key %d\n", sum_digits);
	}
	else
	{
		printf("key %d\n", sum_odd);
	}

	return 0;
}
