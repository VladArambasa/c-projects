/* CULEGERE III.9.2 - MOST DIVISORS BELOW 1000 (V2)
 * WHICH OF THE NUMBERS SMALLER THAN 1000 HAVE THE MOST DIVISORS?
 * V2: DIVISORS COME IN PAIRS (D AND X / D), SO D ONLY GOES UP TO THE SQUARE ROOT OF X
 * OUTPUT: 840 IS THE ONLY ONE, WITH 32 DIVISORS */
#include <stdio.h> /* PRINTF */

int count_divisors(int x) /* COUNTS THE DIVISORS IN PAIRS: D AND X / D */
{
	int d, count = 0;

	for (d = 1; d * d <= x; d++) /* D * D <= X MEANS D <= SQUARE ROOT OF X */
	{
		if (x % d == 0)
		{
			if (d * d == x) /* D AND X / D ARE THE SAME NUMBER: COUNT IT ONCE */
			{
				count++;
			}
			else
			{
				count = count + 2; /* D AND ITS PARTNER X / D */
			}
		}
	}
	return count;
}

int main(void)
{
	int i, count;
	int max = 0;

	for (i = 1; i < 1000; i++) /* FIRST PASS: THE LARGEST NUMBER OF DIVISORS */
	{
		count = count_divisors(i);
		if (count > max)
		{
			max = count;
		}
	}

	/* SECOND PASS: EVERY NUMBER WITH THAT MANY DIVISORS (THERE COULD BE SEVERAL) */
	printf("Numbers with the most divisors (%d):", max);
	for (i = 1; i < 1000; i++)
	{
		if (count_divisors(i) == max)
		{
			printf(" %d", i);
		}
	}
	printf("\n");

	return 0;
}
