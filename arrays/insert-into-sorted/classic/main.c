/* INSERT A VALUE INTO A SORTED ARRAY SO THAT IT STAYS SORTED */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100

int main(void)
{
	int a[MAX + 1]; /* ONE EXTRA PLACE FOR THE NEW VALUE */
	int n = 0, i, value = 0;

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

	printf("Value to insert: ");
	scanf("%d", &value);

	i = n - 1;
	while (i >= 0 && a[i] > value) /* MOVE THE BIGGER ELEMENTS ONE PLACE RIGHT */
	{
		a[i + 1] = a[i];
		i--;
	}
	a[i + 1] = value; /* THE GAP IS WHERE THE VALUE BELONGS */
	n++;

	printf("New array:");
	for (i = 0; i < n; i++)
	{
		printf(" %d", a[i]);
	}
	printf("\n");

	return 0;
}
