/* CULEGERE III.7.9 - HOW MANY TIMES EACH DIGIT APPEARS
 * AN INTEGER WITH AT MOST 9 DIGITS IS READ; PRINT HOW MANY TIMES EACH DIGIT FROM 0 TO 9
 * APPEARS IN IT
 * EXAMPLE: 364901211 -> 0 APPEARS 1 TIME, 1 APPEARS 3 TIMES, 2 APPEARS 1 TIME, ...,
 *          5 APPEARS 0 TIMES, ..., 9 APPEARS 1 TIME */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0, d;
	int count[10] = {0}; /* COUNT[D] = HOW MANY TIMES DIGIT D APPEARS, ALL 0 AT THE START */

	printf("n = ");
	scanf("%d", &n);

	if (n < 0) /* THE MINUS SIGN IS NOT A DIGIT */
	{
		n = -n;
	}

	do /* DO-WHILE: FOR THE NUMBER 0, THE DIGIT 0 IS COUNTED ONCE */
	{
		count[n % 10]++; /* THE LAST DIGIT SAYS WHICH COUNTER GROWS */
		n = n / 10;
	} while (n > 0);

	for (d = 0; d <= 9; d++)
	{
		printf("%d appears %d %s\n", d, count[d], (count[d] == 1) ? "time" : "times");
	}

	return 0;
}
