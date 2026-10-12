/* LINEAR SEARCH: CHECK THE ELEMENTS ONE BY ONE UNTIL THE VALUE IS FOUND */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100

int main(void)
{
	int a[MAX];
	int n = 0, i, key = 0;
	int position = -1; /* -1 MEANS NOT FOUND (YET) */

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

	printf("Value to search for: ");
	scanf("%d", &key);

	for (i = 0; i < n; i++)
	{
		if (a[i] == key)
		{
			position = i;
			break; /* THE FIRST MATCH IS ENOUGH */
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
