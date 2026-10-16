/* CULEGERE XIII.4.5 - SPIDER SHORTEST PATHS
 * THE NODES OF A NET LIE AT THE POINTS WITH INTEGER COORDINATES, EACH ONE JOINED TO ITS 4
 * NEIGHBOURS. A SPIDER STARTS AT (0, 0) AND EVERY SECOND MOVES TO A NEIGHBOUR NODE. SPIDER.IN
 * HOLDS X AND Y (0 < X, Y <= 80); WRITE IN SPIDER.OUT IN HOW MANY WAYS THE SPIDER CAN REACH (X, Y)
 * IN THE SHORTEST TIME. A SHORTEST WAY ONLY STEPS RIGHT OR UP, SO THE WAYS TO A NODE = THE WAYS TO
 * THE NODE ON ITS LEFT + THE WAYS TO THE NODE BELOW IT (AS IN PASCAL'S TRIANGLE). THE ANSWER HAS
 * UP TO 47 DIGITS, SO THE NUMBERS ARE KEPT DIGIT BY DIGIT
 * V1: FILL THE TABLE OF WAYS COLUMN BY COLUMN, USING ONLY ADDITIONS OF BIG NUMBERS
 * EXAMPLE: 1 2 -> 3; 2 3 -> 10 */
#include <stdio.h> /* PRINTF, FOPEN, FSCANF, FPRINTF */

#define MAXC 81 /* COORDINATES FROM 0 TO 80 */
#define MAXD 60 /* DIGITS OF A BIG NUMBER (THE LARGEST ANSWER HAS 47) */

int ways[MAXC][MAXD]; /* WAYS[J]: WAYS TO THE NODE AT HEIGHT J OF THIS COLUMN, UNITS DIGIT FIRST */
int len[MAXC];        /* HOW MANY DIGITS EACH OF THESE NUMBERS HAS */

/* WAYS[J] = WAYS[J] + WAYS[J - 1]: BEFORE THE ADDITION WAYS[J] HOLDS THE WAYS TO THE NODE ON
 * THE LEFT (THE COLUMN BEFORE), AND WAYS[J - 1] ALREADY HOLDS THE WAYS TO THE NODE BELOW */
void add_below(int j)
{
	int k, sum, carry = 0;
	int digits = len[j];

	if (len[j - 1] > digits)
	{
		digits = len[j - 1];
	}
	for (k = 0; k < digits; k++)
	{
		sum = ways[j][k] + ways[j - 1][k] + carry;
		ways[j][k] = sum % 10;
		carry = sum / 10;
	}
	if (carry > 0)
	{
		ways[j][digits] = carry;
		digits++;
	}
	len[j] = digits;
}

int main(void)
{
	FILE *in = fopen("SPIDER.IN", "r");
	FILE *out;
	int x = 0, y = 0, i, j, k;

	if (in == NULL)
	{
		printf("Cannot open SPIDER.IN\n");
		return 1;
	}
	fscanf(in, "%d %d", &x, &y);
	fclose(in);

	/* COLUMN 0: ONE WAY TO EVERY NODE, STRAIGHT UP */
	for (j = 0; j <= y; j++)
	{
		ways[j][0] = 1;
		len[j] = 1;
	}
	/* THE NEXT COLUMNS; WAYS[0] STAYS 1 (ONE WAY ALONG THE X AXIS) */
	for (i = 1; i <= x; i++)
	{
		for (j = 1; j <= y; j++)
		{
			add_below(j);
		}
	}

	out = fopen("SPIDER.OUT", "w");
	for (k = len[y] - 1; k >= 0; k--)
	{
		fprintf(out, "%d", ways[y][k]);
	}
	fprintf(out, "\n");
	fclose(out);

	return 0;
}
