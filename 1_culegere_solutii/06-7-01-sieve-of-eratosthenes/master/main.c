/* CULEGERE VI.7.1 - SIEVE OF ERATOSTHENES
 * BUILD THE VECTOR OF THE PRIME NUMBERS SMALLER THAN A GIVEN N (N < 1000) WITH THE SIEVE FROM THE
 * MATHS TEXTBOOK: A NUMBER THAT IS CROSSED OUT IS REPLACED BY 0, AND THE ZEROS ARE NOT PRINTED
 * EXAMPLE (NOT IN THE BOOK): N=20 -> 2 3 5 7 11 13 17 19 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 1000 /* N < 1000 */

int main(void)
{
	int a[MAX];
	int n = 0, i, j;

	printf("n = ");
	scanf("%d", &n);

	a[0] = 0; /* 0 AND 1 ARE NOT PRIME */
	a[1] = 0;
	for (i = 2; i < n; i++) /* WRITE THE NUMBERS 2, 3, ..., N - 1 */
	{
		a[i] = i;
	}

	for (i = 2; i < n; i++)
	{
		if (a[i] != 0) /* NOT CROSSED OUT BY A SMALLER NUMBER, SO NUMBER I IS PRIME */
		{
			for (j = 2 * i; j < n; j = j + i) /* CROSS OUT ITS MULTIPLES 2I, 3I, ... */
			{
				a[j] = 0;
			}
		}
	}

	for (i = 2; i < n; i++)
	{
		if (a[i] != 0) /* ONLY THE NUMBERS THAT WERE NOT CROSSED OUT */
		{
			printf("%d ", a[i]);
		}
	}
	printf("\n");

	return 0;
}
