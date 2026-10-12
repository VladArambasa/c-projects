/* CULEGERE X.6.10 - TRIANGLES OF MAXIMUM AREA
 * N POINTS (N >= 3, INTEGER COORDINATES < 50) ARE READ; PRINT THE COORDINATES OF THE THREE
 * POINTS OF EVERY TRIANGLE OF MAXIMUM AREA
 * EXAMPLE: (0 0) (4 0) (0 3) (1 1) -> MAXIMUM AREA = 6.0, THE TRIANGLE (0, 0) (4, 0) (0, 3)
 * ASSUMPTION: AT MOST 100 POINTS; IF ALL THE POINTS ARE ON ONE LINE, THERE IS NO TRIANGLE */
#include <stdio.h>  /* PRINTF, SCANF */
#include <stdlib.h> /* ABS */

#define MAX 100

int x[MAX], y[MAX];

/* TWICE THE AREA OF THE TRIANGLE OF POINTS I, J, K: A WHOLE NUMBER, SO NO ROUNDING */
int twice_area(int i, int j, int k)
{
	return abs((x[j] - x[i]) * (y[k] - y[i]) - (x[k] - x[i]) * (y[j] - y[i]));
}

int main(void)
{
	int n = 0, i, j, k, max = 0;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d points (x y): ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &x[i], &y[i]);
	}

	/* FIRST PASS: THE MAXIMUM AREA OVER ALL GROUPS OF THREE POINTS */
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			for (k = j + 1; k < n; k++)
			{
				if (twice_area(i, j, k) > max)
				{
					max = twice_area(i, j, k);
				}
			}
		}
	}

	if (max == 0)
	{
		printf("All the points are on one line: there is no triangle\n");
	}
	else
	{
		printf("Maximum area = %.1f\n", max / 2.0);
		/* SECOND PASS: PRINT EVERY TRIANGLE WITH THAT AREA */
		for (i = 0; i < n; i++)
		{
			for (j = i + 1; j < n; j++)
			{
				for (k = j + 1; k < n; k++)
				{
					if (twice_area(i, j, k) == max)
					{
						printf("(%d, %d) (%d, %d) (%d, %d)\n",
						       x[i], y[i], x[j], y[j], x[k], y[k]);
					}
				}
			}
		}
	}

	return 0;
}
