/* PRODUCT OF ALL EVEN NUMBERS FROM 1 TO N */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0, i;
	long long product = 1; /* PRODUCTS GROW FAST: LONG LONG IS ENOUGH UP TO N = 33 */

	printf("Enter n: ");
	scanf("%d", &n);

	if (n < 2)
	{
		printf("There are no even numbers up to %d\n", n);
		return 0;
	}

	for (i = 2; i <= n; i = i + 2) /* 2, 4, 6, ... */
	{
		product = product * i;
	}

	printf("Product = %lld\n", product);

	return 0;
}
