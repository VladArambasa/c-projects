/* CULEGERE I.6 - FIVE CONSECUTIVE NUMBERS
 * ION SAYS A NUMBER; VASILE MUST SAY FIVE CONSECUTIVE INCREASING NUMBERS WITH ION'S NUMBER
 * IN THE MIDDLE. READ ION'S NUMBER AND PRINT VASILE'S ANSWER
 * EXAMPLE: 10 -> 8 9 10 11 12 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0;

	printf("Ion's number: ");
	scanf("%d", &n);

	/* TWO NUMBERS BEFORE N, N ITSELF, TWO NUMBERS AFTER N */
	printf("%d %d %d %d %d\n", n - 2, n - 1, n, n + 1, n + 2);

	return 0;
}
