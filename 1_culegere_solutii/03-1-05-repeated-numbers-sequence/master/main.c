/* CULEGERE III.1.5 - SEQUENCE 1,1,2,2,2,3,3,3,3,...
 * GENERATE THE FIRST N TERMS OF THE SEQUENCE 1,1,2,2,2,3,3,3,3,4,4,4,4,4,...
 * (EVERY NUMBER K APPEARS K + 1 TIMES)
 * EXAMPLE: N=10 -> 1 1 2 2 2 3 3 3 3 4 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0, count, k, j;

	printf("n = ");
	scanf("%d", &n);

	count = 0; /* HOW MANY TERMS HAVE BEEN PRINTED SO FAR */
	k = 1;
	while (count < n)
	{
		/* PRINT K, K + 1 TIMES, BUT STOP AS SOON AS N TERMS ARE PRINTED */
		for (j = 1; j <= k + 1 && count < n; j++)
		{
			printf("%d ", k);
			count++;
		}
		k++; /* THE NEXT NUMBER OF THE SEQUENCE */
	}
	printf("\n");

	return 0;
}
