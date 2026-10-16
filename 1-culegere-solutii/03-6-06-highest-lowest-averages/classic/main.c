/* CULEGERE III.6.6 - HIGHEST AND LOWEST AVERAGE
 * THE AVERAGES OF N PUPILS ARE READ AS REAL NUMBERS; PRINT THE HIGHEST AND THE LOWEST AVERAGE
 * AND CHECK WHETHER SOME PUPILS FAIL
 * ASSUMPTION: A PUPIL FAILS ("CORIGENT") WITH AN AVERAGE BELOW 5; THE FAILING PUPILS ARE COUNTED
 * EXAMPLE: N=4: 9.50 4.25 9.66 6.33 -> MAX=9.66 MIN=4.25, 1 FAILING PUPIL */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0, i;
	int failing = 0;
	double x = 0;
	double max = 0;  /* SMALLER THAN ANY AVERAGE (AVERAGES GO FROM 1 TO 10) */
	double min = 10; /* NO AVERAGE IS LARGER THAN 10 */

	printf("n = ");
	scanf("%d", &n);

	printf("The %d averages: ", n);
	for (i = 1; i <= n; i++)
	{
		scanf("%lf", &x);
		if (x > max)
		{
			max = x;
		}
		if (x < min)
		{
			min = x;
		}
		if (x < 5) /* BELOW 5: THE PUPIL FAILS */
		{
			failing++;
		}
	}

	printf("max=%.2f min=%.2f\n", max, min);
	if (failing == 0)
	{
		printf("No failing pupils\n");
	}
	else
	{
		printf("%d failing %s\n", failing, (failing == 1) ? "pupil" : "pupils");
	}

	return 0;
}
