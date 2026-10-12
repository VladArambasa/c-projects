/* CULEGERE III.6.3 - HOW MANY EVEN NUMBERS
 * NON-ZERO NATURAL NUMBERS ARE READ UNTIL 0 IS TYPED (THE FIRST NUMBER IS NOT 0);
 * COUNT HOW MANY OF THEM ARE EVEN
 * EXAMPLE: 4 3 6 5 7 7 0 -> 2 EVEN NUMBERS */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int x = 0;
	int count = 0;

	printf("Numbers (0 to stop): ");
	/* SCANF GIVES 1 WHEN IT HAS READ A NUMBER: STOP AT 0 OR WHEN THE INPUT ENDS */
	while (scanf("%d", &x) == 1 && x != 0)
	{
		if (x % 2 == 0) /* EVEN: THE REMAINDER WHEN DIVIDED BY 2 IS 0 */
		{
			count++;
		}
	}

	printf("%d even %s\n", count, (count == 1) ? "number" : "numbers");

	return 0;
}
