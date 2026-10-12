/* ASSIGNMENT OPERATORS: X += 5 IS SHORT FOR X = X + 5 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int x = 10;

	printf("x = 10   -> %d\n", x);
	x += 5;
	printf("x += 5   -> %d\n", x); /* 15 */
	x -= 3;
	printf("x -= 3   -> %d\n", x); /* 12 */
	x *= 2;
	printf("x *= 2   -> %d\n", x); /* 24 */
	x /= 5;
	printf("x /= 5   -> %d\n", x); /* 4: INTEGER DIVISION */
	x %= 3;
	printf("x %%= 3   -> %d\n", x); /* 1 */
	x <<= 4;
	printf("x <<= 4  -> %d\n", x); /* 16 */
	x |= 3;
	printf("x |= 3   -> %d\n", x); /* 19 */

	return 0;
}
