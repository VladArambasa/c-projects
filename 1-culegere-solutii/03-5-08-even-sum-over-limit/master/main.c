/* CULEGERE III.5.8 - EVEN SUM OVER A LIMIT
 * NATURAL NUMBERS ARE READ UNTIL THE SUM OF THE EVEN ONES IS GREATER THAN K. PRINT HOW MANY
 * NUMBERS WERE READ AND THE SUM OF THE EVEN ONES (CUPA MARTISOR 2005, BUCURESTI)
 * EXAMPLE: K=12, 5 8 1 2 2 3 6 -> 7 (NUMBERS) 18 (SUM OF THE EVEN ONES) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int k = 0, x = 0, count, sum;

	printf("k = ");
	scanf("%d", &k);
	printf("Numbers: ");

	count = 0; /* HOW MANY NUMBERS WERE READ */
	sum = 0; /* THE SUM OF THE EVEN NUMBERS */
	while (sum <= k && scanf("%d", &x) == 1) /* UNTIL THE EVEN SUM GOES ABOVE K OR THE INPUT ENDS */
	{
		count++;
		if (x % 2 == 0)
		{
			sum = sum + x;
		}
	}
	printf("%d (numbers) %d (sum of the even ones)\n", count, sum);

	return 0;
}
