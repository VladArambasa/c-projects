/* CULEGERE III.6.2 - AVERAGE POSITIVE AND NEGATIVE TEMPERATURE
 * THE AVERAGE TEMPERATURES OF THE 12 MONTHS OF A YEAR ARE READ AS INTEGERS; PRINT, WITH TWO
 * DECIMALS, THE AVERAGE OF THE POSITIVE TEMPERATURES AND THE AVERAGE OF THE NEGATIVE ONES
 * EXAMPLE: -5 -3 1 8 12 17 20 21 18 10 6 -2 -> MEAN_POS=12.56 MEAN_NEG=-3.33
 * NOTE: THE BOOK'S EXAMPLE SAYS MEDIE_POZ=13.66; THE CORRECT RESULT IS 113 / 9 = 12.56 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int t = 0, i;
	int sum_pos = 0, count_pos = 0; /* POSITIVE TEMPERATURES: THEIR SUM AND HOW MANY */
	int sum_neg = 0, count_neg = 0; /* NEGATIVE TEMPERATURES: THEIR SUM AND HOW MANY */

	printf("The 12 temperatures: ");
	for (i = 1; i <= 12; i++)
	{
		scanf("%d", &t);
		if (t > 0)
		{
			sum_pos = sum_pos + t;
			count_pos++;
		}
		else if (t < 0) /* 0 IS NEITHER POSITIVE NOR NEGATIVE, SO IT IS SKIPPED */
		{
			sum_neg = sum_neg + t;
			count_neg++;
		}
	}

	/* (DOUBLE) MAKES THE DIVISION REAL: 113 / 9 BETWEEN TWO INTS WOULD GIVE ONLY 12 */
	if (count_pos > 0)
	{
		printf("mean_pos=%.2f\n", (double)sum_pos / count_pos);
	}
	else
	{
		printf("No positive temperatures\n");
	}

	if (count_neg > 0)
	{
		printf("mean_neg=%.2f\n", (double)sum_neg / count_neg);
	}
	else
	{
		printf("No negative temperatures\n");
	}

	return 0;
}
