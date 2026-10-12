/* CULEGERE II.3.5 - T-SHIRT COLOR
 * THE FIRST 100 CONTESTANTS GET T-SHIRTS IN THE ORDER WHITE, RED, BLUE, BLACK, WHITE, RED ...
 * IONEL IS IN PLACE X: PRINT THE COLOR OF HIS T-SHIRT
 * EXAMPLE: X=38 -> RED */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int x = 0, r;

	printf("x = ");
	scanf("%d", &x);

	r = x % 4; /* THE 4 COLORS REPEAT, SO ONLY THE REMAINDER BY 4 MATTERS */

	if (r == 1)
	{
		printf("white\n");
	}
	else if (r == 2)
	{
		printf("red\n");
	}
	else if (r == 3)
	{
		printf("blue\n");
	}
	else
	{
		printf("black\n"); /* REMAINDER 0: THE 4TH COLOR */
	}

	return 0;
}
