/* ROTATE AN ARRAY K PLACES TO THE RIGHT (V2): THREE REVERSALS, EVERY ELEMENT MOVES AT MOST TWICE
 * REVERSE ALL, THEN REVERSE THE FIRST K, THEN REVERSE THE REST */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100

void reverse(int a[], int start, int end)
{
	int temp;

	while (start < end)
	{
		temp = a[start];
		a[start] = a[end];
		a[end] = temp;
		start++;
		end--;
	}
}

int main(void)
{
	int a[MAX];
	int n = 0, k = 0, i;

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
	k = k % n;

	reverse(a, 0, n - 1); /* 1 2 3 4 5  ->  5 4 3 2 1 */
	reverse(a, 0, k - 1); /* K = 2:        4 5 3 2 1 */
	reverse(a, k, n - 1); /*               4 5 1 2 3 */

	printf("Rotated:");
	for (i = 0; i < n; i++)
	{
		printf(" %d", a[i]);
	}
	printf("\n");

	return 0;
}
