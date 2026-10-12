/* PRIME CHECK (V2): TEST DIVISORS ONLY UP TO THE SQUARE ROOT AND STOP AT THE FIRST ONE FOUND
 * IF N = A * B AND A > SQRT(N), THEN B < SQRT(N), SO B WOULD ALREADY HAVE BEEN FOUND */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0, i;
	int is_prime = 1;

	printf("Enter a number: ");
	scanf("%d", &n);

	if (n < 2)
	{
		is_prime = 0;
	}

	for (i = 2; i <= n / i; i++) /* SAME AS I * I <= N, BUT IT CANNOT OVERFLOW */
	{
		if (n % i == 0)
		{
			is_prime = 0;
			break; /* ONE DIVISOR IS ENOUGH */
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
