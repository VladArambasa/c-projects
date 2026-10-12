/* CULEGERE XIII.3.8 - RANKS OF NUMBERS
 * SIRURI.IN HOLDS N (1 <= N <= 100) AND THEN N DIFFERENT NATURAL NUMBERS X[1..N], EACH AT MOST
 * 32000. BUILD Y[1..N] WITH VALUES FROM 1 TO N SO THAT X[I] < X[J] ALWAYS GIVES Y[I] < Y[J], AND
 * WRITE IT IN SIRURI.OUT: Y[I] IS THE PLACE OF X[I] WHEN THE NUMBERS ARE SORTED INCREASINGLY
 * EXAMPLE: 6 / 12 3 7 16 10 1 -> 5 2 3 6 4 1 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAXN 100

int main(void)
{
	FILE *in = fopen("siruri.in", "r");
	FILE *out;
	int x[MAXN], y[MAXN];
	int n = 0, i, j;

	if (in == NULL)
	{
		printf("Cannot open siruri.in\n");
		return 1;
	}
	fscanf(in, "%d", &n);
	for (i = 0; i < n; i++)
	{
		x[i] = 0;
		fscanf(in, "%d", &x[i]);
	}
	fclose(in);

	/* Y[I] = 1 + HOW MANY NUMBERS ARE SMALLER THAN X[I] */
	for (i = 0; i < n; i++)
	{
		y[i] = 1;
		for (j = 0; j < n; j++)
		{
			if (x[j] < x[i])
			{
				y[i]++;
			}
		}
	}

	out = fopen("siruri.out", "w");
	for (i = 0; i < n; i++)
	{
		if (i > 0)
		{
			fprintf(out, " ");
		}
		fprintf(out, "%d", y[i]);
	}
	fprintf(out, "\n");
	fclose(out);

	return 0;
}
