/* CULEGERE I.10 - SUMS OF PAIRS
 * READ THREE NUMBERS AND PRINT ALL THE SUMS OF TWO OF THEM, SHOWING THE TERMS TOO
 * EXAMPLE: 2 13 4 -> 2+13=15  2+4=6  13+4=17 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int a = 0, b = 0, c = 0;

	printf("The three numbers: ");
	scanf("%d %d %d", &a, &b, &c);

	/* THERE ARE THREE PAIRS: A WITH B, A WITH C, B WITH C */
	printf("%d+%d=%d  ", a, b, a + b);
	printf("%d+%d=%d  ", a, c, a + c);
	printf("%d+%d=%d\n", b, c, b + c);

	return 0;
}
