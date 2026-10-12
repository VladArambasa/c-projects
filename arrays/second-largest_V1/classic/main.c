/* SECOND LARGEST ELEMENT: FIRST FIND THE LARGEST, THEN THE LARGEST OF WHAT IS SMALLER THAN IT */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100

int main(void)
{
	int a[MAX];
	int n = 0, i, largest, second;
	int found = 0;

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

	largest = a[0]; /* PASS 1: THE LARGEST */
	for (i = 1; i < n; i++)
	{
		if (a[i] > largest)
		{
			largest = a[i];
		}
	}

	second = 0; /* PASS 2: THE LARGEST VALUE BELOW IT */
	for (i = 0; i < n; i++)
	{
		if (a[i] < largest && (!found || a[i] > second))
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
