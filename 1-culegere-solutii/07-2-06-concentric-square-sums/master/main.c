/* CULEGERE VII.2.6 - SUMS ON CONCENTRIC SQUARES
 * AN N X N MATRIX IS READ; PRINT THE SUM OF THE ELEMENTS ON EACH CONCENTRIC SQUARE, FROM THE
 * BORDER (SQUARE 1) TOWARDS THE CENTER
 * EXAMPLE: N=4, 1 1 1 1 / 2 2 2 2 / 3 3 3 3 / 4 4 4 4 -> SQUARE 1 = 30, SQUARE 2 = 10 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 50 /* AT MOST 50 ROWS AND 50 COLUMNS */

int main(void)
{
	int a[MAX][MAX] = {0};
	int sum[MAX] = {0};
	int n = 0, i, j, k, squares;

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

	/* THE SQUARE OF AN ELEMENT IS GIVEN BY ITS DISTANCE TO THE NEAREST BORDER:
	 * 0 ON THE BORDER (SQUARE 1), 1 ON THE NEXT SQUARE INSIDE (SQUARE 2), ... */
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			/* THE SMALLEST DISTANCE: TO THE TOP, LEFT, BOTTOM OR RIGHT BORDER */
			k = i;
			if (j < k)
			{
				k = j;
			}
			if (n - 1 - i < k)
			{
				k = n - 1 - i;
			}
			if (n - 1 - j < k)
			{
				k = n - 1 - j;
			}
			sum[k] = sum[k] + a[i][j];
		}
	}

	/* N=4 HAS 2 SQUARES, N=5 HAS 3 (THE LAST ONE IS ONLY THE CENTER ELEMENT) */
	squares = (n + 1) / 2;
	for (k = 0; k < squares; k++)
	{
		printf("sum of square %d=%d\n", k + 1, sum[k]);
	}

	return 0;
}
