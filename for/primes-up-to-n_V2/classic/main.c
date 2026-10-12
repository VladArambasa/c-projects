/* ALL PRIME NUMBERS FROM 2 TO N (V2): DIVISORS ONLY UP TO THE SQUARE ROOT, STOP AT THE FIRST */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0, i, d;

	printf("Enter n: ");
	scanf("%d", &n);

	for (i = 2; i <= n; i++)
	{
		int is_prime = 1;

		for (d = 2; d * d <= i; d++)
		{
			if (i % d == 0)
			{
				is_prime = 0;
				break; /* NO NEED TO LOOK FURTHER */
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
