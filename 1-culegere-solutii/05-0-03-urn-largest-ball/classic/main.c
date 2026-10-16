/* CULEGERE V.3 - THE LARGEST BALL
 * N BALLS ARE DRAWN FROM AN URN WITH BALLS NUMBERED FROM 1 TO 20 (THE COMPUTER GENERATES THEIR
 * VALUES); PRINT THE LARGEST VALUE DRAWN
 * EXAMPLE: N=4 -> BALLS: 7 15 3 12 / LARGEST VALUE: 15 (THE BALLS ARE RANDOM)
 * ASSUMPTION: EVERY BALL IS PUT BACK, SO THE SAME VALUE CAN BE DRAWN AGAIN */
#include <stdio.h>  /* PRINTF, SCANF */
#include <stdlib.h> /* RAND, SRAND */
#include <time.h>   /* TIME */

int main(void)
{
	int n = 0, i, ball;
	int max = 0; /* SMALLER THAN ANY BALL, SO THE FIRST BALL REPLACES IT */

	srand(time(NULL)); /* DIFFERENT RANDOM NUMBERS AT EVERY RUN */

	printf("n = ");
	scanf("%d", &n);

	printf("Balls:");
	for (i = 1; i <= n; i++)
	{
		ball = rand() % 20 + 1; /* FROM 1 TO 20 */
		printf(" %d", ball);
		if (ball > max)
		{
			max = ball;
		}
	}
	printf("\n");

	printf("Largest value: %d\n", max);

	return 0;
}
