/* CULEGERE III.3.1 - TRIPLETS WITH SUM DIVISIBLE BY 10
 * PRINT ALL THE TRIPLETS OF NUMBERS A, B, C WITH 1 < A < B < C < 100 AND A + B + C DIVISIBLE BY 10
 * EXAMPLE: NO INPUT -> 2 3 5, 2 3 15, 2 3 25, ..., 95 97 98 (15209 TRIPLETS) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int a, b, c, count;

	count = 0;
	/* EACH LOOP STARTS RIGHT AFTER THE NUMBER OF THE OUTER LOOP, SO A < B < C ALWAYS HOLDS */
	for (a = 2; a < 100; a++)
	{
		for (b = a + 1; b < 100; b++)
		{
			for (c = b + 1; c < 100; c++)
			{
				if ((a + b + c) % 10 == 0)
				{
					printf("%d %d %d\n", a, b, c);
					count++;
				}
			}
		}
	}
	printf("Total: %d triplets\n", count);

	return 0;
}
