/* CULEGERE III.7.2 - DIGITS: HOW MANY, LARGEST, SMALLEST, SUM
 * A NATURAL NUMBER WITH AT MOST 9 DIGITS IS READ; PRINT HOW MANY DIGITS IT HAS, ITS LARGEST
 * DIGIT AND THE SUM OF ALL ITS DIGITS
 * ASSUMPTION: THE SMALLEST DIGIT IS PRINTED TOO, AS IN THE EXAMPLE
 * EXAMPLE: 24356103 -> 8 DIGITS MAX=6 MIN=0 SUM=24 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0, digit;
	int count = 0, sum = 0;
	int max = 0; /* NO DIGIT IS SMALLER THAN 0 */
	int min = 9; /* NO DIGIT IS LARGER THAN 9 */

	printf("n = ");
	scanf("%d", &n);

	do /* DO-WHILE, SO THAT THE NUMBER 0 STILL HAS ONE DIGIT */
	{
		digit = n % 10; /* THE LAST DIGIT */
		count++;
		sum = sum + digit;
		if (digit > max)
		{
			max = digit;
		}
		if (digit < min)
		{
			min = digit;
		}
		n = n / 10; /* CUT OFF THE LAST DIGIT */
	} while (n > 0);

	printf("%d %s max=%d min=%d sum=%d\n",
	       count, (count == 1) ? "digit" : "digits", max, min, sum);

	return 0;
}
