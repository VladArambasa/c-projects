/* CULEGERE II.4.4 - PUPIL WITH THE BEST SCORE
 * THREE PAIRS (PUPIL NUMBER, SCORE) ARE READ; PRINT THE NUMBER OF THE PUPIL WITH THE HIGHEST
 * SCORE
 * EXAMPLE: 7 120, 3 100, 4 119 -> PUPIL NUMBER 7
 * ASSUMPTION: IF SEVERAL PUPILS HAVE THE HIGHEST SCORE, THE ONE READ FIRST IS PRINTED */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int nr1 = 0, score1 = 0, nr2 = 0, score2 = 0, nr3 = 0, score3 = 0, best;

	printf("Pupil 1 (number and score): ");
	scanf("%d %d", &nr1, &score1);
	printf("Pupil 2 (number and score): ");
	scanf("%d %d", &nr2, &score2);
	printf("Pupil 3 (number and score): ");
	scanf("%d %d", &nr3, &score3);

	/* THE BEST SCORE IS AT LEAST AS BIG AS EACH OF THE OTHER TWO */
	if (score1 >= score2 && score1 >= score3)
	{
		best = nr1;
	}
	else if (score2 >= score1 && score2 >= score3)
	{
		best = nr2;
	}
	else
	{
		best = nr3;
	}

	printf("The highest score belongs to pupil number %d\n", best);

	return 0;
}
