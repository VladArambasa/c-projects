/* CULEGERE III.1.9 - SUMS OF CONSECUTIVE NUMBERS
 * FIND ALL THE WAYS TO WRITE A NATURAL NUMBER N AS A SUM OF CONSECUTIVE NUMBERS
 * ASSUMPTION: AT LEAST TWO TERMS, ALL OF THEM >= 1; WHEN THERE IS NO WAY, PRINT NOT POSSIBLE
 * EXAMPLE: 15 -> 15=1+2+3+4+5 15=4+5+6 15=7+8 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0, first, last, sum, i, found;

	printf("n = ");
	scanf("%d", &n);

	found = 0;
	/* TRY EVERY FIRST TERM; WITH AT LEAST TWO TERMS IT CANNOT BE BIGGER THAN N / 2 */
	for (first = 1; first <= n / 2; first++)
	{
		/* ADD FIRST, FIRST + 1, FIRST + 2, ... WHILE THE SUM IS SMALLER THAN N */
		sum = 0;
		last = first - 1;
		while (sum < n)
		{
			last++;
			sum = sum + last;
		}
		if (sum == n) /* THE SUM HIT N EXACTLY: PRINT FIRST + ... + LAST */
		{
			printf("%d=%d", n, first);
			for (i = first + 1; i <= last; i++)
			{
				printf("+%d", i);
			}
			printf("\n");
			found = 1;
		}
	}
	if (found == 0)
	{
		printf("Not possible\n");
	}

	return 0;
}
