/* CULEGERE III.3.3 - INCREASING DIGITS WITH SUM 18
 * LIST THE NUMBERS FROM 100 TO 599 WITH THE DIGITS IN INCREASING ORDER AND THE DIGIT SUM 18
 * ASSUMPTION: INCREASING MEANS STRICTLY INCREASING (EVERY DIGIT IS BIGGER THAN THE ONE BEFORE IT)
 * EXAMPLE: NO INPUT -> 189 279 369 378 459 468 567 */
#include <stdio.h> /* PRINTF */

int main(void)
{
	int a, b, c;

	/* A, B, C ARE THE HUNDREDS, TENS AND UNITS DIGITS */
	for (a = 1; a <= 5; a++) /* THE NUMBER IS BETWEEN 100 AND 599 */
	{
		for (b = a + 1; b <= 9; b++) /* EACH DIGIT STARTS ABOVE THE DIGIT BEFORE IT */
		{
			for (c = b + 1; c <= 9; c++)
			{
				if (a + b + c == 18)
				{
					printf("%d ", a * 100 + b * 10 + c);
				}
			}
		}
	}
	printf("\n");

	return 0;
}
