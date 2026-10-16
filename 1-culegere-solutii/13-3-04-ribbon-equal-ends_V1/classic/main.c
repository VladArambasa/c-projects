/* CULEGERE XIII.3.4 - RIBBON WITH EQUAL ENDS
 * A RIBBON HAS N BANDS (2 <= N <= 10000) COLORED WITH C COLORS (NUMBERED FROM 1 TO C, C <= 200).
 * CUT BANDS FROM ITS TWO ENDS SO THAT THE TWO END BANDS HAVE THE SAME COLOR AND THE RIBBON STAYS
 * AS LONG AS POSSIBLE; ON A TIE, CUT AS LITTLE AS POSSIBLE AT THE BEGINNING. PANGLICA.IN HOLDS N
 * AND C, THEN THE N COLORS, ONE PER LINE; PANGLICA.OUT GETS, ONE PER LINE: THE BANDS LEFT, THE
 * COLOR AT THE ENDS, THE BANDS CUT AT THE BEGINNING, THE BANDS CUT AT THE END
 * V1: TRY THE LENGTHS FROM N DOWN AND, FOR EACH LENGTH, EVERY START FROM THE LEFT
 * ASSUMPTION: IF NO COLOR APPEARS TWICE, ONE BAND IS KEPT (ITS TWO ENDS ARE THE SAME BAND)
 * EXAMPLE: 6 3 / 1 2 1 3 2 3 -> 4 / 2 / 1 / 1 */
#include <stdio.h> /* PRINTF, FOPEN, FSCANF, FPRINTF */

#define MAXN 10000

int color[MAXN];

int main(void)
{
	FILE *in = fopen("PANGLICA.IN", "r");
	FILE *out;
	int n = 0, c = 0, i, len, start, found;
	int best_len = 0, best_start = 0;

	if (in == NULL)
	{
		printf("Cannot open PANGLICA.IN\n");
		return 1;
	}
	fscanf(in, "%d %d", &n, &c);
	for (i = 0; i < n; i++)
	{
		fscanf(in, "%d", &color[i]);
	}
	fclose(in);

	/* THE LONGEST PIECES ARE TRIED FIRST AND, FOR ONE LENGTH, THE STARTS FROM THE LEFT: THE
	 * FIRST PIECE WITH EQUAL END COLORS IS THE LONGEST ONE, CUT LEAST AT THE BEGINNING */
	found = 0;
	for (len = n; len >= 1 && found == 0; len--)
	{
		for (start = 0; start + len <= n && found == 0; start++)
		{
			if (color[start] == color[start + len - 1])
			{
				found = 1;
				best_len = len;
				best_start = start;
			}
		}
	}

	out = fopen("PANGLICA.OUT", "w");
	fprintf(out, "%d\n%d\n", best_len, color[best_start]);
	fprintf(out, "%d\n%d\n", best_start, n - best_start - best_len);
	fclose(out);

	return 0;
}
