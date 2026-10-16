/* CULEGERE VII.3.1 - SORT THE ROWS BY THE FIRST COLUMN
 * A MATRIX WITH M ROWS AND N COLUMNS IS READ; BY SWAPPING WHOLE ROWS, MAKE THE ELEMENTS OF THE
 * FIRST COLUMN INCREASING AND PRINT THE NEW MATRIX
 * EXAMPLE: M=3 N=3, 7 4 9 / 1 8 4 / 5 4 0 -> 1 8 4 / 5 4 0 / 7 4 9
 * NOTE: THE BOOK'S EXAMPLE SAYS M=2; THE CORRECT VALUE IS M=3 (ITS MATRIX HAS 3 ROWS) */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 50 /* AT MOST 50 ROWS AND 50 COLUMNS */

/* SWAPS ROWS R1 AND R2 OF A MATRIX WITH N COLUMNS, ELEMENT BY ELEMENT */
void swap_rows(int a[][MAX], int n, int r1, int r2)
{
	int j, aux;

	for (j = 0; j < n; j++)
	{
		aux = a[r1][j];
		a[r1][j] = a[r2][j];
		a[r2][j] = aux;
	}
}

int main(void)
{
	int a[MAX][MAX] = {0};
	int m = 0, n = 0, i, j;

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

	/* SORTING BY INTERCHANGE: ROW I IS COMPARED WITH EVERY ROW BELOW IT;
	 * IF THEIR FIRST ELEMENTS ARE IN THE WRONG ORDER, THE WHOLE ROWS ARE SWAPPED */
	for (i = 0; i < m - 1; i++)
	{
		for (j = i + 1; j < m; j++)
		{
			if (a[i][0] > a[j][0])
			{
				swap_rows(a, n, i, j);
			}
		}
	}

	printf("The sorted matrix:\n");
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
