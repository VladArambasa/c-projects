/* CULEGERE III.1.4 - PAIRS WITH SUM 1000
 * PRINT THE PAIRS OF NUMBERS A AND B WITH A + B = 1000, A DIVISIBLE BY 17 AND B DIVISIBLE BY 19
 * IMPROVEMENT: A GOES ONLY THROUGH THE MULTIPLES OF 17 (58 STEPS INSTEAD OF 999)
 * EXAMPLE: NO INPUT -> A=221 B=779, A=544 B=456, A=867 B=133 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int a, b;

	/* A TAKES ONLY THE VALUES 17, 34, 51, ..., SO IT IS ALWAYS DIVISIBLE BY 17 */
	for (a = 17; a < 1000; a = a + 17)
	{
		b = 1000 - a;
		if (b % 19 == 0) /* ONLY B STILL NEEDS A CHECK */
		{
			printf("a=%d b=%d\n", a, b);
		}
	}

	return 0;
}
