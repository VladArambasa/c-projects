/* CULEGERE II.2.4 - QUOTIENT OR DIVISION IMPOSSIBLE
 * READ TWO NUMBERS. IF THE SECOND ONE IS NOT 0, PRINT THE QUOTIENT OF THE FIRST BY THE SECOND;
 * IF IT IS 0, PRINT "DIVISION IMPOSSIBLE"
 * EXAMPLES: 10 3 -> 3.33; 45 0 -> DIVISION IMPOSSIBLE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	double a = 0, b = 0;

	printf("The two numbers: ");
	scanf("%lf %lf", &a, &b);

	if (b != 0) /* DIVISION BY 0 IS NOT ALLOWED */
	{
		printf("%.2f\n", a / b);
	}
	else
	{
		printf("Division impossible\n");
	}

	return 0;
}
