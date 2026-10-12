/* CULEGERE VI.3.12 - THE LARGEST NUMBER BELOW 100
 * N INTEGERS ARE READ; AMONG THE NUMBERS SMALLER THAN 100, PRINT THE ONE WITH THE LARGEST VALUE
 * EXAMPLE: N=4, 120 98 34 105 -> 98
 * ASSUMPTION: IF NO NUMBER IS SMALLER THAN 100, A MESSAGE IS PRINTED */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100

int main(void)
{
	int a[MAX] = {0};
	int n = 0, i, max = 0;
	int found = 0; /* BOOLEAN: 1 AFTER THE FIRST NUMBER SMALLER THAN 100 */

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	for (i = 0; i < n; i++)
	{
		if (a[i] < 100) /* ONLY THESE NUMBERS TAKE PART */
		{
			if (found == 0 || a[i] > max) /* THE FIRST ONE, OR A LARGER ONE */
			{
				max = a[i];
				found = 1;
			}
		}
	}

	if (found == 1)
	{
		printf("%d\n", max);
	}
	else
	{
		printf("No number is smaller than 100\n");
	}

	return 0;
}
