/* CULEGERE III.1.4 - PAIRS WITH SUM 1000
 * PRINT THE PAIRS OF NUMBERS A AND B WITH A + B = 1000, A DIVISIBLE BY 17 AND B DIVISIBLE BY 19
 * EXAMPLE: NO INPUT -> A=221 B=779, A=544 B=456, A=867 B=133 */
#include <stdio.h> /* PRINTF */

int main(void)
{
	int a, b;

	/* TRY EVERY VALUE OF A; B IS WHAT IS LEFT UP TO 1000 */
	for (a = 1; a < 1000; a++)
	{
		b = 1000 - a;
		if (a % 17 == 0 && b % 19 == 0)
		{
			printf("a=%d b=%d\n", a, b);
		}
	}

	return 0;
}
