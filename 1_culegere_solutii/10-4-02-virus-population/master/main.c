/* CULEGERE X.4.2 - VIRUS POPULATION
 * VIRUSES LIVE ON A MATRIX OF M ROWS AND N COLUMNS: 1, 2 OR 3 IS THE GENERATION (AGE) OF A
 * VIRUS, 0 IS AN EMPTY PLACE; A PLACE HAS AT MOST 4 NEIGHBORS: N, S, E, W. A VIRUS DIES ISOLATED
 * WITH FEWER THAN 2 NEIGHBORS AND SUFFOCATED WITH MORE THAN 3; A VIRUS APPEARS ON AN EMPTY PLACE
 * WITH 2 OR 3 NEIGHBORS; A VIRUS LIVES 3 GENERATIONS. WRITE THE POPULATION AFTER G GENERATIONS.
 * VIRUS.INP: M N G, THEN THE MATRIX; VIRUS.OUT: THE MATRIX AFTER G GENERATIONS
 * EXAMPLE: 3 3 2 / 2 1 0 / 2 2 3 / 0 1 3 -> 0 3 0 / 0 1 0 / 2 0 0 (THE TABLE OF THE BOOK)
 * ASSUMPTION: A NEIGHBOR IS A NON-EMPTY PLACE TO THE N, S, E OR W (NOTHING BEYOND THE BORDER)
 * ASSUMPTION: ALL THE PLACES CHANGE AT THE SAME TIME, LOOKING AT THE PREVIOUS GENERATION
 * ASSUMPTION: A VIRUS WITH 2 OR 3 NEIGHBORS GETS ONE GENERATION OLDER; AT AGE 3 IT DIES
 * ASSUMPTION: A NEW VIRUS HAS AGE 1; AT MOST 100 ROWS AND 100 COLUMNS
 * THESE RULES GIVE EXACTLY THE EXAMPLE TABLE OF THE BOOK */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100

/* ROWS 0 AND M + 1, COLUMNS 0 AND N + 1 STAY EMPTY: A BORDER WITHOUT VIRUSES,
 * SO EVERY PLACE OF THE MATRIX HAS 4 NEIGHBOR PLACES TO LOOK AT */
int a[MAX + 2][MAX + 2]; /* THE CURRENT GENERATION */
int b[MAX + 2][MAX + 2]; /* THE NEXT GENERATION */

/* HOW MANY VIRUSES ARE ON THE 4 NEIGHBOR PLACES OF PLACE (I, J) */
int neighbors(int i, int j)
{
	int di[4] = {-1, 1, 0, 0}; /* N, S, E, W */
	int dj[4] = {0, 0, 1, -1};
	int d, count = 0;

	for (d = 0; d < 4; d++)
	{
		if (a[i + di[d]][j + dj[d]] > 0)
		{
			count++;
		}
	}
	return count;
}

int main(void)
{
	FILE *in, *out;
	int m = 0, n = 0, g = 0, i, j, k, count;

	in = fopen("virus.inp", "r");
	if (in == NULL)
	{
		printf("Cannot open virus.inp\n");
		return 1;
	}
	fscanf(in, "%d %d %d", &m, &n, &g);
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			fscanf(in, "%d", &a[i][j]);
		}
	}
	fclose(in);

	for (k = 1; k <= g; k++)
	{
		/* BUILD THE NEXT GENERATION IN B, LOOKING ONLY AT THE CURRENT ONE IN A */
		for (i = 1; i <= m; i++)
		{
			for (j = 1; j <= n; j++)
			{
				count = neighbors(i, j);
				if (a[i][j] == 0)
				{
					/* EMPTY PLACE: A NEW VIRUS APPEARS WITH 2 OR 3 NEIGHBORS */
					if (count == 2 || count == 3)
					{
						b[i][j] = 1;
					}
					else
					{
						b[i][j] = 0;
					}
				}
				else if (count < 2 || count > 3)
				{
					b[i][j] = 0; /* ISOLATED OR SUFFOCATED */
				}
				else if (a[i][j] < 3)
				{
					b[i][j] = a[i][j] + 1; /* ONE GENERATION OLDER */
				}
				else
				{
					b[i][j] = 0; /* IT HAS LIVED ITS 3 GENERATIONS */
				}
			}
		}

		/* THE NEXT GENERATION BECOMES THE CURRENT ONE */
		for (i = 1; i <= m; i++)
		{
			for (j = 1; j <= n; j++)
			{
				a[i][j] = b[i][j];
			}
		}
	}

	out = fopen("virus.out", "w");
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (j > 1)
			{
				fprintf(out, " "); /* ONE SPACE BETWEEN THE NUMBERS OF A ROW */
			}
			fprintf(out, "%d", a[i][j]);
		}
		fprintf(out, "\n");
	}
	fclose(out);

	return 0;
}
