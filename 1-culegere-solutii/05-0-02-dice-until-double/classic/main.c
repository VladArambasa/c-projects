/* CULEGERE V.2 - TWO DICE UNTIL A DOUBLE
 * TWO DICE ARE ROLLED AGAIN AND AGAIN UNTIL A DOUBLE APPEARS (BOTH DICE SHOW THE SAME FACE);
 * PRINT THE SUM OF THE POINTS
 * EXAMPLE: 3 5 / 2 6 / 4 4 -> SUM OF POINTS: 24 (THE ROLLS ARE RANDOM)
 * ASSUMPTION: THE SUM ADDS THE POINTS OF ALL THE ROLLS, THE DOUBLE INCLUDED */
#include <stdio.h>  /* PRINTF */
#include <stdlib.h> /* RAND, SRAND */
#include <time.h>   /* TIME */

int main(void)
{
	int die1, die2;
	int roll = 0, sum = 0;

	srand(time(NULL)); /* DIFFERENT RANDOM NUMBERS AT EVERY RUN */

	do
	{
		die1 = rand() % 6 + 1; /* EACH DIE GIVES 1 TO 6 */
		die2 = rand() % 6 + 1;
		roll++;
		printf("Roll %d: %d %d\n", roll, die1, die2);
		sum = sum + die1 + die2;
	} while (die1 != die2); /* A DOUBLE ENDS THE GAME */

	printf("Sum of points: %d\n", sum);

	return 0;
}
