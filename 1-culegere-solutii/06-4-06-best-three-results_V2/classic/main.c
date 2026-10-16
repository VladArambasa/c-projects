/* CULEGERE VI.4.6 - BEST THREE RESULTS
 * THE RESULTS OF N ATHLETES ARE READ; PRINT THE BEST THREE RESULTS, IN DESCENDING ORDER
 * V2: ONE PASS AND NO SORTING: KEEP ONLY THE THREE BEST RESULTS SEEN SO FAR (NO VECTOR NEEDED)
 * ASSUMPTION: THE RESULTS ARE NATURAL NUMBERS, A LARGER RESULT IS BETTER (AS IN THE EXAMPLE)
 * AND THERE ARE AT LEAST 3 ATHLETES
 * EXAMPLE: N=5, 156 187 23 97 86 -> 187 156 97 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0, x = 0, i;
	int first = -1, second = -1, third = -1; /* -1 IS SMALLER THAN ANY NATURAL NUMBER */

	printf("n = ");
	scanf("%d", &n);
	printf("The %d results: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x);
		if (x > first) /* A NEW BEST RESULT: THE OLD FIRST AND SECOND MOVE ONE PLACE DOWN */
		{
			third = second;
			second = first;
			first = x;
		}
		else if (x > second) /* X GOES BETWEEN FIRST AND SECOND */
		{
			third = second;
			second = x;
		}
		else if (x > third) /* X ONLY REPLACES THE THIRD */
		{
			third = x;
		}
	}

	printf("%d %d %d\n", first, second, third);

	return 0;
}
