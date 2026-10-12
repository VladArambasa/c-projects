/* CULEGERE VI.4.4 - COUNT EACH CHARACTER
 * N CHARACTERS ARE READ; SORT THEM, THEN PRINT HOW MANY TIMES EACH CHARACTER APPEARS
 * ASSUMPTION: THE CHARACTERS ARE TYPED SEPARATED BY SPACES, SO A SPACE IS NEVER AN ELEMENT
 * ASSUMPTION: THE COUNTS ARE PRINTED IN SORTED (ASCII) ORDER, SO DIGITS COME BEFORE LETTERS;
 * THE BOOK'S EXAMPLE GIVES THE SAME COUNTS IN THE ORDER A, G, 4
 * EXAMPLE (THE LETTERS ARE LOWERCASE): N=4, A 4 G A -> 4 APPEARS 1 TIME(S),
 * A APPEARS 2 TIME(S), G APPEARS 1 TIME(S) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100 /* AT MOST 100 CHARACTERS */

int main(void)
{
	char c[MAX], temp;
	int n = 0, i, j, count;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d characters: ", n);
	for (i = 0; i < n; i++)
	{
		scanf(" %c", &c[i]); /* THE SPACE BEFORE %C SKIPS SPACES AND NEW LINES */
	}

	/* BUBBLE SORT: CHARACTERS ARE COMPARED BY THEIR ASCII CODES */
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (c[j] > c[j + 1])
			{
				temp = c[j];
				c[j] = c[j + 1];
				c[j + 1] = temp;
			}
		}
	}

	/* NOW EQUAL CHARACTERS ARE NEIGHBOURS: COUNT EVERY GROUP OF EQUAL NEIGHBOURS */
	count = 1;
	for (i = 1; i < n; i++)
	{
		if (c[i] == c[i - 1])
		{
			count++;
		}
		else /* A NEW GROUP STARTS: PRINT THE ONE THAT HAS JUST ENDED */
		{
			printf("%c appears %d time(s)\n", c[i - 1], count);
			count = 1;
		}
	}
	printf("%c appears %d time(s)\n", c[n - 1], count); /* THE LAST GROUP */

	return 0;
}
