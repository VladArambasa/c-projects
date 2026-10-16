/* CULEGERE II.5.2 - ALL POSITIVE OR A SUM
 * READ THREE INTEGERS. IF ALL OF THEM ARE POSITIVE, PRINT THE BIGGER OF THE SECOND AND THE
 * THIRD; OTHERWISE PRINT THE SUM OF THE FIRST TWO
 * EXAMPLES: 45 23 100 -> 100; 34 -25 10 -> 9
 * ASSUMPTION: POSITIVE MEANS GREATER THAN 0 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int a = 0, b = 0, c = 0;

	printf("The three numbers: ");
	scanf("%d %d %d", &a, &b, &c);

	if (a > 0 && b > 0 && c > 0) /* ALL POSITIVE: THE BIGGER OF B AND C */
	{
		if (b > c)
		{
			printf("%d\n", b);
		}
		else
		{
			printf("%d\n", c);
		}
	}
	else
	{
		printf("%d\n", a + b);
	}

	return 0;
}
