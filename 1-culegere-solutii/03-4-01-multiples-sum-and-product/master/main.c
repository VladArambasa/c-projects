/* CULEGERE III.4.1 - SUM AND PRODUCT OF MULTIPLES
 * COMPUTE 7+14+21+28+...+98 AND 3*6*9*12*...*33
 * EXAMPLE: NO INPUT -> 7+14+21+...+98 = 735, 3*6*9*...*33 = 7071141369600 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int i, sum;
	long long product; /* THE PRODUCT IS ABOUT 7 * 10^12, MUCH TOO BIG FOR AN INT */

	sum = 0;
	for (i = 7; i <= 98; i = i + 7) /* THE MULTIPLES OF 7 UP TO 98 */
	{
		sum = sum + i;
	}

	product = 1; /* A PRODUCT STARTS FROM 1, NOT FROM 0 */
	for (i = 3; i <= 33; i = i + 3) /* THE MULTIPLES OF 3 UP TO 33 */
	{
		product = product * i;
	}

	printf("7+14+21+...+98 = %d\n", sum);
	printf("3*6*9*...*33 = %lld\n", product);

	return 0;
}
