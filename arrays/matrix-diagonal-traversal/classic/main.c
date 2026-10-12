/* ZIGZAG DIAGONAL TRAVERSAL: WALK THE ANTI-DIAGONALS, CHANGING DIRECTION EVERY TIME
 * 1 2 3
 * 4 5 6   ->   1 2 4 7 5 3 6 8 9
 * 7 8 9 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 10

int main(void)
{
	int m[MAX][MAX];
	int rows = 0, cols = 0, i, j, d, r, c;

	printf("Rows and columns (1-%d): ", MAX);
	scanf("%d %d", &rows, &cols);
	if (rows < 1 || rows > MAX || cols < 1 || cols > MAX)
	{
		printf("Invalid size\n");
		return 1;
	}

	printf("Enter the %d elements, row by row:\n", rows * cols);
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			scanf("%d", &m[i][j]);
		}
	}

	for (d = 0; d <= rows + cols - 2; d++) /* ON DIAGONAL D, ROW + COLUMN = D */
	{
		if (d % 2 == 0) /* EVEN DIAGONAL: GO UP AND RIGHT */
		{
			r = (d < rows) ? d : rows - 1; /* START AT THE BOTTOM-LEFT END OF THE DIAGONAL */
			c = d - r;
			while (r >= 0 && c < cols)
			{
				printf("%d ", m[r][c]);
				r--;
				c++;
			}
		}
		else /* ODD DIAGONAL: GO DOWN AND LEFT */
		{
			c = (d < cols) ? d : cols - 1; /* START AT THE TOP-RIGHT END OF THE DIAGONAL */
			r = d - c;
			while (c >= 0 && r < rows)
			{
				printf("%d ", m[r][c]);
				r++;
				c--;
			}
		}
	}
	printf("\n");

	return 0;
}
