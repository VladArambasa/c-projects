/* CULEGERE III.7.5 - ZEROS AT THE END
 * IN HOW MANY ZEROS DOES A NATURAL NUMBER WITH AT MOST 9 DIGITS END?
 * ASSUMPTION: THE NUMBER 0 IS WRITTEN WITH ONE ZERO, SO IT ENDS IN 1 ZERO
 * EXAMPLE: 20034000 -> 3 ZEROS */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0;
	int zeros = 0;

	printf("n = ");
	scanf("%d", &n);

	if (n == 0) /* SPECIAL CASE: 0 / 10 IS STILL 0, SO THE LOOP BELOW WOULD NEVER END */
	{
		zeros = 1;
	}
	else
	{
		while (n % 10 == 0) /* THE LAST DIGIT IS 0 */
		{
			zeros++;
			n = n / 10; /* CUT IT OFF */
		}
	}

	printf("%d %s\n", zeros, (zeros == 1) ? "zero" : "zeros");

	return 0;
}
