/* MACRO PITFALLS: MISSING PARENTHESES AND ARGUMENTS EVALUATED TWICE */
#include <stdio.h> /* PRINTF */

#define BAD_SQUARE(X) X * X        /* NO PARENTHESES: TROUBLE */
#define GOOD_SQUARE(X) ((X) * (X))
#define MAX(A, B) ((A) > (B) ? (A) : (B))

int main(void)
{
	int n = 3;
	int a = 5, b = 2, m;

	printf("BAD_SQUARE(n + 1)   = %d\n", BAD_SQUARE(n + 1));   /* N + 1 * N + 1 = 3 + 3 + 1 = 7 */
	printf("GOOD_SQUARE(n + 1)  = %d\n", GOOD_SQUARE(n + 1));  /* (N + 1) * (N + 1) = 16 */
	printf("100 / BAD_SQUARE(5) = %d\n", 100 / BAD_SQUARE(5)); /* 100 / 5 * 5 = 100, NOT 4 */

	m = MAX(a++, b++); /* A++ APPEARS TWICE IN THE EXPANSION, SO A GROWS TWICE */
	printf("MAX(a++, b++) = %d, then a = %d, b = %d\n", m, a, b);

	return 0;
}
