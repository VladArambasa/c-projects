/* CULEGERE XIII.3.4 - RIBBON WITH EQUAL ENDS
 * A RIBBON HAS N BANDS (2 <= N <= 10000) COLORED WITH C COLORS (NUMBERED FROM 1 TO C, C <= 200).
 * CUT BANDS FROM ITS TWO ENDS SO THAT THE TWO END BANDS HAVE THE SAME COLOR AND THE RIBBON STAYS
 * AS LONG AS POSSIBLE; ON A TIE, CUT AS LITTLE AS POSSIBLE AT THE BEGINNING. PANGLICA.IN HOLDS N
 * AND C, THEN THE N COLORS, ONE PER LINE; PANGLICA.OUT GETS, ONE PER LINE: THE BANDS LEFT, THE
 * COLOR AT THE ENDS, THE BANDS CUT AT THE BEGINNING, THE BANDS CUT AT THE END
 * V2: ONE PASS REMEMBERS THE FIRST AND THE LAST BAND OF EACH COLOR, INSTEAD OF TRYING EVERY CUT
 * ASSUMPTION: IF NO COLOR APPEARS TWICE, ONE BAND IS KEPT (ITS TWO ENDS ARE THE SAME BAND)
 * EXAMPLE: 6 3 / 1 2 1 3 2 3 -> 4 / 2 / 1 / 1 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAXC 200

int first[MAXC + 1]; /* FIRST[K]: THE FIRST BAND OF COLOR K, -1 IF THE COLOR IS MISSING */
int last[MAXC + 1];  /* LAST[K]: THE LAST BAND OF COLOR K */

int main(void)
{
	FILE *in = fopen("PANGLICA.IN", "r");
	FILE *out;
	int n = 0, c = 0, i, k, len, color = 0;
	int best_len = 0, best_color = 0, best_start = 0;

	if (in == NULL)
	{
		printf("Cannot open PANGLICA.IN\n");
		return 1;
	}
	fscanf(in, "%d %d", &n, &c);
	for (k = 1; k <= c; k++)
	{
		first[k] = -1;
	}
	for (i = 0; i < n; i++)
	{
		fscanf(in, "%d", &color);
		if (first[color] == -1)
		{
			first[color] = i;
		}
		last[color] = i;
	}
	fclose(in);

	/* THE LONGEST PIECE WITH ENDS OF COLOR K GOES FROM ITS FIRST TO ITS LAST BAND;
	 * ON A TIE THE PIECE THAT STARTS EARLIER IS CUT LESS AT THE BEGINNING */
	for (k = 1; k <= c; k++)
	{
		if (first[k] != -1)
		{
			len = last[k] - first[k] + 1;
			if (len > best_len || (len == best_len && first[k] < best_start))
			{
				best_len = len;
				best_color = k;
				best_start = first[k];
			}
		}
	}

	out = fopen("PANGLICA.OUT", "w");
	fprintf(out, "%d\n%d\n", best_len, best_color);
	fprintf(out, "%d\n%d\n", best_start, n - best_start - best_len);
	fclose(out);

	return 0;
}
