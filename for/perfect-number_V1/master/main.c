/* PERFECT NUMBER: EQUAL TO THE SUM OF ITS DIVISORS SMALLER THAN ITSELF (6 = 1 + 2 + 3) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0, i;
	int sum = 0;

	printf("Enter a number: ");
	scanf("%d", &n);

	for (i = 1; i < n; i++)
	{
		if (n % i == 0)
		{
			sum = sum + i;
		}
	}

	if (n > 0 && sum == n)
	{
		printf("%d is a perfect number\n", n);
	}
	else
	{
		printf("%d is not a perfect number\n", n);
	}

	return 0;
}
