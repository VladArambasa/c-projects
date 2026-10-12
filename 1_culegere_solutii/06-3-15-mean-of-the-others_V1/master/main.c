/* CULEGERE VI.3.15 - THE MEAN OF THE OTHERS (V1)
 * REPLACE EVERY ELEMENT OF A SEQUENCE OF N NUMBERS WITH THE ARITHMETIC MEAN OF THE OTHER N-1
 * ELEMENTS, THEN PRINT THE SEQUENCE
 * EXAMPLE: N=3, 1 2 3 -> 2.5 2 1.5
 * IDEA: FOR EVERY ELEMENT ADD UP ALL THE OTHERS. THE MEANS GO INTO A SECOND VECTOR FIRST,
 * BECAUSE CHANGING THE GIVEN VECTOR TOO EARLY WOULD SPOIL THE SUMS OF THE NEXT ELEMENTS */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100

int main(void)
{
	double a[MAX] = {0};
	double mean[MAX] = {0};
	double sum;
	int n = 0, i, j;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%lf", &a[i]);
	}

	for (i = 0; i < n; i++)
	{
		sum = 0;
		for (j = 0; j < n; j++) /* ALL THE ELEMENTS EXCEPT A[I] */
		{
			if (j != i)
			{
				sum = sum + a[j];
			}
		}
		mean[i] = sum / (n - 1);
	}

	for (i = 0; i < n; i++) /* NOW THE REPLACEMENT IS SAFE */
	{
		a[i] = mean[i];
		printf("%g ", a[i]); /* %G WRITES 2 AND NOT 2.000000 */
	}
	printf("\n");

	return 0;
}
