/* CULEGERE XIII.1.9 - SNAILS ON POLES (V2)
 * N POLES OF HEIGHTS H[1..N] METERS; AT THE FOOT OF POLE I IS SNAIL I, WHICH CLIMBS P[I] METERS
 * EVERY DAY AND SLIDES DOWN Q[I] METERS EVERY NIGHT (P[I] >= Q[I]); PRINT THE SNAILS IN THE ORDER
 * THEY REACH THE TOPS OF THEIR POLES
 * EXAMPLE: N=3, (H P Q) = (2 1 0), (4 4 4), (5 1 0) -> 2 1 3
 * V2: A FORMULA GIVES THE DAY OF ARRIVAL OF EVERY SNAIL, NO MATTER HOW HIGH THE POLE IS
 * ASSUMPTION: SNAILS ARRIVING ON THE SAME DAY ARE PRINTED IN THE ORDER OF THEIR NUMBERS
 * ASSUMPTION: A SNAIL WITH P[I] = Q[I] < H[I] NEVER ARRIVES; SUCH SNAILS ARE LISTED APART */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100

int main(void)
{
	int h[MAX + 1], p[MAX + 1], q[MAX + 1];
	int days[MAX + 1];    /* THE DAY SNAIL I ARRIVES, 0 = NEVER */
	int printed[MAX + 1]; /* 1 = ALREADY PRINTED */
	int n = 0, i, step, best, reachable = 0;

	printf("n = ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		printf("Snail %d (h p q): ", i);
		scanf("%d %d %d", &h[i], &p[i], &q[i]);
		printed[i] = 0;
		if (p[i] >= h[i]) /* IT GETS THERE ON THE FIRST DAY */
		{
			days[i] = 1;
		}
		else if (p[i] == q[i]) /* EACH NIGHT IT SLIDES BACK ALL IT CLIMBED */
		{
			days[i] = 0;
		}
		else
		{
			/* A DAY AND A NIGHT RAISE IT BY P - Q; IT ARRIVES ON THE FIRST DAY
			 * THAT STARTS AT HEIGHT H - P OR HIGHER, AFTER (H - P) / (P - Q) NIGHTS,
			 * ROUNDED UP; (A + B - 1) / B IS A / B ROUNDED UP */
			days[i] = (h[i] - p[i] + (p[i] - q[i]) - 1) / (p[i] - q[i]) + 1;
		}
		if (days[i] > 0)
		{
			reachable++;
		}
	}

	printf("Order:");
	for (step = 1; step <= reachable; step++)
	{
		best = 0; /* THE EARLIEST SNAIL NOT PRINTED YET; ON A TIE, THE SMALLER NUMBER */
		for (i = 1; i <= n; i++)
		{
			if (days[i] > 0 && printed[i] == 0 && (best == 0 || days[i] < days[best]))
			{
				best = i;
			}
		}
		printf(" %d", best);
		printed[best] = 1;
	}
	printf("\n");

	if (reachable < n)
	{
		printf("Never reach the top:");
		for (i = 1; i <= n; i++)
		{
			if (days[i] == 0)
			{
				printf(" %d", i);
			}
		}
		printf("\n");
	}

	return 0;
}
