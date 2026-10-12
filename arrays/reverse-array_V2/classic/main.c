/* REVERSE AN ARRAY (V2): SWAP THE ENDS AND MOVE INWARD, IN PLACE, NO SECOND ARRAY NEEDED */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100

int main(void)
{
	int a[MAX];
	int n = 0, i, temp;

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

	for (i = 0; i < n / 2; i++) /* ONLY HALF: EACH SWAP FIXES TWO ELEMENTS */
	{
		temp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = temp;
	}

	printf("Reversed:");
	for (i = 0; i < n; i++)
	{
		printf(" %d", a[i]);
	}
	printf("\n");

	return 0;
}
