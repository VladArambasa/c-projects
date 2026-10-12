/* TRANSPOSE OF A MATRIX: ROWS BECOME COLUMNS */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 10

int main(void)
{
	int m[MAX][MAX], t[MAX][MAX];
	int rows = 0, cols = 0, i, j;

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

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			t[j][i] = m[i][j]; /* ELEMENT (I, J) MOVES TO (J, I) */
		}
	}

	printf("Transpose (%d x %d):\n", cols, rows);
	for (i = 0; i < cols; i++)
	{
		for (j = 0; j < rows; j++)
		{
			printf("%4d", t[i][j]);
		}
		printf("\n");
	}

	return 0;
}
