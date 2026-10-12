/* CULEGERE II.1.3 - SCORES IN DESCENDING ORDER
 * READ THE SCORES OF TWO ATHLETES AND PRINT THEM IN DESCENDING ORDER
 * EXAMPLE: 100 134 -> 134 POINTS  100 POINTS */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int a = 0, b = 0;

	printf("The two scores: ");
	scanf("%d %d", &a, &b);

	if (a >= b) /* THE BIGGER SCORE IS PRINTED FIRST */
	{
		printf("%d points  %d points\n", a, b);
	}
	else
	{
		printf("%d points  %d points\n", b, a);
	}

	return 0;
}
