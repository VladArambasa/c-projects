/* CULEGERE VI.5.4 - REMOVE THE ZEROS
 * COMPACT A VECTOR OF N INTEGERS: EVERY ELEMENT EQUAL TO 0 IS REMOVED AND ALL THE ELEMENTS TO
 * ITS RIGHT MOVE ONE POSITION LEFT, INTO ITS PLACE
 * V2: ONE PASS: EVERY NON-ZERO ELEMENT IS COPIED STRAIGHT TO THE FIRST FREE PLACE AT THE FRONT
 * EXAMPLE: N=4, 9 0 0 5 -> 9 5 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100 /* AT MOST 100 NUMBERS */

int main(void)
{
	int a[MAX];
	int n = 0, i, k;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	k = 0; /* THE NON-ZERO ELEMENTS FOUND SO FAR ARE ALREADY IN A[0..K-1] */
	for (i = 0; i < n; i++)
	{
		if (a[i] != 0)
		{
			a[k] = a[i]; /* K <= I, SO NO ELEMENT IS OVERWRITTEN BEFORE IT IS READ */
			k++;
		}
	}
	n = k; /* ONLY THE NON-ZERO ELEMENTS REMAIN */

	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
