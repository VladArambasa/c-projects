/* CULEGERE III.1.3 - MULTIPLICATION TABLE
 * PRINT THE MULTIPLICATION TABLE OF N, FROM 1 X N TO 10 X N
 * EXAMPLE: N=5 -> 1X5=5 2X5=10 3X5=15 ... 10X5=50 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0, i;

	printf("n = ");
	scanf("%d", &n);

	/* ONE LINE FOR EVERY FACTOR FROM 1 TO 10 */
	for (i = 1; i <= 10; i++)
	{
		printf("%dx%d=%d\n", i, n, i * n);
	}

	return 0;
}
