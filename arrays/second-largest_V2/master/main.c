/* SECOND LARGEST ELEMENT (V2): ONE PASS, KEEPING THE TWO LARGEST VALUES SEEN SO FAR */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100

int main(void)
{
	int a[MAX];
	int n = 0, i, largest;
	int second = 0;
	int found = 0; /* DO WE HAVE A SECOND LARGEST YET? */

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

	largest = a[0];
	for (i = 1; i < n; i++)
	{
		if (a[i] > largest) /* NEW LARGEST: THE OLD ONE BECOMES SECOND */
		{
			second = largest;
			largest = a[i];
			found = 1;
		}
		else if (a[i] < largest && (!found || a[i] > second))
		{
			second = a[i];
			found = 1;
		}
	}

	if (found)
	{
		printf("Second largest = %d\n", second);
	}
	else
	{
		printf("There is no second largest (all elements are equal)\n");
	}

	return 0;
}
