/* CULEGERE VII.2.3 - SUMS ON THE TWO DIAGONALS (VERSION 1)
 * AN N X N MATRIX IS READ; PRINT THE SUM OF THE ELEMENTS ON THE MAIN DIAGONAL AND THE SUM OF
 * THE ELEMENTS ON THE SECONDARY DIAGONAL
 * EXAMPLE: N=3, 1 2 3 / 4 5 6 / 7 8 10 -> 16 AND 15
 * ASSUMPTION: TWO SEPARATE SUMS ARE PRINTED, ONE FOR EACH DIAGONAL
 * VERSION 1: THE WHOLE MATRIX IS TRAVERSED AND EVERY ELEMENT IS TESTED (N*N STEPS) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 50 /* AT MOST 50 ROWS AND 50 COLUMNS */

int main(void)
{
	int a[MAX][MAX] = {0};
	int n = 0, i, j, sum_main = 0, sum_second = 0;

	printf("n = ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("Row %d: ", i + 1);
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			/* ON THE MAIN DIAGONAL THE ROW EQUALS THE COLUMN */
			if (i == j)
			{
				sum_main = sum_main + a[i][j];
			}
			/* ON THE SECONDARY DIAGONAL ROW + COLUMN = N - 1 (INDEXES FROM 0) */
			if (i + j == n - 1)
			{
				sum_second = sum_second + a[i][j];
			}
		}
	}

	printf("Main diagonal sum: %d\n", sum_main);
	printf("Secondary diagonal sum: %d\n", sum_second);

	return 0;
}
