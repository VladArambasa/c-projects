/* CULEGERE III.9.6 - DIGIT PYRAMID
 * A NATURAL NUMBER N WITH AT MOST 9 DIGITS IS READ; PRINT A PYRAMID OF ITS DIGITS: THE MIDDLE
 * DIGIT (OR THE TWO MIDDLE DIGITS) ON THE FIRST LINE, THE 3 (OR 4) MIDDLE DIGITS ON THE SECOND
 * LINE, AND SO ON, WITH THE WHOLE NUMBER ON THE LAST LINE
 * EXAMPLE: 237855 ->     7 8
 *                      3 7 8 5
 *                    2 3 7 8 5 5 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 9 /* AT MOST 9 DIGITS */

int main(void)
{
	int digit[MAX] = {0};
	int n = 0, len = 0, lines, line, side, i;

	printf("n = ");
	scanf("%d", &n);

	/* DIGIT[0] GETS THE LAST DIGIT, DIGIT[LEN - 1] THE FIRST ONE */
	do
	{
		digit[len] = n % 10;
		len++;
		n = n / 10;
	} while (n > 0);

	lines = (len + 1) / 2; /* EVERY LINE HAS ONE MORE DIGIT ON EACH SIDE THAN THE ONE ABOVE */
	for (line = 1; line <= lines; line++)
	{
		side = lines - line; /* HOW MANY DIGITS ARE LEFT OUT ON EACH SIDE OF THIS LINE */
		for (i = 1; i <= side; i++)
		{
			printf("  "); /* A LEFT-OUT DIGIT AND ITS SPACE: 2 COLUMNS */
		}
		/* LEFT TO RIGHT IN THE NUMBER IS FROM THE END OF THE ARRAY BACKWARDS */
		for (i = len - 1 - side; i >= side; i--)
		{
			printf("%d ", digit[i]);
		}
		printf("\n");
	}

	return 0;
}
