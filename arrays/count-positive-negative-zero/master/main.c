/* COUNT THE POSITIVE, NEGATIVE AND ZERO ELEMENTS OF AN ARRAY */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100

int main(void)
{
	int a[MAX];
	int n = 0, i;
	int positive = 0, negative = 0, zero = 0;

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
		if (a[i] > 0)
		{
			positive++;
		}
		else if (a[i] < 0)
		{
			negative++;
		}
		else
		{
			zero++;
		}
	}

	printf("Positive = %d, Negative = %d, Zero = %d\n", positive, negative, zero);

	return 0;
}
