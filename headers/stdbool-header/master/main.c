/* STDBOOL.H: THE BOOL TYPE WITH THE VALUES TRUE AND FALSE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

bool is_prime(int n)
{
	int i;

	if (n < 2)
	{
		return false;
	}
	for (i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main(void)
{
	int n;
	bool any = false;

	printf("Primes below 30:");
	for (n = 1; n < 30; n++)
	{
		if (is_prime(n)) /* A BOOL WORKS DIRECTLY AS A CONDITION */
		{
			printf(" %d", n);
			any = true;
		}
	}
	printf("\n");

	printf("any = %d, true = %d, false = %d\n", any, true, false); /* PRINTED AS 1 AND 0 */

	return 0;
}
