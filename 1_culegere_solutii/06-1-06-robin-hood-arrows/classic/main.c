/* CULEGERE VI.1.6 - ROBIN HOOD
 * THE TARGET HAS N CONCENTRIC CIRCLES, EACH WITH ITS OWN SCORE. ROBIN HOOD MUST SCORE EXACTLY X
 * WITH THREE ARROWS. PRINT ALL THE WAYS (THE VALUES OF THE THREE CIRCLES HIT), OR "IMPOSSIBLE"
 * EXAMPLE: N=4 X=4, VALUES 1 2 3 4 -> 1 1 2 (1+1+2=4)
 * ASSUMPTION: THE BOOK'S EXAMPLE SAYS N=3 BUT LISTS 4 VALUES; THE PROGRAM READS EXACTLY N VALUES
 * ASSUMPTION: THE CIRCLES HAVE DIFFERENT VALUES; EVERY WAY IS PRINTED ONCE, WITH THE THREE
 * VALUES IN NON-DECREASING ORDER */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100

int main(void)
{
	int v[MAX] = {0}; /* THE VALUE OF EVERY CIRCLE */
	int n = 0, x = 0, i, j, k;
	int count = 0;

	printf("n and x: ");
	scanf("%d %d", &n, &x);
	printf("The %d circle values: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &v[i]);
	}

	/* EVERY ARROW CAN HIT ANY CIRCLE; ASKING FOR V[I] <= V[J] <= V[K] KEEPS ONLY ONE ORDER OF
	 * THE SAME THREE VALUES, SO 1 1 2, 1 2 1 AND 2 1 1 ARE PRINTED ONLY ONCE, AS 1 1 2 */
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				if (v[i] <= v[j] && v[j] <= v[k] && v[i] + v[j] + v[k] == x)
				{
					printf("%d %d %d\n", v[i], v[j], v[k]);
					count++;
				}
			}
		}
	}

	if (count == 0)
	{
		printf("impossible\n");
	}

	return 0;
}
