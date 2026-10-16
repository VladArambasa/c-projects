/* CULEGERE III.7.3 - EVEN DIGITS
 * HOW MANY EVEN DIGITS DOES A GIVEN NATURAL NUMBER HAVE?
 * EXAMPLE: 34425346 -> 5 EVEN DIGITS
 * NOTE: THE BOOK'S EXAMPLE SAYS 4 DIGITS; THE CORRECT RESULT IS 5 (4, 4, 2, 4 AND 6) */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0, digit;
	int count = 0;

	printf("n = ");
	scanf("%d", &n);

	do /* DO-WHILE: THE NUMBER 0 HAS ONE DIGIT, AND IT IS EVEN */
	{
		digit = n % 10; /* THE LAST DIGIT */
		if (digit % 2 == 0)
		{
			count++;
		}
		n = n / 10; /* CUT IT OFF AND GO ON WITH THE REST */
	} while (n > 0);

	printf("%d even %s\n", count, (count == 1) ? "digit" : "digits");

	return 0;
}
