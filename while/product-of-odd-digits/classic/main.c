/* PRODUCT OF THE ODD DIGITS OF A NUMBER */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0, digit;
	long long product = 1;
	int found = 0; /* DID WE SEE ANY ODD DIGIT? */

	printf("Enter a number: ");
	scanf("%d", &n);

	if (n < 0)
	{
		n = -n;
	}

	while (n > 0)
	{
		digit = n % 10;
		if (digit % 2 == 1)
		{
			product = product * digit;
			found = 1;
		}
		n = n / 10;
	}

	if (found)
	{
		printf("Product of odd digits = %lld\n", product);
	}
	else
	{
		printf("There are no odd digits\n");
	}

	return 0;
}
