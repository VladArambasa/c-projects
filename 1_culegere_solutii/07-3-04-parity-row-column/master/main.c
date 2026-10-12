/* CULEGERE VII.3.4 - EVEN NUMBER OF 1 ON EVERY ROW AND COLUMN
 * A MATRIX WITH M ROWS AND N COLUMNS HOLDS ONLY 0 AND 1; BUILD A MATRIX WITH M+1 ROWS AND N+1
 * COLUMNS THAT HAS AN EVEN NUMBER OF 1 ON EVERY ROW AND ON EVERY COLUMN
 * EXAMPLE: M=2 N=3, 1 0 1 / 1 1 1 -> 1 0 1 0 / 1 1 1 1 / 0 1 0 1
 * ASSUMPTION: THE GIVEN MATRIX IS KEPT AND A PARITY COLUMN AND A PARITY ROW ARE ADDED TO IT */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 50 /* AT MOST 50 ROWS AND 50 COLUMNS */

int main(void)
{
	int a[MAX + 1][MAX + 1] = {0}; /* ROOM FOR THE NEW ROW AND THE NEW COLUMN */
	int m = 0, n = 0, i, j, ones;

	printf("m = ");
	scanf("%d", &m);
	printf("n = ");
	scanf("%d", &n);
	for (i = 0; i < m; i++)
	{
		printf("Row %d (0 and 1): ", i + 1);
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	/* NEW LAST COLUMN: 1 WHEN THE ROW HAS AN ODD NUMBER OF 1, SO THE ROW BECOMES EVEN */
	for (i = 0; i < m; i++)
	{
		ones = 0;
		for (j = 0; j < n; j++)
		{
			ones = ones + a[i][j];
		}
		a[i][n] = ones % 2;
	}

	/* NEW LAST ROW: THE SAME FOR EVERY COLUMN, THE NEW COLUMN INCLUDED
	 * (THE NEW ROW ITSELF THEN ALSO HAS AN EVEN NUMBER OF 1) */
	for (j = 0; j <= n; j++)
	{
		ones = 0;
		for (i = 0; i < m; i++)
		{
			ones = ones + a[i][j];
		}
		a[m][j] = ones % 2;
	}

	printf("The new matrix:\n");
	for (i = 0; i <= m; i++)
	{
		for (j = 0; j <= n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}
