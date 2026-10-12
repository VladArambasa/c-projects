/* CULEGERE VII.1.1 - ADD K TO A MATRIX
 * A MATRIX WITH M ROWS AND N COLUMNS (1 <= M, N <= 50) WITH INTEGER ELEMENTS AND AN INTEGER K
 * ARE READ; PRINT THE MATRIX WITH EVERY ELEMENT INCREASED BY K
 * EXAMPLE: M=2 N=3 K=5, 1 2 3 / 4 5 6 -> 6 7 8 / 9 10 11 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 50 /* AT MOST 50 ROWS AND 50 COLUMNS */

int main(void)
{
	int a[MAX][MAX] = {0};
	int m = 0, n = 0, k = 0, i, j;

	printf("m = ");
	scanf("%d", &m);
	printf("n = ");
	scanf("%d", &n);
	printf("k = ");
	scanf("%d", &k);

	/* READ THE MATRIX ROW BY ROW */
	for (i = 0; i < m; i++)
	{
		printf("Row %d: ", i + 1);
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	/* FULL TRAVERSAL: EVERY ELEMENT GROWS BY K */
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			a[i][j] = a[i][j] + k;
		}
	}

	/* PRINT THE MATRIX, ONE ROW PER LINE */
	printf("The new matrix:\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}
