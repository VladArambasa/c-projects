/* MATRIX MULTIPLICATION: C[I][J] = SUM OF A[I][K] * B[K][J] */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 10

int main(void)
{
	int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
	int r1 = 0, c1 = 0, r2 = 0, c2 = 0, i, j, k;

	printf("Rows and columns of the first matrix (1-%d): ", MAX);
	scanf("%d %d", &r1, &c1);
	printf("Rows and columns of the second matrix (1-%d): ", MAX);
	scanf("%d %d", &r2, &c2);

	if (r1 < 1 || r1 > MAX || c1 < 1 || c1 > MAX || r2 < 1 || r2 > MAX || c2 < 1 || c2 > MAX)
	{
		printf("Invalid size\n");
		return 1;
	}
	if (c1 != r2) /* COLUMNS OF THE FIRST MUST EQUAL ROWS OF THE SECOND */
	{
		printf("These matrices cannot be multiplied\n");
		return 1;
	}

	printf("First matrix, %d elements:\n", r1 * c1);
	for (i = 0; i < r1; i++)
	{
		for (j = 0; j < c1; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	printf("Second matrix, %d elements:\n", r2 * c2);
	for (i = 0; i < r2; i++)
	{
		for (j = 0; j < c2; j++)
		{
			scanf("%d", &b[i][j]);
		}
	}

	for (i = 0; i < r1; i++)
	{
		for (j = 0; j < c2; j++)
		{
			c[i][j] = 0;
			for (k = 0; k < c1; k++) /* ROW I OF A TIMES COLUMN J OF B */
			{
				c[i][j] = c[i][j] + a[i][k] * b[k][j];
			}
		}
	}

	printf("Product:\n");
	for (i = 0; i < r1; i++)
	{
		for (j = 0; j < c2; j++)
		{
			printf("%6d", c[i][j]);
		}
		printf("\n");
	}

	return 0;
}
