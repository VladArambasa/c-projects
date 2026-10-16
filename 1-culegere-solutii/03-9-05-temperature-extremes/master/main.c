/* CULEGERE III.9.5 - LARGEST NEGATIVE AND SMALLEST POSITIVE TEMPERATURE
 * THE AVERAGE TEMPERATURES OF THE 12 MONTHS OF A YEAR ARE READ; PRINT THE LARGEST NEGATIVE
 * TEMPERATURE AND THE SMALLEST POSITIVE TEMPERATURE OF THAT YEAR
 * ASSUMPTION: THE TEMPERATURES ARE INTEGERS, AS IN THE EXAMPLE
 * EXAMPLE: -4 -6 0 5 10 20 24 25 17 8 -1 -7 -> MAX NEGATIVE=-1 MIN POSITIVE=5 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int t = 0, i;
	int max_neg = 0, count_neg = 0; /* THE LARGEST NEGATIVE IS THE ONE CLOSEST TO 0 */
	int min_pos = 0, count_pos = 0;

	printf("The 12 temperatures: ");
	for (i = 1; i <= 12; i++)
	{
		scanf("%d", &t);
		if (t < 0)
		{
			if (count_neg == 0 || t > max_neg) /* THE FIRST ONE, OR A LARGER ONE */
			{
				max_neg = t;
			}
			count_neg++;
		}
		else if (t > 0) /* 0 IS NEITHER NEGATIVE NOR POSITIVE */
		{
			if (count_pos == 0 || t < min_pos) /* THE FIRST ONE, OR A SMALLER ONE */
			{
				min_pos = t;
			}
			count_pos++;
		}
	}

	if (count_neg > 0)
	{
		printf("max negative=%d\n", max_neg);
	}
	else
	{
		printf("No negative temperatures\n");
	}

	if (count_pos > 0)
	{
		printf("min positive=%d\n", min_pos);
	}
	else
	{
		printf("No positive temperatures\n");
	}

	return 0;
}
