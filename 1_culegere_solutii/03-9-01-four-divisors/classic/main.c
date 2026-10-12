/* CULEGERE III.9.1 - NUMBERS WITH FOUR DIVISORS
 * PRINT ALL THE NUMBERS UP TO 100 THAT HAVE EXACTLY FOUR DIVISORS
 * OUTPUT: 6 8 10 14 15 21 22 26 27 ... 91 93 94 95 (6 HAS THE DIVISORS 1, 2, 3 AND 6) */
#include <stdio.h> /* PRINTF */

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
	int i;

	for (i = 1; i <= 100; i++)
	{
		if (count_divisors(i) == 4)
		{
			printf("%d ", i);
		}
	}
	printf("\n");

	return 0;
}
