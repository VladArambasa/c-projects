/* CULEGERE III.9.9 - THE TIRED FROG
 * A FROG JUMPS P CM EVERY SECOND; AFTER EVERY N SECONDS ITS JUMP BECOMES HALF AS LONG.
 * READ P, N AND THE TOTAL TIME T IN SECONDS; PRINT THE TOTAL DISTANCE WITH TWO DECIMALS
 * LIMITS: P, N, T < 30000 AND T / N < 16
 * EXAMPLE: P=20 N=10 T=33 -> 357.50 CM (10 * 20 + 10 * 10 + 10 * 5 + 3 * 2.5) */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int p = 0, n = 0, t = 0, second;
	double jump;          /* THE JUMP CAN BECOME 2.5, 1.25... SO IT IS A REAL NUMBER */
	double distance = 0;

	printf("p = ");
	scanf("%d", &p);
	printf("n = ");
	scanf("%d", &n);
	printf("T = ");
	scanf("%d", &t);

	jump = p;
	for (second = 1; second <= t; second++)
	{
		distance = distance + jump; /* ONE JUMP EVERY SECOND */
		if (second % n == 0) /* AFTER EVERY N SECONDS THE FROG GETS MORE TIRED */
		{
			jump = jump / 2;
		}
	}

	printf("%.2f cm\n", distance);

	return 0;
}
