/* CULEGERE III.9.13 - SHOOTING RANGE SCORES (V1)
 * IONICA SCORED S POINTS IN AT LEAST TWO SHOTS; EVERY SHOT SCORED, AND EACH ONE SCORED ONE POINT
 * MORE THAN THE ONE BEFORE. PRINT EVERY POSSIBILITY ON ITS OWN LINE (THE NUMBER OF SHOTS AND THE
 * SCORE OF THE FIRST SHOT), THEN "NUMBER OF SOLUTIONS" AND HOW MANY THERE ARE (S <= 998877)
 * ASSUMPTION: THE SOLUTIONS ARE PRINTED FROM THE FEWEST SHOTS TO THE MOST SHOTS
 * V1: TRY EVERY FIRST SCORE AND ADD THE NEXT SCORES UNTIL THE SUM REACHES OR PASSES S
 * EXAMPLE: S=15 -> 2 7 (7+8), 3 4 (4+5+6), 5 1 (1+2+3+4+5), NUMBER OF SOLUTIONS 3 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int s = 0, first, score, shots, sum;
	int solutions = 0;

	printf("S = ");
	scanf("%d", &s);

	/* WITH AT LEAST TWO SHOTS, FIRST + (FIRST + 1) <= S, SO FIRST <= S / 2.
	 * GOING DOWN FROM THE BIGGEST FIRST SCORE GIVES THE SOLUTIONS WITH FEWER SHOTS FIRST */
	for (first = s / 2; first >= 1; first--)
	{
		sum = 0;
		shots = 0;
		score = first;
		while (sum < s) /* ONE MORE SHOT, ONE POINT MORE THAN THE PREVIOUS ONE */
		{
			sum = sum + score;
			score++;
			shots++;
		}
		if (sum == s) /* EXACTLY S POINTS: A SOLUTION */
		{
			printf("%d %d\n", shots, first);
			solutions++;
		}
	}

	printf("Number of solutions %d\n", solutions);

	return 0;
}
