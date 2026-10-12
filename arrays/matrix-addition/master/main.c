/* ADD TWO MATRICES OF THE SAME SIZE, ELEMENT BY ELEMENT */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 10

int main(void)
{
	int a[MAX][MAX], b[MAX][MAX];
	int rows = 0, cols = 0, i, j;

	printf("Rows and columns (1-%d): ", MAX);
	scanf("%d %d", &rows, &cols);
	if (rows < 1 || rows > MAX || cols < 1 || cols > MAX)
	{
		printf("Invalid size\n");
		return 1;
	}

	printf("First matrix, %d elements:\n", rows * cols);
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	printf("Second matrix, %d elements:\n", rows * cols);
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			scanf("%d", &b[i][j]);
		}
	}

	printf("Sum:\n");
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			printf("%4d", a[i][j] + b[i][j]);
		}
		printf("\n");
	}

	return 0;
}
