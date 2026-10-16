/* CULEGERE VI.7.12 - ELEMENT AT POSITION K
 * IN THE SEQUENCE 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, ... EVERY NUMBER V IS WRITTEN V TIMES.
 * READ K AND PRINT THE ELEMENT ON POSITION K
 * V1: BUILD THE VECTOR OF THE FIRST K TERMS, THEN PRINT THE LAST ONE
 * ASSUMPTION: K <= 10000, THE SIZE OF THE VECTOR
 * EXAMPLE (NOT IN THE BOOK): K=7 -> 4 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 10000 /* K <= 10000 */

int main(void)
{
	int a[MAX + 1]; /* A[1..K]: POSITIONS ARE COUNTED FROM 1, A[0] IS NOT USED */
	int k = 0, len, v, j;

	printf("k = ");
	scanf("%d", &k);

	len = 0; /* HOW MANY TERMS ARE ALREADY WRITTEN */
	v = 1;
	while (len < k)
	{
		for (j = 1; j <= v && len < k; j++) /* WRITE V, V TIMES, BUT NOT PAST POSITION K */
		{
			len++;
			a[len] = v;
		}
		v++;
	}

	printf("%d\n", a[k]);

	return 0;
}
