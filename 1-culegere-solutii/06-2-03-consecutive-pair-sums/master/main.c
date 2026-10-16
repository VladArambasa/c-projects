/* CULEGERE VI.2.3 - SUMS OF PAIRS
 * AN EVEN NUMBER OF NUMBERS IS READ; ADD THEM TWO BY TWO (FIRST + SECOND, THIRD + FOURTH, ...)
 * AND PRINT THE SUMS
 * EXAMPLE: 6 ELEMENTS, 5 4 3 6 5 5 -> 9 9 10 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100

int main(void)
{
	int a[MAX] = {0};
	int n = 0, i;

	printf("Number of elements: ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	i = 0;
	while (i < n) /* ONE PAIR AT A TIME: A[I] AND A[I + 1] */
	{
		printf("%d ", a[i] + a[i + 1]);
		i = i + 2;
	}
	printf("\n");

	return 0;
}
