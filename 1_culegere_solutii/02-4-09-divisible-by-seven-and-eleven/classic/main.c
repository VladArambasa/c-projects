/* CULEGERE II.4.9 - DIVISIBLE BY 7 AND 11
 * READ TWO NUMBERS AND PRINT THE ONES THAT CAN BE DIVIDED EXACTLY BY BOTH 7 AND 11
 * EXAMPLE: 154 213 -> 154 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int a = 0, b = 0;

	printf("The two numbers: ");
	scanf("%d %d", &a, &b);

	/* BOTH REMAINDERS MUST BE 0 */
	if (a % 7 == 0 && a % 11 == 0)
	{
		printf("%d ", a);
	}
	if (b % 7 == 0 && b % 11 == 0)
	{
		printf("%d ", b);
	}
	printf("\n");

	return 0;
}
