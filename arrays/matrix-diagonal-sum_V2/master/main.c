/* SUM OF THE MAIN DIAGONAL (V2): THE DIAGONAL IS M[I][I], SO ONE LOOP OF N STEPS IS ENOUGH */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

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

	for (i = 0; i < n; i++) /* N STEPS INSTEAD OF N * N */
	{
		sum = sum + m[i][i];
	}

	printf("Diagonal sum = %d\n", sum);

	return 0;
}
