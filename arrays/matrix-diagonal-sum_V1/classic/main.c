/* SUM OF THE MAIN DIAGONAL: VISIT EVERY ELEMENT AND KEEP THOSE WHERE THE ROW EQUALS THE COLUMN */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 10

int main(void)
{
	int m[MAX][MAX];
	int n = 0, i, j;
	int sum = 0;

	printf("Size of the square matrix (1-%d): ", MAX);
	scanf("%d", &n);
	if (n < 1 || n > MAX)
	{
		printf("Invalid size\n");
		return 1;
	}

	printf("Enter the %d elements, row by row:\n", n * n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &m[i][j]);
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j) /* ON THE DIAGONAL */
			{
				sum = sum + m[i][j];
			}
		}
	}

	printf("Diagonal sum = %d\n", sum);

	return 0;
}
