/* CULEGERE IX.2.4 - STATISTICS OF THE QUALIFIERS
 * IN A CLASS OF AT MOST 25 PUPILS, EVERY PUPIL GOT ONE OF THE QUALIFIERS SUFFICIENT, GOOD
 * OR VERY GOOD IN EACH OF THE 10 SUBJECTS; FOR EVERY PUPIL THE NAME AND THE NUMBER OF EACH
 * QUALIFIER ARE READ. PRINT THE CLASS STATISTICS (HOW MANY SUFFICIENT, GOOD, VERY GOOD) IN
 * DECREASING ORDER AND THE NAME OF THE PUPIL WITH THE MOST VERY GOOD QUALIFIERS
 * ASSUMPTION: A NAME IS ONE WORD; ON A TIE FOR THE MOST VERY GOOD, THE FIRST PUPIL READ IS PRINTED
 * EXAMPLE: ANA 1 3 6, BOGDAN 2 5 3, CARMEN 0 2 8, DAN 4 4 2
 *          -> VERY GOOD: 19, GOOD: 14, SUFFICIENT: 7, MOST VERY GOOD QUALIFIERS: CARMEN */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 25 /* AT MOST 25 PUPILS */

struct pupil
{
	char name[31];
	int sufficient; /* HOW MANY QUALIFIERS OF EACH KIND */
	int good;
	int very_good;
};

struct statistic
{
	char label[12];
	int count;
};

int main(void)
{
	struct pupil p[MAX];
	struct statistic st[3] = {{"sufficient", 0}, {"good", 0}, {"very good", 0}};
	struct statistic temp;
	int n = 0, i, j, best = 0;

	printf("Number of pupils: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("Pupil %d (name, sufficient, good, very good): ", i + 1);
		scanf("%30s", p[i].name);
		scanf("%d %d %d", &p[i].sufficient, &p[i].good, &p[i].very_good);

		st[0].count = st[0].count + p[i].sufficient; /* THE TOTALS OF THE CLASS */
		st[1].count = st[1].count + p[i].good;
		st[2].count = st[2].count + p[i].very_good;
		if (p[i].very_good > p[best].very_good)
		{
			best = i; /* A TIE DOES NOT CHANGE THE BEST, SO THE FIRST ONE STAYS */
		}
	}

	/* BUBBLE SORT OF THE THREE RECORDS, DECREASING BY THEIR COUNT */
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2 - i; j++)
		{
			if (st[j].count < st[j + 1].count)
			{
				temp = st[j];
				st[j] = st[j + 1];
				st[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		printf("%s: %d\n", st[i].label, st[i].count);
	}
	printf("Most very good qualifiers: %s\n", p[best].name);

	return 0;
}
