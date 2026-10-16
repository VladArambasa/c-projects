/* CULEGERE VII.3.2 - REMOVE A ROW
 * A MATRIX WITH M ROWS AND N COLUMNS AND A NUMBER K (K <= M) ARE READ; REMOVE ROW K FROM THE
 * MATRIX AND PRINT WHAT REMAINS
 * EXAMPLE: M=3 N=3, 1 2 3 / 4 5 6 / 7 8 9, K=2 -> 1 2 3 / 7 8 9 */
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
	for (i = 0; i < m; i++)
	{
		printf("Row %d: ", i + 1);
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	printf("k = ");
	scanf("%d", &k);

	/* EVERY ROW BELOW ROW K MOVES ONE PLACE UP, OVER THE ROW ABOVE IT
	 * (ROW K HAS THE INDEX K - 1) */
	for (i = k - 1; i < m - 1; i++)
	{
		for (j = 0; j < n; j++)
		{
			a[i][j] = a[i + 1][j];
		}
	}
	m--; /* THE MATRIX HAS ONE ROW LESS */

	printf("The matrix without row %d:\n", k);
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
