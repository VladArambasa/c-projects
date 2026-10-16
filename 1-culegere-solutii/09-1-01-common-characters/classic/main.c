/* CULEGERE IX.1.1 - CHARACTERS COMMON TO ALL STRINGS
 * N STRINGS (1 <= N <= 30) OF LETTERS AND DIGITS ARE READ;
 * PRINT THE CHARACTERS USED IN EVERY STRING
 * (A CAPITAL LETTER AND A SMALL LETTER ARE DIFFERENT CHARACTERS)
 * EXAMPLE: N = 3, STRINGS AB12C, B2A9, 2BXA -> A B 2
 * NOTE: THE BOOK'S EXAMPLE SAYS A D S 1 2; THE CORRECT RESULT IS A A D S 1 2 (CAPITAL A, THEN
 * SMALL A, D, S), BECAUSE THE SMALL A IS ALSO IN ALL THREE OF THE BOOK'S STRINGS
 * A SET OF CHARACTERS IS AN ARRAY OF 0/1 FLAGS, ONE FLAG FOR EVERY CHARACTER CODE */
#include <stdio.h>  /* PRINTF, SCANF */
#include <string.h> /* STRLEN */

#define MAXLEN 256 /* A STRING HAS AT MOST 255 CHARACTERS */
#define CODES 128  /* THE ASCII CODES 0..127, ONE FLAG FOR EACH */

/* PRINTS THE CHARACTERS FROM FIRST TO LAST THAT BELONG TO THE SET; RETURNS HOW MANY IT PRINTED */
int print_range(int set[], int first, int last)
{
	int c, count = 0;

	for (c = first; c <= last; c++)
	{
		if (set[c] == 1)
		{
			printf(" %c", c);
			count++;
		}
	}
	return count;
}

int main(void)
{
	char s[MAXLEN] = "";
	int common[CODES];  /* THE CHARACTERS FOUND IN EVERY STRING READ SO FAR */
	int present[CODES]; /* THE CHARACTERS OF THE CURRENT STRING */
	int n = 0, i, j, c, len, count;

	printf("n = ");
	scanf("%d", &n);

	for (c = 0; c < CODES; c++)
	{
		common[c] = 1; /* BEFORE THE FIRST STRING EVERY CHARACTER IS STILL POSSIBLE */
	}
	for (i = 1; i <= n; i++)
	{
		printf("String %d: ", i);
		scanf("%255s", s);

		for (c = 0; c < CODES; c++)
		{
			present[c] = 0; /* THE SET OF THIS STRING STARTS EMPTY */
		}
		len = strlen(s);
		for (j = 0; j < len; j++)
		{
			present[(int)s[j]] = 1; /* THE CHARACTER CODE IS THE INDEX */
		}

		for (c = 0; c < CODES; c++)
		{
			common[c] = common[c] && present[c]; /* INTERSECTION OF THE TWO SETS */
		}
	}

	/* CAPITAL LETTERS, THEN SMALL LETTERS, THEN DIGITS, AS IN THE BOOK */
	printf("Common characters:");
	count = print_range(common, 'A', 'Z');
	count = count + print_range(common, 'a', 'z');
	count = count + print_range(common, '0', '9');
	if (count == 0)
	{
		printf(" none");
	}
	printf("\n");

	return 0;
}
