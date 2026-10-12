/* CULEGERE X.4.1 - CELEBRITY IN A GROUP
 * A CELEBRITY IS A PERSON KNOWN BY EVERYBODY WHO KNOWS NOBODY; THE RELATIONS BETWEEN THE N
 * PERSONS OF A GROUP ARE KNOWN: FIND THE CELEBRITY, IF THERE IS ONE
 * EXAMPLE: N = 4, ROWS 0 1 1 0 / 0 0 1 1 / 0 0 0 0 / 1 0 1 0 -> PERSON 3 IS THE CELEBRITY
 * ASSUMPTION: THE RELATIONS ARE TYPED AS AN N X N MATRIX: 1 ON ROW I, COLUMN J MEANS THAT
 * PERSON I KNOWS PERSON J (THE DIAGONAL IS IGNORED); AT MOST 100 PERSONS */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100

int knows[MAX + 1][MAX + 1]; /* KNOWS[I][J] = 1 WHEN PERSON I KNOWS PERSON J */

/* 1 IF PERSON P IS KNOWN BY ALL THE OTHERS AND KNOWS NONE OF THEM */
int is_celebrity(int n, int p)
{
	int i;

	for (i = 1; i <= n; i++)
	{
		if (i != p && (knows[i][p] == 0 || knows[p][i] == 1))
		{
			return 0; /* I DOES NOT KNOW P, OR P KNOWS I */
		}
	}
	return 1;
}

int main(void)
{
	int n = 0, i, j, celebrity = 0;

	printf("n = ");
	scanf("%d", &n);
	printf("The relation matrix, row by row (1 = knows, 0 = does not know):\n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &knows[i][j]);
		}
	}

	/* TEST EVERY PERSON; AT MOST ONE CAN PASS, BECAUSE A SECOND CELEBRITY
	 * WOULD BE KNOWN BY THE FIRST ONE, WHO KNOWS NOBODY */
	for (i = 1; i <= n; i++)
	{
		if (is_celebrity(n, i))
		{
			celebrity = i;
		}
	}

	if (celebrity > 0)
	{
		printf("Person %d is the celebrity\n", celebrity);
	}
	else
	{
		printf("There is no celebrity\n");
	}

	return 0;
}
