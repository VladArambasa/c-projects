/* OPERATOR PRECEDENCE: WHICH OPERATION HAPPENS FIRST */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int a = 2, b = 3, c = 4;
	int x, y, z;

	printf("a + b * c   = %d\n", a + b * c);   /* * BEFORE +: 2 + 12 */
	printf("(a + b) * c = %d\n", (a + b) * c); /* PARENTHESES FIRST: 5 * 4 */
	printf("a - b - c   = %d\n", a - b - c);   /* LEFT TO RIGHT: (2 - 3) - 4 */
	printf("c / a * b   = %d\n", c / a * b);   /* LEFT TO RIGHT: (4 / 2) * 3 */

	x = y = z = 7; /* ASSIGNMENT GOES RIGHT TO LEFT: Z FIRST */
	printf("x = %d, y = %d, z = %d\n", x, y, z);

	/* == IS DONE BEFORE &, SO WRITE (A & 1) == 0 WITH PARENTHESES */
	printf("(a & 1) == 0 is %d, so a is even\n", (a & 1) == 0);

	return 0;
}
