/* COUNT THE EVEN AND THE ODD NUMBERS IN AN ARRAY */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100

int main(void)
{
	int a[MAX];
	int n = 0, i;
	int even = 0, odd = 0;

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
		if (a[i] % 2 == 0)
		{
			even++;
		}
		else
		{
			odd++;
		}
	}

	printf("Even = %d, Odd = %d\n", even, odd);

	return 0;
}
