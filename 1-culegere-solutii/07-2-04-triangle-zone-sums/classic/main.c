/* CULEGERE VII.2.4 - SUMS OF THE FOUR TRIANGULAR ZONES
 * THE TWO DIAGONALS SPLIT A SQUARE MATRIX INTO FOUR TRIANGULAR ZONES: TOP, RIGHT, BOTTOM AND
 * LEFT; PRINT THE SUM OF THE ELEMENTS INSIDE EACH ZONE
 * EXAMPLE: N=5, THE NUMBERS 1, 2, ..., 25 ROW BY ROW -> TOP 17, RIGHT 59, BOTTOM 87, LEFT 45
 * ASSUMPTION: THE ELEMENTS ON THE DIAGONALS ARE NOT INSIDE ANY ZONE, SO THEY ARE NOT ADDED */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 50 /* AT MOST 50 ROWS AND 50 COLUMNS */

int main(void)
{
	int a[MAX][MAX] = {0};
	int n = 0, i, j, top = 0, right = 0, bottom = 0, left = 0;

	printf("n = ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("Row %d: ", i + 1);
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	/* ABOVE THE MAIN DIAGONAL I < J, BELOW IT I > J;
	 * ABOVE THE SECONDARY DIAGONAL I + J < N - 1, BELOW IT I + J > N - 1 */
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i < j && i + j < n - 1)
			{
				top = top + a[i][j];
			}
			else if (i < j && i + j > n - 1)
			{
				right = right + a[i][j];
			}
			else if (i > j && i + j > n - 1)
			{
				bottom = bottom + a[i][j];
			}
			else if (i > j && i + j < n - 1)
			{
				left = left + a[i][j];
			}
		}
	}

	printf("Top zone: %d\n", top);
	printf("Right zone: %d\n", right);
	printf("Bottom zone: %d\n", bottom);
	printf("Left zone: %d\n", left);

	return 0;
}
