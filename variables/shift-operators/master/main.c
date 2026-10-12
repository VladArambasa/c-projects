/* SHIFT OPERATORS: << MOVES BITS LEFT (TIMES 2), >> MOVES BITS RIGHT (DIVIDED BY 2) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	unsigned char a = 45;  /* 0010 1101 */
	unsigned char b = 172; /* 1010 1100 */
	signed char c = -84;   /* 1010 1100 READ AS SIGNED */

	printf("45 << 1 = %d\n", (unsigned char)(a << 1)); /* 90 = 45 * 2 */
	printf("45 << 2 = %d\n", (unsigned char)(a << 2)); /* 180 = 45 * 4 */
	printf("45 << 3 = %d\n", (unsigned char)(a << 3)); /* 104, NOT 360: THE CAST KEEPS ONLY 8 BITS */

	printf("172 >> 2 = %d\n", b >> 2); /* 43 = 172 / 4 */
	printf("172 >> 3 = %d\n", b >> 3); /* 21 = 172 / 8, FRACTION LOST */

	printf("-84 >> 2 = %d\n", c >> 2); /* -21: GCC KEEPS THE SIGN (OTHER COMPILERS MAY NOT) */

	return 0;
}
