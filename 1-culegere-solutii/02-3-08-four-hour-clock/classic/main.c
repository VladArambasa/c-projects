/* CULEGERE II.3.8 - FOUR HOUR CLOCK
 * IN GALAXY RECKYA ALL CLOCKS HAVE ONLY 4 HOURS (1, 2, 3, 4). GYGELY WAS BORN AT HOUR 1 AND
 * WILL LIVE M HOURS (M <= 50): PRINT THE HOUR AT WHICH HE WILL DIE
 * EXAMPLE: M=10 -> 3 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int m = 0, hour;

	printf("m = ");
	scanf("%d", &m);

	/* START AT HOUR 1 AND MOVE M HOURS; THE CLOCK STARTS OVER AFTER EVERY 4 HOURS */
	hour = (1 + m) % 4;
	if (hour == 0)
	{
		hour = 4; /* THE CLOCK SHOWS 4, NOT 0 */
	}

	printf("hour %d\n", hour);

	return 0;
}
