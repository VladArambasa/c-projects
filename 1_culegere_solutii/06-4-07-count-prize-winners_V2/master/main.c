/* CULEGERE VI.4.7 - COUNT PRIZE WINNERS
 * THE SCORES OF N PUPILS ARE READ (N <= 300, EVERY SCORE IS A NATURAL NUMBER <= 100). TWO PUPILS
 * GET THE SAME PRIZE ONLY IF THEIR SCORES ARE EQUAL: THE HIGHEST SCORE GETS PRIZE I, THE NEXT
 * DIFFERENT SCORE GETS PRIZE II, THE NEXT ONE PRIZE III. PRINT, ONE PER LINE, HOW MANY PUPILS
 * GET EACH PRIZE
 * V2: A FREQUENCY VECTOR (A SCORE IS AT MOST 100) REPLACES THE SORTING: ONE PASS OVER THE SCORES
 * ASSUMPTION: WITH FEWER THAN THREE DIFFERENT SCORES, A PRIZE NOBODY GETS IS PRINTED AS 0
 * EXAMPLE: N=10, 58 79 34 12 58 40 79 58 30 58 -> 2 4 1 (ONE NUMBER PER LINE) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int count[101] = {0}; /* COUNT[S] = HOW MANY PUPILS HAVE THE SCORE S, FOR S = 0..100 */
	int prizes[4] = {0};  /* PRIZES[1], PRIZES[2], PRIZES[3]; PRIZES[0] IS NOT USED */
	int n = 0, x = 0, i, score, prize;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d scores: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x);
		count[x]++; /* NO NEED TO KEEP THE SCORES, ONLY HOW OFTEN EACH ONE APPEARS */
	}

	/* FROM 100 DOWN, EVERY SCORE THAT SOMEBODY HAS GETS THE NEXT PRIZE */
	prize = 1;
	for (score = 100; score >= 0 && prize <= 3; score--)
	{
		if (count[score] > 0)
		{
			prizes[prize] = count[score];
			prize++;
		}
	}

	printf("%d\n%d\n%d\n", prizes[1], prizes[2], prizes[3]);

	return 0;
}
