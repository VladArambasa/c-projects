/* CULEGERE IX.1.7 - DISJOINT SETS
 * AT MOST 10 SETS OF BYTES (NUMBERS FROM 0 TO 255) ARE READ; CHECK WHETHER THEY ARE DISJOINT,
 * THAT IS WHETHER NO NUMBER BELONGS TO TWO OF THEM
 * EXAMPLE: 1 2 3 / 4 5 / 6 7 8 -> DISJOINT; 1 2 3 / 4 5 / 5 6 -> NOT DISJOINT (5 IS IN TWO SETS)
 * A SET IS AN ARRAY OF 256 FLAGS: SET[X] = 1 WHEN X BELONGS TO THE SET */
#include <stdio.h> /* PRINTF, SCANF */

#define MAXV 255 /* A BYTE HOLDS A NUMBER FROM 0 TO 255 */

/* READS SET NUMBER K: FIRST HOW MANY ELEMENTS IT HAS, THEN THE ELEMENTS */
void read_set(int k, int set[])
{
	int count = 0, element = 0, i;

	for (i = 0; i <= MAXV; i++)
	{
		set[i] = 0; /* START WITH THE EMPTY SET */
	}
	printf("Number of elements of set %d: ", k);
	scanf("%d", &count);
	printf("The elements of set %d: ", k);
	for (i = 0; i < count; i++)
	{
		scanf("%d", &element);
		set[element] = 1;
	}
}

int main(void)
{
	int set[MAXV + 1];
	int seen[MAXV + 1]; /* THE UNION OF THE SETS READ BEFORE THE CURRENT ONE */
	int n = 0, i, x, common = -1;

	printf("Number of sets: ");
	scanf("%d", &n);

	for (x = 0; x <= MAXV; x++)
	{
		seen[x] = 0;
	}
	for (i = 1; i <= n; i++)
	{
		read_set(i, set);
		for (x = 0; x <= MAXV; x++)
		{
			if (set[x] == 1 && seen[x] == 1 && common == -1)
			{
				common = x; /* X IS IN THIS SET AND ALSO IN AN EARLIER ONE */
			}
			seen[x] = seen[x] || set[x]; /* ADD THIS SET TO THE UNION */
		}
	}

	if (common == -1)
	{
		printf("The sets are disjoint\n");
	}
	else
	{
		printf("The sets are not disjoint: %d is in more than one set\n", common);
	}

	return 0;
}
