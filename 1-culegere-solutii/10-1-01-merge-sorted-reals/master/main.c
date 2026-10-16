/* CULEGERE X.1.1 - MERGE TWO SORTED SEQUENCES
 * TWO SEQUENCES OF REAL NUMBERS, BOTH SORTED INCREASINGLY, ARE MERGED:
 * A NEW SORTED SEQUENCE IS BUILT FROM ALL THEIR ELEMENTS
 * EXAMPLE: 3 6 9 AND 1 2 5 9 -> 1 2 3 5 6 9 9
 * NOTE: THE BOOK'S EXAMPLE SAYS 1 2 3 5 6 9; THE CORRECT RESULT IS 1 2 3 5 6 9 9 (THE NEW SEQUENCE
 * HOLDS ALL THE ELEMENTS, SO THE 9 OF EACH SEQUENCE APPEARS) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100 /* AT MOST 100 NUMBERS IN EACH SEQUENCE */

int main(void)
{
	double a[MAX], b[MAX], c[2 * MAX];
	int n = 0, m = 0, i, j, k;

	printf("Number of elements of the first sequence: ");
	scanf("%d", &n);
	printf("The first sequence: ");
	for (i = 0; i < n; i++)
	{
		scanf("%lf", &a[i]);
	}
	printf("Number of elements of the second sequence: ");
	scanf("%d", &m);
	printf("The second sequence: ");
	for (j = 0; j < m; j++)
	{
		scanf("%lf", &b[j]);
	}

	i = 0;
	j = 0;
	k = 0;
	while (i < n && j < m) /* THE SMALLER OF THE TWO FIRST ELEMENTS GOES TO C */
	{
		if (a[i] <= b[j])
		{
			c[k] = a[i];
			i++;
		}
		else
		{
			c[k] = b[j];
			j++;
		}
		k++;
	}
	while (i < n) /* ONE SEQUENCE IS USED UP: COPY WHAT IS LEFT OF THE OTHER */
	{
		c[k] = a[i];
		i++;
		k++;
	}
	while (j < m)
	{
		c[k] = b[j];
		j++;
		k++;
	}

	printf("Merged sequence:");
	for (i = 0; i < k; i++)
	{
		printf(" %g", c[i]); /* PRINTS 3 AS 3 AND 2.5 AS 2.5, WITHOUT USELESS ZEROS */
	}
	printf("\n");

	return 0;
}
