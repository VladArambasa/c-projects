/* CULEGERE III.9.11 - PAGES WITH PICTURES (V1)
 * A BOOK HAS N PAGES; THE PAGES WHOSE NUMBER IS DIVISIBLE BY K BUT NOT BY H HAVE PICTURES.
 * READ N, K, H AND PRINT THE LAST DIGIT OF THE SUM OF THE NUMBERS OF THE PAGES WITH PICTURES,
 * OR IMPOSSIBLE! IF NO PAGE HAS A PICTURE. LIMITS: 0 < N <= 1000000000, 0 < K, H <= N
 * V1: CHECK EVERY PAGE, ONE BY ONE (A BILLION STEPS FOR THE LARGEST N)
 * EXAMPLE: N=20 K=3 H=2 -> 7 (PAGES 3, 9 AND 15; 3 + 9 + 15 = 27) */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0, k = 0, h = 0, page;
	int last = 0;  /* THE LAST DIGIT OF THE SUM SO FAR */
	int found = 0; /* BECOMES 1 WHEN A PAGE WITH A PICTURE IS FOUND */

	printf("N = ");
	scanf("%d", &n);
	printf("K = ");
	scanf("%d", &k);
	printf("H = ");
	scanf("%d", &h);

	for (page = 1; page <= n; page++)
	{
		if (page % k == 0 && page % h != 0) /* THIS PAGE HAS A PICTURE */
		{
			last = (last + page % 10) % 10; /* ONLY THE LAST DIGIT OF THE SUM MATTERS */
			found = 1;
		}
	}

	if (found == 1)
	{
		printf("%d\n", last);
	}
	else
	{
		printf("Impossible!\n");
	}

	return 0;
}
