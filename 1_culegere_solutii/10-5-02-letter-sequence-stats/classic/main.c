/* CULEGERE X.5.2 - LETTER SEQUENCE STATISTICS
 * OLIMP71.INP HOLDS N AND A STRING OF N LETTERS C1 C2 ... CN (AT MOST 255 LETTERS OF THE ENGLISH
 * ALPHABET); PRINT ON THE SCREEN:
 * A) THE POSITION P AND THE LENGTH L OF THE LONGEST RUN OF EQUAL LETTERS STANDING TOGETHER;
 * B) THE DISTINCT LETTERS AND HOW MANY TIMES EACH ONE APPEARS;
 * C) IN HOW MANY WAYS 3 DIFFERENT LETTERS, CHOSEN FROM THE DISTINCT ONES, CAN BE ARRANGED
 * EXAMPLE: 6 ABBACX -> A) P=2 L=2  B) A B C X / 2 2 1 1  C) 24
 * ASSUMPTION: THE LETTERS ARE SMALL LETTERS, AS IN THE EXAMPLE; BLANKS BETWEEN THEM ARE SKIPPED
 * ASSUMPTION: OF SEVERAL LONGEST RUNS THE FIRST ONE IS GIVEN; B) LISTS THE LETTERS IN
 * ALPHABETICAL ORDER */
#include <stdio.h> /* FOPEN, FSCANF, FCLOSE, PRINTF */

#define MAX 255

int main(void)
{
	FILE *in;
	char c[MAX + 1] = ""; /* THE LETTERS, IN C[1] ... C[N] */
	int freq[26] = {0};   /* FREQ[0] COUNTS THE LETTER A, FREQ[1] THE LETTER B, ... */
	int n = 0, i, p = 0, l = 0, start = 0, run = 0, k = 0;

	in = fopen("olimp71.inp", "r");
	if (in == NULL)
	{
		printf("Cannot open olimp71.inp\n");
		return 1;
	}
	fscanf(in, "%d", &n);
	for (i = 1; i <= n; i++)
	{
		fscanf(in, " %c", &c[i]); /* THE BLANK IN THE FORMAT SKIPS SPACES AND NEW LINES */
	}
	fclose(in);

	/* A) A RUN GOES ON WHILE A LETTER EQUALS THE ONE BEFORE IT; ONLY A STRICTLY
	 * LONGER RUN REPLACES THE BEST ONE, SO THE FIRST LONGEST RUN IS KEPT */
	for (i = 1; i <= n; i++)
	{
		if (i > 1 && c[i] == c[i - 1])
		{
			run++;
		}
		else
		{
			start = i;
			run = 1;
		}
		if (run > l)
		{
			l = run;
			p = start;
		}
	}
	printf("a) p=%d l=%d\n", p, l);

	/* B) COUNT EVERY LETTER, THEN LIST THE LETTERS THAT APPEAR AND, BELOW THEM, THEIR COUNTS */
	for (i = 1; i <= n; i++)
	{
		freq[c[i] - 'a']++;
	}
	printf("b)");
	for (i = 0; i < 26; i++)
	{
		if (freq[i] > 0)
		{
			printf("%3c", 'a' + i);
			k++; /* K = HOW MANY DISTINCT LETTERS */
		}
	}
	printf("\n  ");
	for (i = 0; i < 26; i++)
	{
		if (freq[i] > 0)
		{
			printf("%3d", freq[i]);
		}
	}
	printf("\n");

	/* C) ARRANGEMENTS OF K LETTERS TAKEN 3 AT A TIME: K CHOICES FOR THE FIRST LETTER,
	 * K - 1 FOR THE SECOND, K - 2 FOR THE THIRD (THE PRODUCT IS 0 WHEN K < 3) */
	printf("c) %d\n", k * (k - 1) * (k - 2));

	return 0;
}
