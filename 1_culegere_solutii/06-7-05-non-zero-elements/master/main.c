/* CULEGERE VI.7.5 - NON-ZERO ELEMENTS
 * BUILD AND PRINT THE VECTOR THAT HOLDS THE NON-ZERO ELEMENTS OF A GIVEN VECTOR
 * EXAMPLE (NOT IN THE BOOK): N=6, 0 3 0 -2 7 0 -> 3 -2 7 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100 /* AT MOST 100 NUMBERS */

int main(void)
{
	int a[MAX], b[MAX];
	int n = 0, m, i;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	m = 0; /* HOW MANY ELEMENTS THE NEW VECTOR B HAS */
	for (i = 0; i < n; i++)
	{
		if (a[i] != 0) /* A NON-ZERO ELEMENT IS ADDED AT THE END OF B */
		{
			b[m] = a[i];
			m++;
		}
	}

	for (i = 0; i < m; i++)
	{
		printf("%d ", b[i]);
	}
	printf("\n");

	return 0;
}
