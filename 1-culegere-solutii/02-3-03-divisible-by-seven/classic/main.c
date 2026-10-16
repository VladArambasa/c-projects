/* CULEGERE II.3.3 - DIVISIBLE BY 7
 * READ TWO NUMBERS AND PRINT THE ONES THAT CAN BE DIVIDED EXACTLY BY 7
 * EXAMPLE: 34 28 -> 28 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int a = 0, b = 0;

	printf("The two numbers: ");
	scanf("%d %d", &a, &b);

	/* EACH NUMBER IS TESTED ON ITS OWN: REMAINDER 0 WHEN DIVIDED BY 7 */
	if (a % 7 == 0)
	{
		printf("%d ", a);
	}
	if (b % 7 == 0)
	{
		printf("%d ", b);
	}
	printf("\n");

	return 0;
}
