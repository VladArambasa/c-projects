/* CULEGERE VI.7.4 - DISTINCT ELEMENTS
 * N INTEGERS ARE READ; STORE THE DIFFERENT VALUES IN ANOTHER VECTOR (EVERY VALUE ONCE) AND
 * PRINT THAT VECTOR
 * ASSUMPTION: THE VALUES KEEP THE ORDER IN WHICH THEY FIRST APPEAR
 * EXAMPLE: N=4, 1 2 2 1 -> 1 2 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100 /* AT MOST 100 NUMBERS */

int main(void)
{
	int a[MAX], b[MAX];
	int n = 0, m, i, j, found;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	m = 0; /* HOW MANY VALUES B HOLDS; B IS EMPTY AT FIRST */
	for (i = 0; i < n; i++)
	{
		found = 0;
		for (j = 0; j < m; j++) /* IS A[I] ALREADY IN B? */
		{
			if (b[j] == a[i])
			{
				found = 1;
			}
		}
		if (found == 0) /* A NEW VALUE: ADD IT AT THE END OF B */
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
