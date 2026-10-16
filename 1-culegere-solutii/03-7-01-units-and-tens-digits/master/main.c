/* CULEGERE III.7.1 - NUMBERS MADE OF UNITS AND TENS
 * THREE TWO-DIGIT NUMBERS A, B, C ARE READ; THEIR UNITS DIGITS FORM THE THREE-DIGIT NUMBER X
 * AND THEIR TENS DIGITS FORM THE THREE-DIGIT NUMBER Y; PRINT X AND Y
 * ASSUMPTION: NO DIGIT IS 0 ("NENULE"), SO X AND Y REALLY HAVE THREE DIGITS
 * EXAMPLE: A=24 B=13 C=64 -> X=434 Y=216 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int a = 0, b = 0, c = 0;
	int x, y;

	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);
	printf("c = ");
	scanf("%d", &c);

	/* FOR A TWO-DIGIT NUMBER, % 10 GIVES THE UNITS DIGIT AND / 10 GIVES THE TENS DIGIT;
	 * THE DIGIT TAKEN FROM A IS WORTH HUNDREDS, THE ONE FROM B TENS, THE ONE FROM C UNITS */
	x = (a % 10) * 100 + (b % 10) * 10 + c % 10;
	y = (a / 10) * 100 + (b / 10) * 10 + c / 10;

	printf("x=%d y=%d\n", x, y);

	return 0;
}
