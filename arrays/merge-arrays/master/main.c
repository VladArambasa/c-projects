/* MERGE TWO ARRAYS: THE ELEMENTS OF THE FIRST, THEN THOSE OF THE SECOND */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 50

int main(void)
{
	int a[MAX], b[MAX], c[2 * MAX]; /* C MUST HOLD BOTH */
	int n1 = 0, n2 = 0, i;

	printf("Size of the first array (1-%d): ", MAX);
	scanf("%d", &n1);
	if (n1 < 1 || n1 > MAX)
	{
		printf("Invalid size\n");
		return 1;
	}
	printf("Enter %d numbers: ", n1);
	for (i = 0; i < n1; i++)
	{
		scanf("%d", &a[i]);
	}

	printf("Size of the second array (1-%d): ", MAX);
	scanf("%d", &n2);
	if (n2 < 1 || n2 > MAX)
	{
		printf("Invalid size\n");
		return 1;
	}
	printf("Enter %d numbers: ", n2);
	for (i = 0; i < n2; i++)
	{
		scanf("%d", &b[i]);
	}

	for (i = 0; i < n1; i++)
	{
		c[i] = a[i];
	}
	for (i = 0; i < n2; i++)
	{
		c[n1 + i] = b[i]; /* CONTINUE RIGHT AFTER THE FIRST ARRAY */
	}

	printf("Merged:");
	for (i = 0; i < n1 + n2; i++)
	{
		printf(" %d", c[i]);
	}
	printf("\n");

	return 0;
}
