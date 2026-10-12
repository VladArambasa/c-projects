/* LARGEST AND SMALLEST ELEMENT OF AN ARRAY */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100

int main(void)
{
	int a[MAX];
	int n = 0, i, max, min;

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

	max = a[0]; /* START WITH THE FIRST ELEMENT, NOT WITH 0 */
	min = a[0];
	for (i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}

	printf("Max = %d, Min = %d\n", max, min);

	return 0;
}
