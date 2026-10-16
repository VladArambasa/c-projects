/* CULEGERE III.4.4 - SUM OF THE EVEN NUMBERS
 * NUMBERS ARE READ UNTIL AN ODD NUMBER DIVISIBLE BY 3 IS TYPED;
 * PRINT THE SUM OF ALL THE EVEN NUMBERS THAT WERE READ
 * EXAMPLE: 7 4 6 2 1 9 -> 12 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int x = 0, sum;

	printf("Numbers (an odd multiple of 3 stops): ");
	sum = 0;
	while (scanf("%d", &x) == 1) /* ALSO STOPS IF THE INPUT ENDS */
	{
		if (x % 2 == 0)
		{
			sum = sum + x;
		}
		else if (x % 3 == 0) /* ODD AND DIVISIBLE BY 3: THE STOP NUMBER */
		{
			break;
		}
	}
	printf("%d\n", sum);

	return 0;
}
