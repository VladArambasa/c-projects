/* CULEGERE VI.3.16 - SANTA'S GIFTS
 * SANTA GIVES EACH OF THE N CHILDREN A GIFT OF A CERTAIN VALUE (IN LEI). PRINT HOW MUCH SANTA
 * SPENT IN MOSI (1 LEU = 6 MOSI) AND WHETHER HE HAS A FAVOURITE CHILD, ONE WHOSE GIFT IS WORTH
 * MORE THAN ALL THE OTHER GIFTS TOGETHER: PRINT YES AND THE NUMBER OF THAT CHILD, OR NO
 * EXAMPLE: N=5, 10 50 6 5 20 -> SANTA SPENT 546 MOSI / YES 2 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100

int main(void)
{
	int gift[MAX] = {0};
	int n = 0, i;
	int sum = 0;
	int favourite = 0; /* THE NUMBER OF THE FAVOURITE CHILD, 0 IF THERE IS NONE */

	printf("n = ");
	scanf("%d", &n);
	printf("The %d gift values: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &gift[i]);
	}

	for (i = 0; i < n; i++)
	{
		sum = sum + gift[i];
	}
	printf("Santa spent %d mosi\n", sum * 6); /* 1 LEU = 6 MOSI */

	for (i = 0; i < n; i++)
	{
		if (gift[i] > sum - gift[i]) /* MORE THAN ALL THE OTHER GIFTS TOGETHER */
		{
			favourite = i + 1;
		}
	}

	if (favourite > 0)
	{
		printf("YES %d\n", favourite);
	}
	else
	{
		printf("NO\n");
	}

	return 0;
}
