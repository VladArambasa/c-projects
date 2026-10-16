/* CULEGERE X.4.3 - THE MOST KNOWN PERSON
 * N PERSONS, NUMBERED FROM 1 TO N, ATTEND A SYMPOSIUM; PAIRS I J, MEANING THAT PERSON I KNOWS
 * PERSON J, ARE TYPED UNTIL THE END OF THE INPUT; PRINT THE PERSON KNOWN BY THE MOST PERSONS
 * EXAMPLE: N = 4, PAIRS 1 2, 1 3, 2 3, 4 3, 3 1, 4 2 -> PERSON 3, KNOWN BY 3 PERSONS
 * ASSUMPTION: A PAIR TYPED TWICE COUNTS ONCE (THE RELATION IS KEPT IN A 0/1 MATRIX)
 * ASSUMPTION: IF SEVERAL PERSONS ARE THE MOST KNOWN, ALL OF THEM ARE PRINTED; AT MOST 100 PERSONS
 * ASSUMPTION: THE INPUT ENDS WITH CTRL+Z (WINDOWS) OR CTRL+D (LINUX, MAC) */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100

int knows[MAX + 1][MAX + 1]; /* KNOWS[I][J] = 1 WHEN PERSON I KNOWS PERSON J */

int main(void)
{
	int known[MAX + 1] = {0}; /* KNOWN[J] = HOW MANY PERSONS KNOW PERSON J */
	int n = 0, i = 0, j = 0, max = 0;

	printf("n = ");
	scanf("%d", &n);
	printf("Pairs i j (end with Ctrl+Z on Windows or Ctrl+D on Linux/Mac):\n");
	/* SCANF RETURNS 2 AS LONG AS IT CAN READ ONE MORE PAIR */
	while (scanf("%d %d", &i, &j) == 2)
	{
		knows[i][j] = 1;
	}

	/* THE PERSONS WHO KNOW J ARE THE 1 VALUES ON COLUMN J; KEEP THE LARGEST COUNT */
	for (j = 1; j <= n; j++)
	{
		for (i = 1; i <= n; i++)
		{
			known[j] = known[j] + knows[i][j];
		}
		if (known[j] > max)
		{
			max = known[j];
		}
	}

	if (max == 0)
	{
		printf("Nobody knows anybody\n");
	}
	else
	{
		/* EVERY PERSON WITH THE LARGEST COUNT IS PRINTED */
		printf("Most known person(s):");
		for (j = 1; j <= n; j++)
		{
			if (known[j] == max)
			{
				printf(" %d", j);
			}
		}
		printf("\nKnown by %d person(s)\n", max);
	}

	return 0;
}
