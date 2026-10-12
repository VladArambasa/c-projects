/* CULEGERE III.3.4 - LETTER SUBTRACTION PUZZLE
 * REPLACE THE LETTERS WITH DIGITS IN THE SUBTRACTION   ABCBE - EDAB = EBCE
 * DIFFERENT LETTERS ARE DIFFERENT DIGITS AND NO NUMBER STARTS WITH 0; PRINT EVERY SOLUTION
 * EXAMPLE: NO INPUT -> A=1 B=0 C=9 D=8 E=5: 10905 - 5810 = 5095 */
#include <stdio.h> /* PRINTF */

/* RETURNS 1 WHEN THE FIVE DIGITS ARE ALL DIFFERENT */
int all_different(int a, int b, int c, int d, int e)
{
	if (a == b || a == c || a == d || a == e)
	{
		return 0;
	}
	if (b == c || b == d || b == e)
	{
		return 0;
	}
	if (c == d || c == e || d == e)
	{
		return 0;
	}
	return 1;
}

/* TRIES ONE CHOICE OF DIGITS: IF THE DIGITS ARE ALL DIFFERENT AND ABCBE - EDAB = EBCE,
 * IT PRINTS THE SOLUTION AND RETURNS 1; OTHERWISE IT RETURNS 0 */
int try_digits(int a, int b, int c, int d, int e)
{
	int x, y, z;

	if (all_different(a, b, c, d, e) == 0)
	{
		return 0;
	}
	x = a * 10000 + b * 1000 + c * 100 + b * 10 + e; /* ABCBE */
	y = e * 1000 + d * 100 + a * 10 + b; /* EDAB */
	z = e * 1000 + b * 100 + c * 10 + e; /* EBCE */
	if (x - y != z)
	{
		return 0;
	}
	printf("a=%d b=%d c=%d d=%d e=%d: %d - %d = %d\n", a, b, c, d, e, x, y, z);
	return 1;
}

int main(void)
{
	int a, b, c, d, e, count;

	count = 0; /* HOW MANY SOLUTIONS WERE FOUND */
	/* ONE LOOP FOR EVERY LETTER; A AND E START NUMBERS, SO THEY CANNOT BE 0 */
	for (a = 1; a <= 9; a++)
	{
		for (b = 0; b <= 9; b++)
		{
			for (c = 0; c <= 9; c++)
			{
				for (d = 0; d <= 9; d++)
				{
					for (e = 1; e <= 9; e++)
					{
						if (try_digits(a, b, c, d, e) == 1)
						{
							count++;
						}
					}
				}
			}
		}
	}
	if (count == 0)
	{
		printf("No solution\n");
	}

	return 0;
}
