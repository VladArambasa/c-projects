/* READ AND PRINT A MATRIX (A TWO-DIMENSIONAL ARRAY) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 10

int main(void)
{
	int m[MAX][MAX]; /* MAX ROWS, MAX COLUMNS */
	int rows = 0, cols = 0, i, j;

	printf("Rows and columns (1-%d): ", MAX);
	scanf("%d %d", &rows, &cols);
	if (rows < 1 || rows > MAX || cols < 1 || cols > MAX)
	{
		printf("Invalid size\n");
		return 1;
	}

	printf("Enter the %d elements, row by row:\n", rows * cols);
	for (i = 0; i < rows; i++) /* I = ROW */
	{
		for (j = 0; j < cols; j++) /* J = COLUMN */
		{
			scanf("%d", &m[i][j]);
		}
	}

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			printf("%4d", m[i][j]); /* WIDTH 4 KEEPS THE COLUMNS ALIGNED */
		}
		printf("\n");
	}

	return 0;
}
