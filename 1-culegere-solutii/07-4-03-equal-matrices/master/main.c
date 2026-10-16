/* CULEGERE VII.4.3 - EQUAL MATRICES
 * TWO MATRICES WITH THE SAME SIZE (M ROWS, N COLUMNS) ARE READ; CHECK IF THEY ARE EQUAL
 * (THE ELEMENTS ON THE SAME POSITION ARE EQUAL)
 * EXAMPLE: M=2 N=2, 1 2 / 3 4 AND 1 2 / 3 4 -> THE MATRICES ARE EQUAL */
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
	int a[MAX][MAX] = {0}, b[MAX][MAX] = {0};
	int m = 0, n = 0, i, j, equal;

	printf("m = ");
	scanf("%d", &m);
	printf("n = ");
	scanf("%d", &n);
	printf("First matrix\n");
	read_matrix(a, m, n);
	printf("Second matrix\n");
	read_matrix(b, m, n);

	/* ONE DIFFERENT PAIR OF ELEMENTS IS ENOUGH TO MAKE THE MATRICES DIFFERENT */
	equal = 1;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[i][j] != b[i][j])
			{
				equal = 0;
			}
		}
	}

	if (equal == 1)
	{
		printf("The matrices are equal\n");
	}
	else
	{
		printf("The matrices are not equal\n");
	}

	return 0;
}
