/* READ N NUMBERS INTO AN ARRAY AND PRINT THEM */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100 /* THE ARRAY CANNOT HOLD MORE THAN THIS */

int main(void)
{
	int a[MAX];
	int n = 0, i;

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
		scanf("%d", &a[i]); /* &A[I] IS THE ADDRESS OF ELEMENT I */
	}

	printf("The array:");
	for (i = 0; i < n; i++)
	{
		printf(" %d", a[i]);
	}
	printf("\n");

	return 0;
}
