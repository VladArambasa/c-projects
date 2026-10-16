/* CULEGERE VI.2.2 - THE FIRST K QUALIFIED
 * N SCORES OF A CONTEST ARE READ. PRINT THE FIRST K SCORES GREATER THAN B, THE SCORE NEEDED TO
 * QUALIFY. IF FEWER THAN K COMPETITORS SCORED MORE THAN B, ALSO PRINT "INSUFFICIENT CANDIDATES"
 * EXAMPLE: N=3, 45 23 78, K=2, B=50 -> 78 / INSUFFICIENT CANDIDATES
 * NOTE: THE BOOK'S EXAMPLE SAYS 78; THE CORRECT RESULT IS 78 AND THE MESSAGE, BECAUSE ONLY ONE
 * SCORE IS GREATER THAN 50 AND K=2 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100

int main(void)
{
	int score[MAX] = {0};
	int n = 0, k = 0, b = 0, i, found;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d scores: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &score[i]);
	}
	printf("k = ");
	scanf("%d", &k);
	printf("b = ");
	scanf("%d", &b);

	i = 0;
	found = 0;
	while (i < n && found < k) /* STOP WHEN K SCORES WERE FOUND OR THE SCORES ARE OVER */
	{
		if (score[i] > b) /* THIS COMPETITOR QUALIFIES */
		{
			printf("%d ", score[i]);
			found++;
		}
		i++;
	}
	printf("\n");

	if (found < k) /* THE SCORES ENDED BEFORE K QUALIFIED COMPETITORS WERE FOUND */
	{
		printf("Insufficient candidates\n");
	}

	return 0;
}
