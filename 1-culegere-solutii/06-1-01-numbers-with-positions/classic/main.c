/* CULEGERE VI.1.1 - NUMBERS AND THEIR POSITIONS
 * READ 4 NUMBERS OF AT MOST 9 DIGITS; PRINT THEM ONE UNDER THE OTHER, EACH WITH ITS POSITION
 * EXAMPLE: 5 3 7 6 -> 5 POSITION 1 / 3 POSITION 2 / 7 POSITION 3 / 6 POSITION 4 */
#include <stdio.h> /* PRINTF, SCANF */

#define N 4 /* HOW MANY NUMBERS */

int main(void)
{
	int a[N] = {0}; /* 9 DIGITS STILL FIT IN AN INT */
	int i;

	printf("The %d numbers: ", N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}

	for (i = 0; i < N; i++)
	{
		printf("%d\tposition %d\n", a[i], i + 1); /* A[0] IS ON POSITION 1 */
	}

	return 0;
}
