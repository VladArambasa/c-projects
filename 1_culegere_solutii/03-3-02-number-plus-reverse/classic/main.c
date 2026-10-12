/* CULEGERE III.3.2 - NUMBER PLUS ITS REVERSE
 * PRINT ALL THE TWO-DIGIT NUMBERS THAT GIVE 55 WHEN ADDED TO THEIR REVERSE (14 + 41 = 55)
 * ASSUMPTION: THE REVERSE OF 50 IS 05 = 5, SO 50 COUNTS TOO (50 + 5 = 55)
 * EXAMPLE: NO INPUT -> 14 23 32 41 50 */
#include <stdio.h> /* PRINTF */

int main(void)
{
	int a, b, number, reverse;

	/* A IS THE TENS DIGIT (NOT 0), B IS THE UNITS DIGIT */
	for (a = 1; a <= 9; a++)
	{
		for (b = 0; b <= 9; b++)
		{
			number = a * 10 + b;
			reverse = b * 10 + a; /* THE SAME DIGITS IN THE OPPOSITE ORDER */
			if (number + reverse == 55)
			{
				printf("%d ", number);
			}
		}
	}
	printf("\n");

	return 0;
}
