/* CULEGERE III.4.3 - SUM UNTIL ZERO
 * NONZERO NUMBERS ARE READ ONE AFTER ANOTHER UNTIL 0 IS TYPED; PRINT THE SUM OF ALL OF THEM
 * EXAMPLE: 3 5 4 2 0 -> 14 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int x = 0, sum;

	printf("Numbers (0 to stop): ");
	sum = 0;
	while (scanf("%d", &x) == 1 && x != 0) /* STOP AT THE 0 (NOT ADDED) OR AT THE END OF THE INPUT */
	{
		sum = sum + x;
	}
	printf("%d\n", sum);

	return 0;
}
