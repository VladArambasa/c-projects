/* CULEGERE X.1.2 - BOOKS ON THE THIRD SHELF
 * ON TWO SHELVES THE BOOKS STAND FROM LEFT TO RIGHT IN DECREASING ORDER OF THEIR HEIGHTS (IN CM).
 * MOVE ALL OF THEM ONTO A THIRD SHELF, ALSO IN DECREASING ORDER, AND PRINT THE HEIGHTS ON IT
 * EXAMPLE: 18 18 17 15 15 AND 15 14 12 -> 18 18 17 15 15 15 14 12 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100 /* AT MOST 100 BOOKS ON A SHELF */

int main(void)
{
	int a[MAX], b[MAX], c[2 * MAX];
	int n = 0, m = 0, i, j, k;

	printf("Number of books on the first shelf: ");
	scanf("%d", &n);
	printf("Heights: ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("Number of books on the second shelf: ");
	scanf("%d", &m);
	printf("Heights: ");
	for (j = 0; j < m; j++)
	{
		scanf("%d", &b[j]);
	}

	i = 0;
	j = 0;
	k = 0;
	while (i < n && j < m) /* THE TALLER OF THE TWO LEFTMOST BOOKS MOVES TO THE THIRD SHELF */
	{
		if (a[i] >= b[j])
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
	while (i < n) /* ONE SHELF IS EMPTY: MOVE THE BOOKS LEFT ON THE OTHER ONE */
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

	printf("Third shelf:");
	for (i = 0; i < k; i++)
	{
		printf(" %d", c[i]);
	}
	printf("\n");

	return 0;
}
