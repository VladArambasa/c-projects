/* DELETE THE ELEMENT AT A GIVEN POSITION (1 = FIRST) */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100

int main(void)
{
	int a[MAX];
	int n = 0, i, pos = 0;

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

	printf("Position to delete (1-%d): ", n);
	scanf("%d", &pos);
	if (pos < 1 || pos > n)
	{
		printf("Invalid position\n");
		return 1;
	}

	for (i = pos - 1; i < n - 1; i++) /* EVERY ELEMENT AFTER IT MOVES ONE PLACE LEFT */
	{
		a[i] = a[i + 1];
	}
	n--;

	printf("New array:");
	for (i = 0; i < n; i++)
	{
		printf(" %d", a[i]);
	}
	printf("\n");

	return 0;
}
