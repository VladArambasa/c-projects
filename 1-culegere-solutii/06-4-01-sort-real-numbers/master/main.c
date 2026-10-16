/* CULEGERE VI.4.1 - SORT REAL NUMBERS
 * N REAL NUMBERS ARE READ; PRINT THEM IN ASCENDING ORDER
 * EXAMPLE: N=4, 7 -3 9.8 0 -> -3 0 7 9.8 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100 /* AT MOST 100 NUMBERS */

int main(void)
{
	double a[MAX], temp;
	int n = 0, i, j;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%lf", &a[i]); /* %LF, IN SMALL LETTERS, READS A DOUBLE */
	}

	/* BUBBLE SORT: GO THROUGH THE VECTOR AND SWAP EVERY TWO NEIGHBOURS IN THE WRONG ORDER */
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++) /* THE I LARGEST VALUES ARE ALREADY AT THE END */
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		printf("%g ", a[i]); /* %G WRITES 7 AND 9.8, NOT 7.000000 AND 9.800000 */
	}
	printf("\n");

	return 0;
}
