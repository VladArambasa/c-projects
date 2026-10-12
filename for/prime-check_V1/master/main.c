/* PRIME CHECK: A PRIME NUMBER HAS NO DIVISOR BETWEEN 2 AND N - 1 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0, i;
	int is_prime = 1; /* 1 = YES, 0 = NO */

	printf("Enter a number: ");
	scanf("%d", &n);

	if (n < 2) /* 0 AND 1 ARE NOT PRIME */
	{
		is_prime = 0;
	}

	for (i = 2; i < n; i++) /* TRY EVERY POSSIBLE DIVISOR */
	{
		if (n % i == 0)
		{
			is_prime = 0;
		}
	}

	if (is_prime)
	{
		printf("%d is prime\n", n);
	}
	else
	{
		printf("%d is not prime\n", n);
	}

	return 0;
}
