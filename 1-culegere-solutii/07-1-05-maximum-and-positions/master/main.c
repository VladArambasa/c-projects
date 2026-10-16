/* CULEGERE VII.1.5 - MAXIMUM AND ITS POSITIONS
 * AN N X N MATRIX IS READ; PRINT ITS LARGEST ELEMENT AND ALL THE POSITIONS (ROW COLUMN)
 * WHERE IT APPEARS
 * EXAMPLE: N=2, 4 7 / 5 7 -> MAX=7 POSITIONS 1 2   2 2 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 50 /* AT MOST 50 ROWS AND 50 COLUMNS */

int main(void)
{
	int a[MAX][MAX] = {0};
	int n = 0, i, j, max;

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

	/* FIRST TRAVERSAL: FIND THE MAXIMUM, STARTING FROM THE FIRST ELEMENT */
	max = a[0][0];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[i][j] > max)
			{
				max = a[i][j];
			}
		}
	}

	/* SECOND TRAVERSAL: PRINT EVERY POSITION OF THE MAXIMUM, NUMBERED FROM 1 */
	printf("max=%d positions", max);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[i][j] == max)
			{
				printf(" %d %d  ", i + 1, j + 1);
			}
		}
	}
	printf("\n");

	return 0;
}
