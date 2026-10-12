/* CULEGERE I.9 - NUMBERS FROM THREE DIGITS
 * READ THREE DIGITS; PRINT ON ONE LINE 5 NUMBERS MADE OF THESE DIGITS, EACH DIGIT USED ONCE
 * EXAMPLE: 3 4 2 -> 324 342 243 234 432 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int a = 0, b = 0, c = 0;
	int n1, n2, n3, n4, n5;

	printf("The three digits: ");
	scanf("%d %d %d", &a, &b, &c);

	/* NUMBER = HUNDREDS * 100 + TENS * 10 + UNITS, IN THE ORDER OF THE EXAMPLE */
	n1 = a * 100 + c * 10 + b;
	n2 = a * 100 + b * 10 + c;
	n3 = c * 100 + b * 10 + a;
	n4 = c * 100 + a * 10 + b;
	n5 = b * 100 + a * 10 + c;

	printf("%d %d %d %d %d\n", n1, n2, n3, n4, n5);

	return 0;
}
