/* CULEGERE VI.5.6 - INSERT AN ARRAY AFTER POSITION K
 * TWO ARRAYS WITH M AND N ELEMENTS AND A NUMBER K (K <= M) ARE READ; INSERT THE SECOND ARRAY
 * INTO THE FIRST ONE, AFTER POSITION K
 * ASSUMPTION: POSITIONS ARE COUNTED FROM 1, SO K = 0 PUTS THE SECOND ARRAY IN FRONT
 * EXAMPLE (NOT IN THE BOOK): M=5, 1 2 3 4 5, N=3, 7 8 9, K=2 -> 1 2 7 8 9 3 4 5 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100 /* AT MOST 100 ELEMENTS IN EACH ARRAY */

int main(void)
{
	int a[2 * MAX], b[MAX]; /* A ALSO NEEDS ROOM FOR THE ELEMENTS OF B */
	int m = 0, n = 0, k = 0, i;

	printf("m = ");
	scanf("%d", &m);
	printf("The %d elements of the first array: ", m);
	for (i = 0; i < m; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("n = ");
	scanf("%d", &n);
	printf("The %d elements of the second array: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
	}
	printf("k = ");
	scanf("%d", &k);

	/* THE ELEMENTS AFTER POSITION K (INDEXES K..M-1) MOVE N PLACES RIGHT.
	 * START WITH THE LAST ONE, SO THAT NO ELEMENT IS OVERWRITTEN BEFORE IT HAS BEEN MOVED */
	for (i = m - 1; i >= k; i--)
	{
		a[i + n] = a[i];
	}

	/* THE N FREE PLACES, INDEXES K..K+N-1, GET THE SECOND ARRAY */
	for (i = 0; i < n; i++)
	{
		a[k + i] = b[i];
	}
	m = m + n;

	for (i = 0; i < m; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
