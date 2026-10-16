/* CULEGERE III.1.2 - LIFT GOING DOWN
 * A LIFT GOES DOWN FROM FLOOR A TO FLOOR B; PRINT ALL THE FLOORS IT GOES THROUGH
 * EXAMPLE: 8 3 -> 8 7 6 5 4 3 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int a = 0, b = 0, i;

	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);

	/* GOING DOWN: THE FLOOR NUMBER DECREASES BY 1 AT EVERY STEP */
	for (i = a; i >= b; i--)
	{
		printf("%d ", i);
	}
	printf("\n");

	return 0;
}
