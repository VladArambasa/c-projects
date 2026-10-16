/* CULEGERE III.9.13 - SHOOTING RANGE SCORES (V2)
 * IONICA SCORED S POINTS IN AT LEAST TWO SHOTS; EVERY SHOT SCORED, AND EACH ONE SCORED ONE POINT
 * MORE THAN THE ONE BEFORE. PRINT EVERY POSSIBILITY ON ITS OWN LINE (THE NUMBER OF SHOTS AND THE
 * SCORE OF THE FIRST SHOT), THEN "NUMBER OF SOLUTIONS" AND HOW MANY THERE ARE (S <= 998877)
 * ASSUMPTION: THE SOLUTIONS ARE PRINTED FROM THE FEWEST SHOTS TO THE MOST SHOTS
 * V2: K SHOTS STARTING WITH SCORE A MAKE K*A + K*(K-1)/2, SO ONLY K IS TRIED (ABOUT 1400 TRIES)
 * EXAMPLE: S=15 -> 2 7 (7+8), 3 4 (4+5+6), 5 1 (1+2+3+4+5), NUMBER OF SOLUTIONS 3 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int s = 0, shots, rest;
	int solutions = 0;

	printf("S = ");
	scanf("%d", &s);

	/* THE SMALLEST TOTAL OF K SHOTS IS 1 + 2 + ... + K = K*(K+1)/2: IT MUST NOT PASS S */
	for (shots = 2; shots * (shots + 1) / 2 <= s; shots++)
	{
		/* K = SHOTS AND A = THE FIRST SCORE:
		 * A + (A+1) + ... + (A+K-1) = K*A + (0 + 1 + ... + K-1) = K*A + K*(K-1)/2 */
		rest = s - shots * (shots - 1) / 2; /* WHAT IS LEFT MUST BE K*A */
		if (rest % shots == 0)
		{
			printf("%d %d\n", shots, rest / shots);
			solutions++;
		}
	}

	printf("Number of solutions %d\n", solutions);

	return 0;
}
