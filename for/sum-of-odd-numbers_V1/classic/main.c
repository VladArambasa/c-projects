/* SUM OF THE FIRST N ODD NUMBERS: 1 + 3 + 5 + ... */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0, i;
	int sum = 0;

	printf("Enter n: ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		sum = sum + (2 * i - 1); /* THE I-TH ODD NUMBER */
	}

	printf("Sum = %d\n", sum);

	return 0;
}
