/* CULEGERE VI.7.6 - LAST DIGIT EQUAL TO K
 * N INTEGERS AND A DIGIT K ARE READ; COPY THE ELEMENTS WHOSE LAST DIGIT IS K INTO ANOTHER VECTOR,
 * THEN PRINT BOTH VECTORS
 * ASSUMPTION: THE GIVEN VECTOR STAYS AS IT WAS (ITS ELEMENTS ARE COPIED, NOT REMOVED)
 * EXAMPLE: N=3, K=7, 17 23 47 -> 17 47 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100 /* AT MOST 100 NUMBERS */

int main(void)
{
	int a[MAX], b[MAX];
	int n = 0, k = 0, m, i;

	printf("n = ");
	scanf("%d", &n);
	printf("k = ");
	scanf("%d", &k);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	m = 0; /* HOW MANY ELEMENTS THE NEW VECTOR B HAS */
	for (i = 0; i < n; i++)
	{
		if (abs(a[i]) % 10 == k) /* ABS: THE LAST DIGIT OF -17 IS ALSO 7 */
		{
			b[m] = a[i];
			m++;
		}
	}

	printf("Given vector: ");
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	printf("New vector: ");
	for (i = 0; i < m; i++)
	{
		printf("%d ", b[i]);
	}
	printf("\n");

	return 0;
}
