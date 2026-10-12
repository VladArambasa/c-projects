/* BUBBLE SORT: COMPARE NEIGHBOURS AND SWAP THEM WHEN THEY ARE IN THE WRONG ORDER, N - 1 TIMES */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100

int main(void)
{
	int a[MAX];
	int n = 0, i, j, temp;

	printf("How many numbers (1-%d)? ", MAX);
	scanf("%d", &n);
	if (n < 1 || n > MAX)
	{
		printf("Invalid size\n");
		return 1;
	}

	printf("Enter %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	for (i = 0; i < n - 1; i++) /* AFTER EVERY PASS THE LARGEST REMAINING VALUE IS IN ITS FINAL PLACE */
	{
		for (j = 0; j < n - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	printf("Sorted:");
	for (i = 0; i < n; i++)
	{
		printf(" %d", a[i]);
	}
	printf("\n");

	return 0;
}
