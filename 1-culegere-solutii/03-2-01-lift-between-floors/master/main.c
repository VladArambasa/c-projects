/* CULEGERE III.2.1 - LIFT BETWEEN TWO FLOORS
 * A LIFT TRAVELS FROM FLOOR A TO FLOOR B; PRINT ALL THE FLOORS IN THE ORDER IT REACHES THEM
 * EXAMPLES: A=4 B=7 -> 4 5 6 7; A=10 B=8 -> 10 9 8 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int a = 0, b = 0, i;

	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);

	/* THE ORDER MATTERS HERE, SO A AND B ARE NOT SWAPPED: THE LOOP COUNTS UP OR DOWN */
	if (a <= b)
	{
		for (i = a; i <= b; i++) /* THE LIFT GOES UP */
		{
			printf("%d ", i);
		}
	}
	else
	{
		for (i = a; i >= b; i--) /* THE LIFT GOES DOWN */
		{
			printf("%d ", i);
		}
	}
	printf("\n");

	return 0;
}
