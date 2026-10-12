/* BINARY SEARCH IN A SORTED ARRAY: LOOK IN THE MIDDLE, THEN KEEP ONLY THE HALF THAT CAN HOLD THE VALUE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100

int main(void)
{
	int a[MAX];
	int n = 0, i, key = 0, mid;
	int low, high;
	int position = -1;

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

	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (a[mid] == key)
		{
			position = mid;
			break;
		}
		else if (a[mid] < key)
		{
			low = mid + 1; /* THE VALUE CAN ONLY BE TO THE RIGHT */
		}
		else
		{
			high = mid - 1; /* THE VALUE CAN ONLY BE TO THE LEFT */
		}
	}

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
