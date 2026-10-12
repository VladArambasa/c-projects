/* ARE THE ELEMENTS ON THE MAIN DIAGONAL ALL DIFFERENT? */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 10

int main(void)
{
	int m[MAX][MAX];
	int n = 0, i, j;
	int distinct = 1;

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

	for (i = 0; i < n; i++) /* COMPARE EACH DIAGONAL ELEMENT WITH THE ONES AFTER IT */
	{
		for (j = i + 1; j < n; j++)
		{
			if (m[i][i] == m[j][j])
			{
				distinct = 0;
			}
		}
	}

	if (distinct)
	{
		printf("All diagonal elements are different\n");
	}
	else
	{
		printf("Some diagonal elements repeat\n");
	}

	return 0;
}
