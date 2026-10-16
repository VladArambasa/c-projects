/* CULEGERE VII.4.6 - MAGIC SQUARE
 * AN N X N MATRIX IS READ; CHECK IF IT IS A MAGIC SQUARE: EVERY ROW, EVERY COLUMN AND EACH OF
 * THE TWO DIAGONALS HAVE THE SAME SUM
 * EXAMPLE: N=3, 2 7 6 / 9 5 1 / 4 3 8 -> YES (EVERY SUM IS 15) */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 50 /* AT MOST 50 ROWS AND 50 COLUMNS */

int main(void)
{
	int a[MAX][MAX] = {0};
	int n = 0, i, j, s, target, magic;

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

	/* THE SUM OF THE MAIN DIAGONAL IS THE ONE ALL THE OTHER SUMS MUST EQUAL */
	target = 0;
	for (i = 0; i < n; i++)
	{
		target = target + a[i][i];
	}
	magic = 1;

	/* THE SECONDARY DIAGONAL */
	s = 0;
	for (i = 0; i < n; i++)
	{
		s = s + a[i][n - 1 - i];
	}
	if (s != target)
	{
		magic = 0;
	}

	/* EVERY ROW */
	for (i = 0; i < n; i++)
	{
		s = 0;
		for (j = 0; j < n; j++)
		{
			s = s + a[i][j];
		}
		if (s != target)
		{
			magic = 0;
		}
	}

	/* EVERY COLUMN */
	for (j = 0; j < n; j++)
	{
		s = 0;
		for (i = 0; i < n; i++)
		{
			s = s + a[i][j];
		}
		if (s != target)
		{
			magic = 0;
		}
	}

	if (magic == 1)
	{
		printf("Yes, it is a magic square (every sum is %d)\n", target);
	}
	else
	{
		printf("No, it is not a magic square\n");
	}

	return 0;
}
