/* CULEGERE VI.5.3 - INSERT INTO A SORTED VECTOR
 * N NUMBERS IN ASCENDING ORDER AND A NUMBER K ARE READ; INSERT K SO THAT THE VECTOR STAYS SORTED
 * EXAMPLE: N=4, K=100, 90 95 110 120 -> 90 95 100 110 120 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100 /* AT MOST 100 NUMBERS */

int main(void)
{
	int a[MAX + 1]; /* ONE EXTRA PLACE FOR K */
	int n = 0, k = 0, i;

	printf("n = ");
	scanf("%d", &n);
	printf("k = ");
	scanf("%d", &k);
	printf("The %d numbers (in ascending order): ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	/* FROM THE END, EVERY ELEMENT LARGER THAN K MOVES ONE PLACE RIGHT */
	i = n - 1;
	while (i >= 0 && a[i] > k)
	{
		a[i + 1] = a[i];
		i--;
	}
	a[i + 1] = k; /* K GOES RIGHT AFTER THE LAST ELEMENT THAT IS NOT LARGER THAN K */
	n++;

	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
