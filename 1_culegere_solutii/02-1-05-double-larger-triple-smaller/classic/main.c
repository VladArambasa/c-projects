/* CULEGERE II.1.5 - DOUBLE THE LARGER, TRIPLE THE SMALLER
 * READ TWO NUMBERS; MULTIPLY THE LARGER ONE BY 2 AND THE SMALLER ONE BY 3; PRINT THE RESULTS
 * EXAMPLE: 3 7 -> 9 14
 * ASSUMPTION: THE RESULTS ARE PRINTED IN THE ORDER THE NUMBERS WERE READ */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int a = 0, b = 0;

	printf("The two numbers: ");
	scanf("%d %d", &a, &b);

	if (a > b) /* A IS THE LARGER ONE */
	{
		a = a * 2;
		b = b * 3;
	}
	else /* B IS THE LARGER ONE (OR THEY ARE EQUAL) */
	{
		a = a * 3;
		b = b * 2;
	}

	printf("%d %d\n", a, b);

	return 0;
}
