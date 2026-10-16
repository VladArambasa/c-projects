/* CULEGERE VI.3.20 - THE APPLE SELLERS
 * X CHILDREN GO TO A MARKET WITH N APPLE SELLERS. THEY BUY ONLY FROM SELLERS WHO HAVE AT LEAST
 * 3 APPLES FOR EVERY CHILD. READ HOW MANY APPLES EACH SELLER HAS; HOW MANY SELLERS QUALIFY?
 * EXAMPLE: X=25, N=5, 280 456 78 50 75 -> 4 SELLERS */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100

int main(void)
{
	int apples[MAX] = {0};
	int x = 0, n = 0, i;
	int count = 0;

	printf("x = ");
	scanf("%d", &x);
	printf("n = ");
	scanf("%d", &n);
	printf("Apples of the %d sellers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &apples[i]);
	}

	for (i = 0; i < n; i++)
	{
		if (apples[i] >= 3 * x) /* 3 APPLES FOR EACH OF THE X CHILDREN */
		{
			count++;
		}
	}

	printf("%d %s\n", count, (count == 1) ? "seller" : "sellers");

	return 0;
}
