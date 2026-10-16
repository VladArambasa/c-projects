/* CULEGERE VI.3.15 - THE MEAN OF THE OTHERS (V2)
 * REPLACE EVERY ELEMENT OF A SEQUENCE OF N NUMBERS WITH THE ARITHMETIC MEAN OF THE OTHER N-1
 * ELEMENTS, THEN PRINT THE SEQUENCE
 * EXAMPLE: N=3, 1 2 3 -> 2.5 2 1.5
 * IMPROVEMENT: ADD ALL THE ELEMENTS ONCE; THE MEAN OF THE OTHERS IS (TOTAL - A[I]) / (N - 1) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100

int main(void)
{
	double a[MAX] = {0};
	double total = 0;
	int n = 0, i;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%lf", &a[i]);
	}

	for (i = 0; i < n; i++)
	{
		total = total + a[i];
	}

	/* THE TOTAL WAS COMPUTED BEFORE ANY CHANGE, SO EVERY A[I] CAN BE REPLACED AT ONCE */
	for (i = 0; i < n; i++)
	{
		a[i] = (total - a[i]) / (n - 1); /* THE OTHERS ADD UP TO TOTAL - A[I] */
		printf("%g ", a[i]);             /* %G WRITES 2 AND NOT 2.000000 */
	}
	printf("\n");

	return 0;
}
