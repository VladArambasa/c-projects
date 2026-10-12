/* CULEGERE VI.3.10 - THE TALLEST AND THE SHORTEST CHILD
 * THE HEIGHTS (IN CM) OF N CHILDREN ARE READ; PRINT THE HEIGHT OF THE TALLEST AND OF THE
 * SHORTEST CHILD AND THE DIFFERENCE BETWEEN THEM
 * EXAMPLE: N=5, 120 118 120 115 100 -> IMAX=120 CM IMIN=100 CM DIFFERENCE=20 CM
 * NOTE: THE BOOK'S EXAMPLE SAYS N=5 BUT LISTS 6 HEIGHTS (THE 6TH IS 117); THE RESULT IS THE SAME */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100

int main(void)
{
	int h[MAX] = {0};
	int n = 0, i, max, min;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d heights: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &h[i]);
	}

	max = h[0]; /* THE FIRST CHILD IS BOTH THE TALLEST AND THE SHORTEST SO FAR */
	min = h[0];
	for (i = 1; i < n; i++)
	{
		if (h[i] > max) /* A TALLER CHILD */
		{
			max = h[i];
		}
		if (h[i] < min) /* A SHORTER CHILD */
		{
			min = h[i];
		}
	}

	printf("imax=%d cm imin=%d cm difference=%d cm\n", max, min, max - min);

	return 0;
}
