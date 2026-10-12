/* CULEGERE VII.2.7 - MAXIMUM OF EACH COLUMN
 * A MATRIX WITH M ROWS AND N COLUMNS IS READ; PRINT THE LARGEST VALUE ON EACH COLUMN
 * EXAMPLE: M=3 N=4, 1 9 3 4 / 5 2 8 0 / 7 6 1 4 -> 7 9 8 4 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 50 /* AT MOST 50 ROWS AND 50 COLUMNS */

int main(void)
{
	int a[MAX][MAX] = {0};
	int m = 0, n = 0, i, j, max;

	printf("m = ");
	scanf("%d", &m);
	printf("n = ");
	scanf("%d", &n);
	for (i = 0; i < m; i++)
	{
		printf("Row %d: ", i + 1);
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	/* THE COLUMNS ARE TRAVERSED ONE BY ONE, EACH FROM TOP TO BOTTOM */
	for (j = 0; j < n; j++)
	{
		max = a[0][j];
		for (i = 1; i < m; i++)
		{
			if (a[i][j] > max)
			{
				max = a[i][j];
			}
		}
		printf("column %d: max=%d\n", j + 1, max);
	}

	return 0;
}
