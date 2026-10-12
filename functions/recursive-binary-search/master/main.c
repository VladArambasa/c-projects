/* BINARY SEARCH WRITTEN RECURSIVELY: EACH CALL SEARCHES HALF OF THE PREVIOUS RANGE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100

int search(int a[], int low, int high, int key)
{
	int mid;

	if (low > high) /* EMPTY RANGE: THE VALUE IS NOT THERE */
	{
		return -1;
	}
	mid = (low + high) / 2;
	if (a[mid] == key)
	{
		return mid;
	}
	if (a[mid] < key)
	{
		return search(a, mid + 1, high, key); /* RIGHT HALF */
	}
	return search(a, low, mid - 1, key); /* LEFT HALF */
}

int main(void)
{
	int a[MAX];
	int n = 0, i, key = 0, position;

	printf("How many numbers (1-%d)? ", MAX);
	scanf("%d", &n);
	if (n < 1 || n > MAX)
	{
		printf("Invalid size\n");
		return 1;
	}

	printf("Enter %d numbers in increasing order: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	printf("Value to search for: ");
	scanf("%d", &key);

	position = search(a, 0, n - 1, key);
	if (position != -1)
	{
		printf("Found at index %d\n", position);
	}
	else
	{
		printf("Not found\n");
	}

	return 0;
}
