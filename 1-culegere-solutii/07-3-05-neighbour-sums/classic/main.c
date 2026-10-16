/* CULEGERE VII.3.5 - SUM OF THE NEIGHBOURS
 * A MATRIX WITH M ROWS AND N COLUMNS IS READ; FOR EVERY ELEMENT PRINT THE SUM OF ITS
 * NEIGHBOURS (THE ELEMENTS AROUND IT, AT MOST 8)
 * EXAMPLE: M=3 N=2, 1 2 / 3 4 / 5 6 -> 9 8 / 18 17 / 13 12 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 50 /* AT MOST 50 ROWS AND 50 COLUMNS */

/* RETURNS THE SUM OF THE NEIGHBOURS OF ELEMENT (I, J): THE ELEMENTS OF THE 3 X 3 SQUARE
 * THAT HAS (I, J) IN ITS CENTER, WITHOUT (I, J) ITSELF AND WITHOUT PLACES OUTSIDE THE MATRIX */
int neighbour_sum(int a[][MAX], int m, int n, int i, int j)
{
	int r, c, s = 0;

	for (r = i - 1; r <= i + 1; r++)
	{
		for (c = j - 1; c <= j + 1; c++)
		{
			if ((r != i || c != j) && r >= 0 && r < m && c >= 0 && c < n)
			{
				s = s + a[r][c];
			}
		}
	}
	return s;
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

	/* THE SUMS ARE PRINTED AS A MATRIX: EACH SUM IN THE PLACE OF ITS ELEMENT */
	printf("The sums of the neighbours:\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", neighbour_sum(a, m, n, i, j));
		}
		printf("\n");
	}

	return 0;
}
