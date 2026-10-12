/* CULEGERE VI.4.6 - BEST THREE RESULTS
 * THE RESULTS OF N ATHLETES ARE READ; PRINT THE BEST THREE RESULTS, IN DESCENDING ORDER
 * V1: SORT ALL THE RESULTS IN DESCENDING ORDER, THEN PRINT THE FIRST THREE
 * ASSUMPTION: THE RESULTS ARE NATURAL NUMBERS, A LARGER RESULT IS BETTER (AS IN THE EXAMPLE)
 * AND THERE ARE AT LEAST 3 ATHLETES
 * EXAMPLE: N=5, 156 187 23 97 86 -> 187 156 97 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100 /* AT MOST 100 ATHLETES */

int main(void)
{
	int a[MAX];
	int n = 0, i, j, temp;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d results: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	/* BUBBLE SORT IN DESCENDING ORDER: THE BEST RESULT GOES FIRST */
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a[j] < a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	printf("%d %d %d\n", a[0], a[1], a[2]); /* THE FIRST THREE ARE THE BEST THREE */

	return 0;
}
