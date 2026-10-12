/* CULEGERE XIII.2.20 - VERTICAL WORD
 * TWO SETS OF WORDS M1 AND M2 AND A NUMBER K ARE READ. ARRANGE THE WORDS OF M1 ONE UNDER ANOTHER
 * SO THAT THEIR LETTERS ON POSITION K SPELL, FROM TOP TO BOTTOM, A WORD OF M2; PRINT THE WORDS OF
 * M1 IN THAT ORDER
 * EXAMPLE: M1 = CARTE ACESTA ARID RAC, M2 = CUTIE ABAC ACAR CORT, K = 2 -> CARTE ACESTA RAC ARID
 * ASSUMPTION: ONE ARRANGEMENT IS PRINTED, FOR THE FIRST WORD OF M2 THAT CAN BE SPELLED
 * METHOD: FOR EACH WORD OF M2, TRY THE ORDERS OF THE WORDS OF M1 BY BACKTRACKING */
#include <stdio.h>  /* PRINTF, SCANF */
#include <string.h> /* STRLEN */

#define MAXW 10   /* AT MOST 10 WORDS IN A SET */
#define MAXLEN 21 /* AT MOST 20 LETTERS IN A WORD */

char m1[MAXW][MAXLEN], m2[MAXW][MAXLEN];
int n1, n2, k;
int used[MAXW];  /* USED[I] = 1 IF WORD I OF M1 IS ALREADY PLACED */
int order[MAXW]; /* ORDER[P] = THE WORD OF M1 WRITTEN ON ROW P */
int target;      /* THE WORD OF M2 THAT WE TRY TO SPELL */
int found;

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

/* CHOOSES THE WORD FOR ROW POS, THEN GOES ON WITH THE NEXT ROWS (BACKTRACKING) */
void place(int pos)
{
	int i;

	if (pos == n1)
	{
		found = 1; /* ALL THE ROWS ARE FILLED: THE TARGET WORD IS SPELLED */
		return;
	}
	for (i = 0; i < n1 && found == 0; i++)
	{
		/* A FREE WORD WHOSE K-TH LETTER IS THE NEXT LETTER OF THE TARGET WORD */
		if (used[i] == 0 && letter_k(i) == m2[target][pos])
		{
			used[i] = 1;
			order[pos] = i;
			place(pos + 1);
			used[i] = 0; /* TAKE IT BACK AND TRY ANOTHER WORD ON THIS ROW */
		}
	}
}

int main(void)
{
	int i, len;

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

	found = 0;
	for (target = 0; target < n2 && found == 0; target++)
	{
		len = strlen(m2[target]);
		if (len == n1) /* THE TARGET NEEDS EXACTLY ONE LETTER FROM EACH WORD OF M1 */
		{
			place(0);
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
