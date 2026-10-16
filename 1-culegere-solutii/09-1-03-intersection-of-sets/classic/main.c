/* CULEGERE IX.1.3 - INTERSECTION OF N SETS
 * N SETS (1 <= N <= 30) OF NATURAL NUMBERS NOT GREATER THAN 255 ARE READ; PRINT THEIR INTERSECTION
 * EXAMPLE: 3 SETS: 1 2 3 4 5 / 2 4 7 1 / 4 5 2 9 -> INTERSECTION 2 4
 * A SET IS AN ARRAY OF 256 FLAGS: SET[X] = 1 WHEN X BELONGS TO THE SET */
#include <stdio.h> /* PRINTF, SCANF */

#define MAXV 255 /* THE ELEMENTS ARE NUMBERS FROM 0 TO 255 */

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
	int inter[MAXV + 1], set[MAXV + 1];
	int n = 0, i, x, empty = 1;

	printf("Number of sets: ");
	scanf("%d", &n);

	for (x = 0; x <= MAXV; x++)
	{
		inter[x] = 1; /* START WITH ALL THE NUMBERS; EVERY SET KEEPS ONLY ITS OWN */
	}
	for (i = 1; i <= n; i++)
	{
		read_set(i, set);
		for (x = 0; x <= MAXV; x++)
		{
			inter[x] = inter[x] && set[x]; /* X STAYS ONLY IF THIS SET HAS IT TOO */
		}
	}

	printf("intersection:");
	for (x = 0; x <= MAXV; x++)
	{
		if (inter[x] == 1)
		{
			printf(" %d", x);
			empty = 0;
		}
	}
	if (empty == 1)
	{
		printf(" empty set");
	}
	printf("\n");

	return 0;
}
