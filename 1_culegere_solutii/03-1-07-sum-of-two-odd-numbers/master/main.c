/* CULEGERE III.1.7 - SUM OF TWO ODD NUMBERS
 * WRITE A NUMBER, IF POSSIBLE, AS A SUM OF TWO ODD NUMBERS, IN ALL THE POSSIBLE WAYS
 * EXAMPLES: 24 -> 24=1+23 24=3+21 24=5+19 24=7+17 24=9+15 24=11+13; 33 -> NOT POSSIBLE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0, i;

	printf("Number: ");
	scanf("%d", &n);

	/* ODD + ODD IS ALWAYS EVEN, AND THE SMALLEST SUCH SUM IS 1 + 1 = 2 */
	if (n % 2 != 0 || n < 2)
	{
		printf("Not possible\n");
	}
	else
	{
		/* THE FIRST NUMBER, I, TAKES THE ODD VALUES UP TO N / 2; THE SECOND ONE IS N - I */
		for (i = 1; i <= n / 2; i = i + 2)
		{
			printf("%d=%d+%d\n", n, i, n - i);
		}
	}

	return 0;
}
