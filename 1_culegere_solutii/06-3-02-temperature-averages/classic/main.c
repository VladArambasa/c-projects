/* CULEGERE VI.3.2 - AVERAGE TEMPERATURES
 * THE TEMPERATURES MEASURED IN N DAYS ARE READ; PRINT THE AVERAGE OF THE NEGATIVE TEMPERATURES
 * AND THE AVERAGE OF THE POSITIVE ONES
 * EXAMPLE: N=5, 23 24 23 25 22 -> NO NEGATIVE TEMPERATURES / 23.40
 * ASSUMPTION: 0 DEGREES IS NEITHER NEGATIVE NOR POSITIVE; WHEN ONE KIND OF TEMPERATURE IS
 * MISSING, A MESSAGE IS PRINTED INSTEAD OF ITS AVERAGE */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100

int main(void)
{
	double t[MAX] = {0};
	double sneg = 0, spos = 0;
	int n = 0, i, cneg = 0, cpos = 0;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d temperatures: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%lf", &t[i]); /* %LF READS A REAL NUMBER, SO 21.5 IS ALSO ACCEPTED */
	}

	for (i = 0; i < n; i++) /* A SUM AND A COUNTER FOR EACH KIND */
	{
		if (t[i] < 0)
		{
			sneg = sneg + t[i];
			cneg++;
		}
		else if (t[i] > 0)
		{
			spos = spos + t[i];
			cpos++;
		}
	}

	if (cneg > 0) /* AN AVERAGE NEEDS AT LEAST ONE TEMPERATURE */
	{
		/* AVERAGE = SUM / COUNT; %.2F KEEPS TWO DECIMALS, AS IN 23.40 */
		printf("Average of the negative temperatures: %.2f\n", sneg / cneg);
	}
	else
	{
		printf("No negative temperatures\n");
	}
	if (cpos > 0)
	{
		printf("Average of the positive temperatures: %.2f\n", spos / cpos);
	}
	else
	{
		printf("No positive temperatures\n");
	}

	return 0;
}
