/* ALL PRIME NUMBERS FROM 2 TO N: TEST EVERY NUMBER WITH EVERY POSSIBLE DIVISOR */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0, i, d;

	printf("Enter n: ");
	scanf("%d", &n);

	for (i = 2; i <= n; i++)
	{
		int is_prime = 1;

		for (d = 2; d < i; d++) /* ANY DIVISOR BETWEEN 2 AND I - 1? */
		{
			if (i % d == 0)
			{
				is_prime = 0;
			}
		}
		if (is_prime)
		{
			printf("%d ", i);
		}
	}
	printf("\n");

	return 0;
}
