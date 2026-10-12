/* CULEGERE III.7.12 - LAST DIGIT OF A SUM (V1)
 * TWO NUMBERS A < B < 5000000 ARE READ; PRINT THE LAST DIGIT OF THE SUM OF ALL THE NUMBERS
 * BETWEEN A AND B
 * ASSUMPTION: A AND B ARE PART OF THE SUM, AS THE EXAMPLE SHOWS (12 + 13 + 14 = 39)
 * V1: ADD THE NUMBERS ONE BY ONE, KEEPING ONLY THE LAST DIGIT OF THE SUM
 * EXAMPLES: A=12 B=14 -> 9; A=1000000 B=3000000 -> 0 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int a = 0, b = 0, i;
	int last = 0; /* THE LAST DIGIT OF THE SUM SO FAR */

	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);

	for (i = a; i <= b; i++)
	{
		/* THE LAST DIGIT OF A SUM DEPENDS ONLY ON THE LAST DIGITS OF THE NUMBERS ADDED,
		 * SO THE WHOLE SUM (TOO BIG FOR AN INT) IS NEVER NEEDED */
		last = (last + i % 10) % 10;
	}

	printf("%d\n", last);

	return 0;
}
