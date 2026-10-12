/* SYMMETRIC MATRIX: A SQUARE MATRIX EQUAL TO ITS TRANSPOSE, M[I][J] == M[J][I] FOR ALL I, J */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 10

int main(void)
{
	int m[MAX][MAX];
	int n = 0, i, j;
	int symmetric = 1;

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

	for (i = 0; i < n; i++) /* COMPARE EVERY ELEMENT WITH ITS MIRROR */
	{
		for (j = 0; j < n; j++)
		{
			if (m[i][j] != m[j][i])
			{
				symmetric = 0;
			}
		}
	}

	if (symmetric)
	{
		printf("The matrix is symmetric\n");
	}
	else
	{
		printf("The matrix is not symmetric\n");
	}

	return 0;
}
