/* SUM OF ALL THE ELEMENTS OF A MATRIX */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 10

int main(void)
{
	int m[MAX][MAX];
	int rows = 0, cols = 0, i, j;
	int sum = 0;

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
			sum = sum + m[i][j];
		}
	}

	printf("Sum = %d\n", sum);

	return 0;
}
