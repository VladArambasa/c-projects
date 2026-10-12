/* CULEGERE VII.1.2 - SUM OF TWO MATRICES
 * TWO MATRICES WITH M ROWS AND N COLUMNS ARE READ; PRINT THEIR SUM MATRIX
 * (EACH ELEMENT IS THE SUM OF THE TWO ELEMENTS ON THE SAME POSITION)
 * EXAMPLE: M=2 N=2, 1 2 / 3 4 AND 5 6 / 7 8 -> 6 8 / 10 12 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 50 /* AT MOST 50 ROWS AND 50 COLUMNS */

/* READS A MATRIX WITH M ROWS AND N COLUMNS, ROW BY ROW */
void read_matrix(int a[][MAX], int m, int n)
{
	int i, j;

	for (i = 0; i < m; i++)
	{
		printf("Row %d: ", i + 1);
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
}

int main(void)
{
	int a[MAX][MAX] = {0}, b[MAX][MAX] = {0}, s[MAX][MAX];
	int m = 0, n = 0, i, j;

	printf("m = ");
	scanf("%d", &m);
	printf("n = ");
	scanf("%d", &n);

	printf("First matrix\n");
	read_matrix(a, m, n);
	printf("Second matrix\n");
	read_matrix(b, m, n);

	/* ADD THE TWO ELEMENTS FOUND ON THE SAME POSITION */
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			s[i][j] = a[i][j] + b[i][j];
		}
	}

	printf("The sum matrix:\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", s[i][j]);
		}
		printf("\n");
	}

	return 0;
}
