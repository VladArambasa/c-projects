/* CULEGERE V.4 - WHITE AND BLACK BALLS
 * ONE BALL AT A TIME IS DRAWN, N TIMES, FROM AN URN WITH WHITE AND BLACK BALLS; PRINT HOW MANY
 * WHITE AND HOW MANY BLACK BALLS WERE DRAWN
 * EXAMPLE: N=5 -> BALLS DRAWN: WHITE BLACK BLACK WHITE BLACK / WHITE BALLS: 2 / BLACK BALLS: 3
 *          (THE BALLS ARE RANDOM)
 * ASSUMPTION: AT EVERY DRAW WHITE AND BLACK ARE EQUALLY LIKELY (THE BALL IS PUT BACK) */
#include <stdio.h>  /* PRINTF, SCANF */
#include <stdlib.h> /* RAND, SRAND */
#include <time.h>   /* TIME */

int main(void)
{
	int n = 0, i;
	int white = 0, black = 0;

	srand(time(NULL)); /* DIFFERENT RANDOM NUMBERS AT EVERY RUN */

	printf("n = ");
	scanf("%d", &n);

	printf("Balls drawn:");
	for (i = 1; i <= n; i++)
	{
		if (rand() % 2 == 0) /* 0 MEANS WHITE, 1 MEANS BLACK */
		{
			printf(" white");
			white++;
		}
		else
		{
			printf(" black");
			black++;
		}
	}
	printf("\n");

	printf("White balls: %d\n", white);
	printf("Black balls: %d\n", black);

	return 0;
}
