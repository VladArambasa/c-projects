/* CULEGERE II.4.1 - MAXIMUM AND MINIMUM OF THREE
 * READ THREE DIFFERENT NUMBERS AND PRINT THE LARGEST AND THE SMALLEST
 * EXAMPLE: 45 34 78 -> MAX=78 MIN=34 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int a = 0, b = 0, c = 0, max, min;

	printf("The three numbers: ");
	scanf("%d %d %d", &a, &b, &c);

	/* THE LARGEST IS BIGGER THAN BOTH OTHERS */
	if (a > b && a > c)
	{
		max = a;
	}
	else if (b > a && b > c)
	{
		max = b;
	}
	else
	{
		max = c;
	}

	/* THE SMALLEST IS SMALLER THAN BOTH OTHERS */
	if (a < b && a < c)
	{
		min = a;
	}
	else if (b < a && b < c)
	{
		min = b;
	}
	else
	{
		min = c;
	}

	printf("max=%d min=%d\n", max, min);

	return 0;
}
