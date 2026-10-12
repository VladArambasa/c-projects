/* SUM OF THE FIRST N ODD NUMBERS (V2): THE SUM IS ALWAYS N * N, SO NO LOOP IS NEEDED
 * 1 = 1, 1 + 3 = 4, 1 + 3 + 5 = 9, 1 + 3 + 5 + 7 = 16 ... */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0;

	printf("Enter n: ");
	scanf("%d", &n);

	printf("Sum = %d\n", n * n);

	return 0;
}
