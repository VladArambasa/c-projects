/* CULEGERE XIII.2.16 - THE FLAG BEARERS
 * A COLUMN OF PUPILS HAS M ROWS (M <= 15) OF N PUPILS (N <= 6). FIRST FLAG: THE SHORTEST PUPIL OF
 * EACH ROW IS CHOSEN, AND THE TALLEST OF THEM GETS THE FLAG. SECOND FLAG: THE TALLEST PUPIL OF
 * EACH ROW IS CHOSEN, AND THE SHORTEST OF THEM GETS THE FLAG. ON EQUAL HEIGHTS THE FIRST PUPIL IS
 * CHOSEN. PRINT THE POSITIONS (ROW, PLACE IN THE ROW) AND THE HEIGHTS OF THE FLAG BEARERS
 * EXAMPLE: 120 130 140 150 / 110 120 130 130 / 140 140 150 150 -> (3,1) 140 AND (2,3) 130 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX_M 15
#define MAX_N 6

int main(void)
{
	int h[MAX_M + 1][MAX_N + 1] = {{0}}; /* HEIGHTS; ROWS AND PLACES ARE COUNTED FROM 1 */
	int m = 0, n = 0, i, j, low, high;
	int row1 = 0, col1 = 0, row2 = 0, col2 = 0; /* WHERE THE TWO FLAGS ARE FOR NOW */

	printf("m = ");
	scanf("%d", &m);
	printf("n = ");
	scanf("%d", &n);
	for (i = 1; i <= m; i++)
	{
		printf("Row %d: ", i);
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &h[i][j]);
		}
	}

	for (i = 1; i <= m; i++)
	{
		/* THE SHORTEST AND THE TALLEST OF ROW I; STRICT COMPARISONS KEEP THE FIRST ON TIES */
		low = 1;
		high = 1;
		for (j = 2; j <= n; j++)
		{
			if (h[i][j] < h[i][low])
			{
				low = j;
			}
			if (h[i][j] > h[i][high])
			{
				high = j;
			}
		}

		/* FIRST FLAG: THE TALLEST OF THE SHORTEST; SECOND FLAG: THE SHORTEST OF THE TALLEST */
		if (i == 1 || h[i][low] > h[row1][col1])
		{
			row1 = i;
			col1 = low;
		}
		if (i == 1 || h[i][high] < h[row2][col2])
		{
			row2 = i;
			col2 = high;
		}
	}

	printf("First flag: position (%d,%d), height %d\n", row1, col1, h[row1][col1]);
	printf("Second flag: position (%d,%d), height %d\n", row2, col2, h[row2][col2]);

	return 0;
}
