/* CULEGERE VI.5.5 - MOVE A VALUE TO THE END
 * N NUMBERS AND A VALUE V ARE READ; MOVE ALL THE ELEMENTS EQUAL TO V TO THE END OF THE SEQUENCE
 * (THE OTHER ELEMENTS KEEP THEIR ORDER, AS IN THE EXAMPLE)
 * V2: ONE PASS COPIES THE OTHER ELEMENTS TO THE FRONT, IN ORDER; THEN THE END IS FILLED WITH V
 * EXAMPLE: N=4, V=5, 5 6 5 3 -> 6 3 5 5 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100 /* AT MOST 100 NUMBERS */

int main(void)
{
	int a[MAX];
	int n = 0, v = 0, i, k;

	printf("n = ");
	scanf("%d", &n);
	printf("v = ");
	scanf("%d", &v);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	k = 0; /* THE ELEMENTS DIFFERENT FROM V FOUND SO FAR ARE ALREADY IN A[0..K-1] */
	for (i = 0; i < n; i++)
	{
		if (a[i] != v)
		{
			a[k] = a[i]; /* K <= I, SO NO ELEMENT IS OVERWRITTEN BEFORE IT IS READ */
			k++;
		}
	}
	for (i = k; i < n; i++) /* THE N - K PLACES LEFT AT THE END GET V */
	{
		a[i] = v;
	}

	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
