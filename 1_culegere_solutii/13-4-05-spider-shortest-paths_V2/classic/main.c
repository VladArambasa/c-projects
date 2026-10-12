/* CULEGERE XIII.4.5 - SPIDER SHORTEST PATHS
 * THE NODES OF A NET LIE AT THE POINTS WITH INTEGER COORDINATES, EACH ONE JOINED TO ITS 4
 * NEIGHBOURS. A SPIDER STARTS AT (0, 0) AND EVERY SECOND MOVES TO A NEIGHBOUR NODE. SPIDER.IN
 * HOLDS X AND Y (0 < X, Y <= 80); WRITE IN SPIDER.OUT IN HOW MANY WAYS THE SPIDER CAN REACH (X, Y)
 * IN THE SHORTEST TIME. THE ANSWER HAS UP TO 47 DIGITS, SO THE NUMBERS ARE KEPT DIGIT BY DIGIT
 * IDEA: A SHORTEST WAY HAS X + Y STEPS, X OF THEM TO THE RIGHT AND Y UP; CHOOSING WHICH X STEPS GO
 * RIGHT GIVES THE BINOMIAL COEFFICIENT C(X + Y, X), BUILT AS C = C * (Y + I) / I FOR I = 1..X
 * V2: X MULTIPLICATIONS AND DIVISIONS OF ONE BIG NUMBER INSTEAD OF X * Y BIG NUMBER ADDITIONS
 * EXAMPLE: 1 2 -> 3; 2 3 -> 10 */
#include <stdio.h> /* PRINTF, FOPEN, FSCANF, FPRINTF */

#define MAXD 60 /* DIGITS OF THE BIG NUMBER (THE LARGEST ANSWER HAS 47) */

int number[MAXD]; /* THE BIG NUMBER, UNITS DIGIT FIRST */
int len;          /* HOW MANY DIGITS IT HAS */

/* NUMBER = NUMBER * M, FOR A SMALL NATURAL NUMBER M */
void multiply(int m)
{
	int k, product, carry = 0;

	for (k = 0; k < len; k++)
	{
		product = number[k] * m + carry;
		number[k] = product % 10;
		carry = product / 10;
	}
	while (carry > 0)
	{
		number[len] = carry % 10;
		len++;
		carry = carry / 10;
	}
}

/* NUMBER = NUMBER / D WHEN THE DIVISION IS EXACT, FROM THE FIRST DIGIT DOWN, AS ON PAPER */
void divide(int d)
{
	int k, rest = 0;

	for (k = len - 1; k >= 0; k--)
	{
		rest = rest * 10 + number[k];
		number[k] = rest / d;
		rest = rest % d;
	}
	while (len > 1 && number[len - 1] == 0)
	{
		len--; /* DROP THE ZEROS IN FRONT */
	}
}

int main(void)
{
	FILE *in = fopen("SPIDER.IN", "r");
	FILE *out;
	int x = 0, y = 0, i, k;

	if (in == NULL)
	{
		printf("Cannot open SPIDER.IN\n");
		return 1;
	}
	fscanf(in, "%d %d", &x, &y);
	fclose(in);

	/* AFTER STEP I THE NUMBER IS C(Y + I, I) */
	number[0] = 1;
	len = 1;
	for (i = 1; i <= x; i++)
	{
		multiply(y + i);
		divide(i);
	}

	out = fopen("SPIDER.OUT", "w");
	for (k = len - 1; k >= 0; k--)
	{
		fprintf(out, "%d", number[k]);
	}
	fprintf(out, "\n");
	fclose(out);

	return 0;
}
