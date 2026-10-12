/* CULEGERE III.7.13 - DIGITS TO CHANGE
 * TWO NATURAL NUMBERS WITH THE SAME NUMBER OF DIGITS ARE READ; HOW MANY DIGITS MUST BE CHANGED
 * TO TURN ONE NUMBER INTO THE OTHER?
 * EXAMPLE: N1=2135 N2=7139 -> 2 DIGITS */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n1 = 0, n2 = 0;
	int count = 0;

	printf("n1 = ");
	scanf("%d", &n1);
	printf("n2 = ");
	scanf("%d", &n2);

	do /* COMPARE THE DIGITS IN THE SAME PLACE, STARTING FROM THE RIGHT */
	{
		if (n1 % 10 != n2 % 10) /* DIFFERENT DIGITS: THIS ONE MUST BE CHANGED */
		{
			count++;
		}
		n1 = n1 / 10;
		n2 = n2 / 10;
	} while (n1 > 0);

	printf("%d %s\n", count, (count == 1) ? "digit" : "digits");

	return 0;
}
