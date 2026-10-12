/* CULEGERE XIII.2.20 - VERTICAL WORD
 * TWO SETS OF WORDS M1 AND M2 AND A NUMBER K ARE READ. ARRANGE THE WORDS OF M1 ONE UNDER ANOTHER
 * SO THAT THEIR LETTERS ON POSITION K SPELL, FROM TOP TO BOTTOM, A WORD OF M2; PRINT THE WORDS OF
 * M1 IN THAT ORDER
 * EXAMPLE: M1 = CARTE ACESTA ARID RAC, M2 = CUTIE ABAC ACAR CORT, K = 2 -> CARTE ACESTA RAC ARID
 * ASSUMPTION: ONE ARRANGEMENT IS PRINTED, FOR THE FIRST WORD OF M2 THAT CAN BE SPELLED
 * IMPROVEMENT: TAKE THE FIRST FREE WORD WITH THE NEEDED K-TH LETTER; NO BACKTRACKING IS NEEDED */
#include <stdio.h>  /* PRINTF, SCANF */
#include <string.h> /* STRLEN */

#define MAXW 10   /* AT MOST 10 WORDS IN A SET */
#define MAXLEN 21 /* AT MOST 20 LETTERS IN A WORD */

char m1[MAXW][MAXLEN], m2[MAXW][MAXLEN];
int n1, n2, k;
int used[MAXW];  /* USED[I] = 1 IF WORD I OF M1 IS ALREADY PLACED */
int order[MAXW]; /* ORDER[P] = THE WORD OF M1 WRITTEN ON ROW P */

/* THE LETTER ON POSITION K OF WORD I OF M1, OR 0 IF THE WORD IS SHORTER THAN K */
char letter_k(int i)
{
	int len = strlen(m1[i]);

	if (k < 1 || len < k)
	{
		return 0;
	}
	return m1[i][k - 1];
}

/* TRIES TO SPELL WORD T OF M2: EACH ROW GETS THE FIRST FREE WORD WITH THE NEEDED LETTER.
 * WORDS WITH THE SAME K-TH LETTER CAN TAKE EACH OTHER'S PLACE, SO THIS CHOICE IS NEVER A MISTAKE.
 * RETURNS 1 IF THE WORD IS SPELLED, 0 IF SOME LETTER CANNOT BE FOUND */
int arrange(int t)
{
	int pos, i, ok;

	for (i = 0; i < n1; i++)
	{
		used[i] = 0;
	}
	for (pos = 0; pos < n1; pos++)
	{
		ok = 0;
		for (i = 0; i < n1 && ok == 0; i++)
		{
			if (used[i] == 0 && letter_k(i) == m2[t][pos])
			{
				used[i] = 1;
				order[pos] = i;
				ok = 1;
			}
		}
		if (ok == 0)
		{
			return 0; /* NO FREE WORD HAS THIS LETTER */
		}
	}
	return 1;
}

int main(void)
{
	int i, t, len, found = 0;

	/* READ THE TWO SETS OF WORDS AND THE POSITION K */
	printf("Number of words in M1: ");
	scanf("%d", &n1);
	printf("The %d words of M1: ", n1);
	for (i = 0; i < n1; i++)
	{
		scanf("%20s", m1[i]);
	}
	printf("Number of words in M2: ");
	scanf("%d", &n2);
	printf("The %d words of M2: ", n2);
	for (i = 0; i < n2; i++)
	{
		scanf("%20s", m2[i]);
	}
	printf("k = ");
	scanf("%d", &k);

	for (t = 0; t < n2 && found == 0; t++)
	{
		len = strlen(m2[t]);
		if (len == n1 && arrange(t) == 1) /* ONE LETTER FROM EACH WORD OF M1 */
		{
			found = 1;
		}
	}

	if (found == 1)
	{
		for (i = 0; i < n1; i++)
		{
			printf("%s\n", m1[order[i]]); /* THE WORDS OF M1 IN THE ORDER FOUND */
		}
	}
	else
	{
		printf("No solution\n");
	}
	return 0;
}
