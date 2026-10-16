/* CULEGERE VI.1.2 - EVEN NUMBERS, THEN ODD NUMBERS
 * A SEQUENCE OF 10 NATURAL NUMBERS IS GIVEN; PRINT THE EVEN ONES ON THE FIRST ROW AND THE ODD
 * ONES ON THE SECOND ROW
 * EXAMPLE: 4 3 2 5 6 8 9 0 1 5 -> 4 2 6 8 0 / 3 5 9 1 5 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define N 10 /* HOW MANY NUMBERS */

int main(void)
{
	int a[N] = {0};
	int i;

	printf("The %d numbers: ", N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}

	for (i = 0; i < N; i++) /* FIRST ROW: THE EVEN NUMBERS */
	{
		if (a[i] % 2 == 0)
		{
			printf("%d ", a[i]);
		}
	}
	printf("\n");

	for (i = 0; i < N; i++) /* SECOND ROW: THE ODD NUMBERS */
	{
		if (a[i] % 2 == 1)
		{
			printf("%d ", a[i]);
		}
	}
	printf("\n");

	return 0;
}
