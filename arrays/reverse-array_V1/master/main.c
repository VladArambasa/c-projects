/* REVERSE AN ARRAY: COPY IT BACKWARDS INTO A SECOND ARRAY */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100

int main(void)
{
	int a[MAX], b[MAX];
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
		scanf("%d", &a[i]);
	}

	for (i = 0; i < n; i++)
	{
		b[i] = a[n - 1 - i]; /* FIRST OF B = LAST OF A */
	}

	printf("Reversed:");
	for (i = 0; i < n; i++)
	{
		printf(" %d", b[i]);
	}
	printf("\n");

	return 0;
}
