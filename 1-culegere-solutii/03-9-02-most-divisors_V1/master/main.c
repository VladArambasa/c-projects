/* CULEGERE III.9.2 - MOST DIVISORS BELOW 1000 (V1)
 * WHICH OF THE NUMBERS SMALLER THAN 1000 HAVE THE MOST DIVISORS?
 * V1: COUNT THE DIVISORS OF EVERY NUMBER BY TRYING ALL D FROM 1 TO THE NUMBER
 * OUTPUT: 840 IS THE ONLY ONE, WITH 32 DIVISORS */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int count_divisors(int x) /* TRY EVERY D FROM 1 TO X */
{
	int d, count = 0;

	for (d = 1; d <= x; d++)
	{
		if (x % d == 0) /* D DIVIDES X EXACTLY */
		{
			count++;
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
