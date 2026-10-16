/* CULEGERE I.11 - MULTIPLICATION TABLE
 * PRINT THE MULTIPLICATION TABLE OF N, ONE LINE UNDER THE OTHER
 * EXAMPLE: 5 -> 1X5=5, 2X5=10, 3X5=15, ..., 10X5=50 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0;

	printf("n = ");
	scanf("%d", &n);

	/* LOOPS COME LATER (CHAPTER III): HERE EACH LINE OF THE TABLE HAS ITS OWN PRINTF */
	printf("1x%d=%d\n", n, 1 * n);
	printf("2x%d=%d\n", n, 2 * n);
	printf("3x%d=%d\n", n, 3 * n);
	printf("4x%d=%d\n", n, 4 * n);
	printf("5x%d=%d\n", n, 5 * n);
	printf("6x%d=%d\n", n, 6 * n);
	printf("7x%d=%d\n", n, 7 * n);
	printf("8x%d=%d\n", n, 8 * n);
	printf("9x%d=%d\n", n, 9 * n);
	printf("10x%d=%d\n", n, 10 * n);

	return 0;
}
