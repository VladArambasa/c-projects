/* BUBBLE SORT (V2): EACH PASS STOPS BEFORE THE ALREADY SORTED END,
 * AND THE SORT STOPS EARLY WHEN A PASS MAKES NO SWAP */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100

int main(void)
{
	int a[MAX];
	int n = 0, i, j, temp, swapped;

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

	for (i = 0; i < n - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < n - 1 - i; j++) /* THE LAST I ELEMENTS ARE ALREADY IN PLACE */
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				swapped = 1;
			}
		}
		if (!swapped) /* NOTHING MOVED: THE ARRAY IS SORTED */
		{
			break;
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
