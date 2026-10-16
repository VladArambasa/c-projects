/* CULEGERE VII.2.5 - SUM ON THE BORDER
 * A MATRIX WITH M ROWS AND N COLUMNS IS READ; PRINT THE SUM OF THE ELEMENTS ON ITS BORDER
 * EXAMPLE: M=3 N=4, 6 4 1 0 / 1 5 3 3 / 0 8 2 7 -> S=32 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 50 /* AT MOST 50 ROWS AND 50 COLUMNS */

int main(void)
{
	int a[MAX][MAX] = {0};
	int m = 0, n = 0, i, j, s;

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

	s = 0;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			/* ON THE BORDER: FIRST OR LAST ROW, FIRST OR LAST COLUMN;
			 * A CORNER IS ADDED ONLY ONCE, EVEN IF IT IS ON A ROW AND ON A COLUMN */
			if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
			{
				s = s + a[i][j];
			}
		}
	}
	printf("s=%d\n", s);

	return 0;
}
