/* CULEGERE IX.1.2 - UNION, INTERSECTION AND DIFFERENCE
 * TWO SETS A AND B OF NATURAL NUMBERS NOT GREATER THAN 255 ARE READ;
 * PRINT THEIR UNION, THEIR INTERSECTION AND THE DIFFERENCE A - B
 * EXAMPLE: A = 1 2 3 4 7 5, B = 4 5 8 -> UNION 1 2 3 4 5 7 8, INTERSECTION 4 5, DIFFERENCE 1 2 3 7
 * A SET IS AN ARRAY OF 256 FLAGS: SET[X] = 1 WHEN X BELONGS TO THE SET */
#include <stdio.h> /* PRINTF, SCANF */

#define MAXV 255 /* THE ELEMENTS ARE NUMBERS FROM 0 TO 255 */

/* READS THE SET CALLED NAME: FIRST HOW MANY ELEMENTS IT HAS, THEN THE ELEMENTS */
void read_set(char name, int set[])
{
	int count = 0, element = 0, i;

	for (i = 0; i <= MAXV; i++)
	{
		set[i] = 0; /* START WITH THE EMPTY SET */
	}
	printf("Number of elements of %c: ", name);
	scanf("%d", &count);
	printf("The elements of %c: ", name);
	for (i = 0; i < count; i++)
	{
		scanf("%d", &element);
		set[element] = 1; /* THE ELEMENT BELONGS TO THE SET */
	}
}

/* PRINTS THE LABEL, THEN THE ELEMENTS OF THE SET IN INCREASING ORDER */
void print_set(char label[], int set[])
{
	int x, empty = 1;

	printf("%s:", label);
	for (x = 0; x <= MAXV; x++)
	{
		if (set[x] == 1)
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
}

int main(void)
{
	int a[MAXV + 1], b[MAXV + 1], result[MAXV + 1];
	int x;

	read_set('a', a);
	read_set('b', b);

	for (x = 0; x <= MAXV; x++)
	{
		result[x] = a[x] || b[x]; /* IN A OR IN B */
	}
	print_set("union", result);

	for (x = 0; x <= MAXV; x++)
	{
		result[x] = a[x] && b[x]; /* IN A AND IN B */
	}
	print_set("intersection", result);

	for (x = 0; x <= MAXV; x++)
	{
		result[x] = a[x] && !b[x]; /* IN A, BUT NOT IN B */
	}
	print_set("difference", result);

	return 0;
}
