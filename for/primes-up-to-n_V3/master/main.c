/* ALL PRIME NUMBERS FROM 2 TO N (V3): SIEVE OF ERATOSTHENES, NO DIVISIONS AT ALL
 * CROSS OUT THE MULTIPLES OF EVERY PRIME; WHATEVER STAYS UNCROSSED IS PRIME */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100000 /* LARGEST N ACCEPTED */

int main(void)
{
	char crossed[MAX + 1] = {0}; /* ALL 0: NOTHING IS CROSSED OUT YET */
	int n = 0, i, j;

	printf("Enter n (at most %d): ", MAX);
	scanf("%d", &n);

	if (n > MAX)
	{
		printf("n is too large\n");
		return 1;
	}

	for (i = 2; i * i <= n; i++)
	{
		if (!crossed[i]) /* I IS PRIME: CROSS OUT ITS MULTIPLES */
		{
			for (j = i * i; j <= n; j = j + i) /* SMALLER MULTIPLES ARE ALREADY CROSSED */
			{
				crossed[j] = 1;
			}
		}
	}

	for (i = 2; i <= n; i++)
	{
		if (!crossed[i])
		{
			printf("%d ", i);
		}
	}
	printf("\n");

	return 0;
}
