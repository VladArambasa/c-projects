/* CULEGERE XIII.1.9 - SNAILS ON POLES (V1)
 * N POLES OF HEIGHTS H[1..N] METERS; AT THE FOOT OF POLE I IS SNAIL I, WHICH CLIMBS P[I] METERS
 * EVERY DAY AND SLIDES DOWN Q[I] METERS EVERY NIGHT (P[I] >= Q[I]); PRINT THE SNAILS IN THE ORDER
 * THEY REACH THE TOPS OF THEIR POLES
 * EXAMPLE: N=3, (H P Q) = (2 1 0), (4 4 4), (5 1 0) -> 2 1 3
 * V1: SIMULATE THE DAYS AND THE NIGHTS ONE BY ONE
 * ASSUMPTION: SNAILS ARRIVING ON THE SAME DAY ARE PRINTED IN THE ORDER OF THEIR NUMBERS
 * ASSUMPTION: A SNAIL WITH P[I] = Q[I] < H[I] NEVER ARRIVES; SUCH SNAILS ARE LISTED APART */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100

int main(void)
{
	int h[MAX + 1], p[MAX + 1], q[MAX + 1];
	int height[MAX + 1]; /* WHERE EVERY SNAIL IS NOW */
	int done[MAX + 1];   /* 1 = ALREADY AT THE TOP */
	int never[MAX + 1];  /* 1 = IT WILL NEVER GET THERE */
	int n = 0, i, reachable = 0, arrived = 0;

	printf("n = ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		printf("Snail %d (h p q): ", i);
		scanf("%d %d %d", &h[i], &p[i], &q[i]);
		height[i] = 0;
		done[i] = 0;
		never[i] = 0;
		if (p[i] < h[i] && p[i] == q[i]) /* EACH NIGHT IT SLIDES BACK ALL IT CLIMBED */
		{
			never[i] = 1;
		}
		else
		{
			reachable++;
		}
	}

	printf("Order:");
	while (arrived < reachable) /* ONE PASS OF THIS LOOP = ONE DAY AND ONE NIGHT */
	{
		for (i = 1; i <= n; i++)
		{
			if (done[i] == 0 && never[i] == 0)
			{
				height[i] = height[i] + p[i]; /* THE DAY: IT CLIMBS */
				if (height[i] >= h[i])
				{
					printf(" %d", i);
					done[i] = 1;
					arrived++;
				}
				else /* THE NIGHT: IT SLIDES DOWN */
				{
					height[i] = height[i] - q[i];
				}
			}
		}
	}
	printf("\n");

	if (reachable < n)
	{
		printf("Never reach the top:");
		for (i = 1; i <= n; i++)
		{
			if (never[i] == 1)
			{
				printf(" %d", i);
			}
		}
		printf("\n");
	}

	return 0;
}
