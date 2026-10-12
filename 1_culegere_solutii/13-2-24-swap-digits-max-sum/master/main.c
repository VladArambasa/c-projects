/* CULEGERE XIII.2.24 - SWAP DIGITS FOR MAXIMUM SUM
 * TWO NUMBERS A AND B WITH AT MOST 8 DIGITS ARE READ. ONE DIGIT OF A AND ONE DIGIT OF B CHANGE
 * PLACES, GIVING TWO NEW NUMBERS A' AND B'. FIND A' AND B' FOR WHICH THE SUM A' + B' IS THE LARGEST
 * EXAMPLE: A = 23, B = 416 -> 63 AND 412 (THE FIRST DIGIT OF A WITH THE LAST DIGIT OF B)
 * ASSUMPTION: A SWAP MAY BRING A 0 IN FRONT (03 IS SIMPLY 3); IF SEVERAL SWAPS GIVE THE LARGEST
 * SUM, THE FIRST ONE TRIED IS KEPT (DIGITS OF A FROM THE LEFT, THEN DIGITS OF B FROM THE LEFT) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAXD 8

/* PUTS THE DIGITS OF N IN D, THE FIRST DIGIT IN D[0]; RETURNS HOW MANY DIGITS N HAS */
int get_digits(int n, int d[])
{
	int reversed[MAXD];
	int count = 0, i;

	do
	{
		reversed[count] = n % 10; /* THE DIGITS COME OUT FROM THE LAST ONE */
		n = n / 10;
		count++;
	} while (n > 0);
	for (i = 0; i < count; i++)
	{
		d[i] = reversed[count - 1 - i]; /* TURN THEM AROUND */
	}
	return count;
}

/* BUILDS THE NUMBER WRITTEN WITH THE DIGITS D[0], D[1], ..., D[COUNT - 1] */
int make_number(int d[], int count)
{
	int i, n = 0;

	for (i = 0; i < count; i++)
	{
		n = n * 10 + d[i];
	}
	return n;
}

int main(void)
{
	int da[MAXD], db[MAXD];
	int a = 0, b = 0, na, nb, i, j, aux, x, y;
	int best = -1, best_a = 0, best_b = 0;

	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);
	na = get_digits(a, da);
	nb = get_digits(b, db);

	/* TRY EVERY DIGIT OF A WITH EVERY DIGIT OF B */
	for (i = 0; i < na; i++)
	{
		for (j = 0; j < nb; j++)
		{
			aux = da[i]; /* SWAP THE TWO DIGITS */
			da[i] = db[j];
			db[j] = aux;
			x = make_number(da, na);
			y = make_number(db, nb);
			if (x + y > best)
			{
				best = x + y;
				best_a = x;
				best_b = y;
			}
			aux = da[i]; /* PUT THEM BACK FOR THE NEXT TRY */
			da[i] = db[j];
			db[j] = aux;
		}
	}
	printf("The maximum sum is obtained for %d and %d\n", best_a, best_b);
	return 0;
}
