/* ROTATE AN ARRAY K PLACES TO THE RIGHT: MOVE IT ONE PLACE, K TIMES */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100

int main(void)
{
	int a[MAX];
	int n = 0, k = 0, i, step, last;

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

	printf("Rotate by (0 or more): ");
	scanf("%d", &k);
	if (k < 0)
	{
		printf("Invalid rotation\n");
		return 1;
	}
	k = k % n; /* ROTATING N PLACES GIVES BACK THE SAME ARRAY */

	for (step = 0; step < k; step++)
	{
		last = a[n - 1]; /* THE LAST ELEMENT GOES TO THE FRONT */
		for (i = n - 1; i > 0; i--)
		{
			a[i] = a[i - 1];
		}
		a[0] = last;
	}

	printf("Rotated:");
	for (i = 0; i < n; i++)
	{
		printf(" %d", a[i]);
	}
	printf("\n");

	return 0;
}
