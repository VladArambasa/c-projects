/* CULEGERE X.6.11 - RECTANGLES WITH VERTICES OF ONE COLOR
 * N POINTS (N >= 4) ARE GIVEN BY THEIR COORDINATES AND THEIR COLOR (NATURAL NUMBERS <= 50);
 * PRINT THE VERTICES OF EVERY RECTANGLE WITH SIDES PARALLEL TO THE AXES WHOSE FOUR VERTICES ARE
 * GIVEN POINTS OF THE SAME COLOR
 * EXAMPLE: (1 1 2) (4 1 2) (4 3 2) (1 3 2) (6 1 2) (6 3 2) (2 2 5) (6 5 5) (2 5 7) (6 2 5)
 * -> 3 RECTANGLES OF COLOR 2; CORNERS (2 2) (6 2) (6 5) OF COLOR 5 HAVE (2 5) OF COLOR 7
 * ASSUMPTION: NO TWO POINTS ARE IN THE SAME PLACE; A SQUARE IS A RECTANGLE TOO */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAXC 50  /* THE LARGEST COORDINATE */
#define MAX 2601 /* AT MOST 51 * 51 DIFFERENT POINTS */

int x[MAX], y[MAX], color[MAX];
int color_at[MAXC + 1][MAXC + 1]; /* THE COLOR OF THE POINT AT (X, Y), -1 IF THERE IS NONE */

int main(void)
{
	int n = 0, i, j, c, found = 0;

	/* -1 MARKS AN EMPTY PLACE (0 IS A GOOD COLOR) */
	for (i = 0; i <= MAXC; i++)
	{
		for (j = 0; j <= MAXC; j++)
		{
			color_at[i][j] = -1;
		}
	}

	printf("n = ");
	scanf("%d", &n);
	printf("The %d points (x y color): ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d %d", &x[i], &y[i], &color[i]);
		color_at[x[i]][y[i]] = color[i];
	}

	/* POINT I IS TRIED AS THE BOTTOM-LEFT CORNER AND POINT J AS THE TOP-RIGHT CORNER;
	 * THE OTHER TWO CORNERS ARE (X[J], Y[I]) AND (X[I], Y[J]). EACH RECTANGLE HAS ONLY ONE
	 * BOTTOM-LEFT CORNER, SO IT IS PRINTED ONLY ONCE */
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			c = color[i];
			if (x[i] < x[j] && y[i] < y[j] && color[j] == c &&
			    color_at[x[j]][y[i]] == c && color_at[x[i]][y[j]] == c)
			{
				printf("(%d, %d) (%d, %d) ", x[i], y[i], x[j], y[i]);
				printf("(%d, %d) (%d, %d) color %d\n", x[j], y[j], x[i], y[j], c);
				found++;
			}
		}
	}

	if (found == 0)
	{
		printf("No rectangle\n");
	}

	return 0;
}
