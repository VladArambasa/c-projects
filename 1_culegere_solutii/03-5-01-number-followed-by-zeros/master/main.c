/* CULEGERE III.5.1 - NUMBER FOLLOWED BY ZEROS
 * READ A AND N AND PRINT THE NUMBER A FOLLOWED BY N ZEROS
 * EXAMPLE: A=34 N=5 -> 3400000 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int a = 0, n = 0, i;

	printf("a = ");
	scanf("%d", &a);
	printf("n = ");
	scanf("%d", &n);

	printf("%d", a);
	/* THE SAME ACTION, PRINTING ONE 0, IS REPEATED N TIMES */
	for (i = 1; i <= n; i++)
	{
		printf("0");
	}
	printf("\n");

	return 0;
}
