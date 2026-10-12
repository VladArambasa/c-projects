/* CULEGERE VI.6.6 - ARITHMETIC PROGRESSION
 * CHECK IF A SEQUENCE OF N REAL NUMBERS IS AN ARITHMETIC PROGRESSION: THE DIFFERENCE BETWEEN ANY
 * TWO NEIGHBOURS IS THE SAME (FOR EXAMPLE 1, 4, 7, 10, 13)
 * EXAMPLE: N=5, 1 4 7 10 13 -> YES */
#include <stdio.h> /* PRINTF, SCANF */
#include <math.h>  /* FABS */

#define MAX 100      /* AT MOST 100 NUMBERS */
#define EPS 0.000001 /* REAL NUMBERS ARE STORED APPROXIMATELY: CLOSER THAN EPS COUNTS AS EQUAL */

int main(void)
{
	double a[MAX];
	int n = 0, i, ok;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%lf", &a[i]);
	}

	ok = 1; /* A PROGRESSION, UNTIL A DIFFERENT DIFFERENCE IS FOUND */
	for (i = 2; i < n; i++)
	{
		/* EVERY DIFFERENCE MUST BE EQUAL TO THE FIRST ONE, A[1] - A[0] */
		if (fabs((a[i] - a[i - 1]) - (a[1] - a[0])) > EPS)
		{
			ok = 0;
		}
	}

	if (ok == 1)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}

	return 0;
}
