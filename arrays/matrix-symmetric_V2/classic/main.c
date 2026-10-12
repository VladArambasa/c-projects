/* SYMMETRIC MATRIX (V2): CHECK ONLY ABOVE THE DIAGONAL (EACH PAIR ONCE) AND STOP AT THE FIRST MISMATCH */
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

	for (i = 0; i < n && symmetric; i++) /* THE OUTER LOOP STOPS TOO ONCE A MISMATCH IS FOUND */
	{
		for (j = i + 1; j < n; j++) /* THE DIAGONAL ITSELF NEVER NEEDS CHECKING */
		{
			if (m[i][j] != m[j][i])
			{
				symmetric = 0;
				break;
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
