/* CULEGERE VI.4.2 - ASCENDING THEN DESCENDING
 * A VECTOR OF N INTEGERS AND A NUMBER K ARE READ; PRINT THE FIRST K ELEMENTS IN ASCENDING ORDER
 * AND THE OTHER ELEMENTS IN DESCENDING ORDER
 * EXAMPLE: N=7, K=3, 23 12 18 4 0 23 5 -> 12 18 23 23 5 4 0 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100 /* AT MOST 100 NUMBERS */

int main(void)
{
	int a[MAX];
	int n = 0, k = 0, i, j, temp;

	printf("n = ");
	scanf("%d", &n);
	printf("k = ");
	scanf("%d", &k);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	/* BUBBLE SORT OF THE FIRST PART, POSITIONS 0..K-1, IN ASCENDING ORDER */
	for (i = 0; i < k - 1; i++)
	{
		for (j = 0; j < k - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	/* BUBBLE SORT OF THE SECOND PART, POSITIONS K..N-1, IN DESCENDING ORDER */
	for (i = 0; i < n - k - 1; i++) /* THIS PART HAS N - K ELEMENTS */
	{
		for (j = k; j < n - 1 - i; j++)
		{
			if (a[j] < a[j + 1]) /* < INSTEAD OF >: THE LARGER VALUE GOES FIRST */
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
