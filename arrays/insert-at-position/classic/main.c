/* INSERT A VALUE AT A GIVEN POSITION (1 = FIRST) */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100

int main(void)
{
	int a[MAX + 1];
	int n = 0, i, pos = 0, value = 0;

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

	printf("Position (1-%d) and value: ", n + 1);
	scanf("%d %d", &pos, &value);
	if (pos < 1 || pos > n + 1)
	{
		printf("Invalid position\n");
		return 1;
	}

	/* FROM THE END DOWN TO THE POSITION, MOVE EACH ELEMENT ONE PLACE RIGHT */
	for (i = n; i >= pos; i--)
	{
		a[i] = a[i - 1];
	}
	a[pos - 1] = value; /* POSITION 1 IS INDEX 0 */
	n++;

	printf("New array:");
	for (i = 0; i < n; i++)
	{
		printf(" %d", a[i]);
	}
	printf("\n");

	return 0;
}
