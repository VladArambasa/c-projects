/* CULEGERE I.2 - NUMBER TRIANGLE
 * READ A NATURAL NUMBER N AND PRINT A TRIANGLE: N ON THE FIRST ROW, N+2 TWICE ON THE
 * SECOND, N+4 THREE TIMES ON THE THIRD AND N+6 FOUR TIMES ON THE FOURTH
 * EXAMPLE: 5 -> 5 / 7 7 / 9 9 9 / 11 11 11 11 (ONE ROW PER LINE) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0;

	printf("n = ");
	scanf("%d", &n);

	/* EACH ROW HAS ONE MORE NUMBER THAN THE ROW ABOVE, AND THE NUMBER GROWS BY 2 */
	printf("%d\n", n);
	printf("%d %d\n", n + 2, n + 2);
	printf("%d %d %d\n", n + 4, n + 4, n + 4);
	printf("%d %d %d %d\n", n + 6, n + 6, n + 6, n + 6);

	return 0;
}
