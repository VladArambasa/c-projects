/* CULEGERE XIII.2.18 - LIGHT ORGAN
 * AN ORGAN OF N X M BULBS (1 = ON, 0 = OFF) CHANGES ONCE A SECOND, ALL BULBS AT THE SAME TIME:
 * A BULB WITH AN EVEN NUMBER OF LIT NEIGHBOURS (LEFT, RIGHT, UP, DOWN; 0 COUNTS AS EVEN) SWITCHES,
 * A BULB WITH AN ODD NUMBER OF LIT NEIGHBOURS STAYS AS IT IS. PRINT THE ORGAN AFTER K SECONDS
 * (1 <= N, M <= 100, 1 <= K <= 500)
 * EXAMPLE: 4 4 3 AND 1 0 0 1 / 1 1 0 0 / 0 1 1 1 / 0 0 0 0
 *          -> 0 1 0 0 / 1 1 1 1 / 0 0 1 1 / 1 1 1 1 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100

/* ROWS GO FROM 1 TO N AND COLUMNS FROM 1 TO M; ROWS 0 AND N + 1 AND COLUMNS 0 AND M + 1 ARE
 * A BORDER OF BULBS THAT STAY OFF, SO EVERY BULB HAS FOUR NEIGHBOURS TO LOOK AT */
int bulb[MAX + 2][MAX + 2];
int after[MAX + 2][MAX + 2]; /* THE ORGAN ONE SECOND LATER */

/* HOW MANY OF THE FOUR NEIGHBOURS OF BULB (I, J) ARE ON */
int lit_neighbours(int i, int j)
{
	return bulb[i - 1][j] + bulb[i + 1][j] + bulb[i][j - 1] + bulb[i][j + 1];
}

/* ONE SECOND GOES BY: ALL BULBS CHANGE AT ONCE, SO THE NEW STATES GO TO ANOTHER TABLE FIRST */
void one_second(int n, int m)
{
	int i, j;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (lit_neighbours(i, j) % 2 == 0)
			{
				after[i][j] = 1 - bulb[i][j]; /* EVEN: THE BULB SWITCHES */
			}
			else
			{
				after[i][j] = bulb[i][j]; /* ODD: IT KEEPS ITS STATE */
			}
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			bulb[i][j] = after[i][j];
		}
	}
}

int main(void)
{
	int n = 0, m = 0, k = 0, i, j, t;

	printf("n, m and k: ");
	scanf("%d %d %d", &n, &m, &k);
	printf("The %d rows of %d bulbs (1 = on, 0 = off):\n", n, m);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &bulb[i][j]); /* INSIDE THE BORDER */
		}
	}

	/* LET K SECONDS GO BY */
	for (t = 1; t <= k; t++)
	{
		one_second(n, m);
	}

	/* THE ORGAN AFTER K SECONDS, ONE ROW ON EACH LINE */
	printf("Answer:\n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (j > 1)
			{
				printf(" "); /* ONE SPACE BETWEEN TWO BULBS */
			}
			printf("%d", bulb[i][j]);
		}
		printf("\n");
	}
	return 0;
}
