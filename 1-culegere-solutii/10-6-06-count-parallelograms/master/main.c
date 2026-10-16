/* CULEGERE X.6.6 - COUNT PARALLELOGRAMS
 * PUNCTE.INT HOLDS N AND THE COORDINATES OF N POINTS, NO FOUR OF THEM ON ONE LINE; PRINT ON THE
 * SCREEN HOW MANY PARALLELOGRAMS HAVE ALL FOUR VERTICES AMONG THESE POINTS
 * EXAMPLE: (2 2) (3 3) (5 4) (1 6) (8 2) (7 1) (6 5) -> 6 (THE TABLE OF THE BOOK)
 * ASSUMPTION: THE COORDINATES ARE INTEGERS; AT MOST 100 POINTS */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100

int x[MAX], y[MAX];

/* 1 IF THE SEGMENTS (A, B) AND (C, D) HAVE THE SAME MIDDLE POINT; THE SUMS OF THE
 * COORDINATES ARE COMPARED INSTEAD OF THEIR HALVES, SO NO DIVISION IS NEEDED */
int same_middle(int a, int b, int c, int d)
{
	if (x[a] + x[b] == x[c] + x[d] && y[a] + y[b] == y[c] + y[d])
	{
		return 1;
	}
	return 0;
}

int main(void)
{
	FILE *in;
	int n = 0, i, j, k, m, count = 0;

	in = fopen("puncte.int", "r");
	if (in == NULL)
	{
		printf("Cannot open puncte.int\n");
		return 1;
	}
	fscanf(in, "%d", &n);
	for (i = 0; i < n; i++)
	{
		fscanf(in, "%d %d", &x[i], &y[i]);
	}
	fclose(in);

	/* THE DIAGONALS OF A PARALLELOGRAM CUT EACH OTHER IN HALF: FOUR POINTS FORM ONE WHEN
	 * THEY SPLIT INTO TWO PAIRS (THE DIAGONALS) WITH THE SAME MIDDLE POINT. NO FOUR POINTS
	 * ARE ON ONE LINE, SO SUCH A FIGURE IS NEVER FLAT. TRY EVERY GROUP OF 4 POINTS AND ITS
	 * 3 SPLITS INTO TWO PAIRS */
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			for (k = j + 1; k < n; k++)
			{
				for (m = k + 1; m < n; m++)
				{
					if (same_middle(i, j, k, m) || same_middle(i, k, j, m) ||
					    same_middle(i, m, j, k))
					{
						count++;
					}
				}
			}
		}
	}

	printf("%d\n", count);

	return 0;
}
