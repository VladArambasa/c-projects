/* CULEGERE XIII.2.11 - FLIPPING THE DISCS
 * N DISCS (1 <= N <= 100) WITH DIFFERENT DIAMETERS (1 ... 999) ARE ON A ROD. THE ONLY MOVE: A
 * CLAMP TAKES THE TOP K DISCS OFF THE ROD AND PUTS THEM BACK UPSIDE DOWN. ARRANGE THE DISCS WITH
 * THE DIAMETERS DECREASING FROM THE BOTTOM UP; FOR EVERY MOVE PRINT K AND THE NEW ORDER ON THE ROD
 * EXAMPLE: 5 3 2 1 4 -> K=4: 5 4 1 2 3, THEN K=3: 5 4 3 2 1
 * ASSUMPTION: THE DIAMETERS ARE READ AND PRINTED FROM THE BOTTOM UP, AS THE EXAMPLE SHOWS
 * ASSUMPTION: THE STATEMENT'S "2<K" IS READ AS K >= 2 (WITH K >= 3 ONLY, THE DISCS 1 2 COULD
 *             NEVER BE ARRANGED) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100

/* TURNS THE TOP K DISCS UPSIDE DOWN (POSITION 1 IS THE BOTTOM, POSITION N IS THE TOP),
 * THEN PRINTS THE MOVE */
void flip(int disc[], int n, int k)
{
	int left = n - k + 1, right = n, aux, i;

	while (left < right)
	{
		aux = disc[left];
		disc[left] = disc[right];
		disc[right] = aux;
		left++;
		right--;
	}

	printf("k=%d\n", k);
	for (i = 1; i <= n; i++)
	{
		printf("%d ", disc[i]);
	}
	printf("\n");
}

int main(void)
{
	int disc[MAX + 1] = {0};
	int n = 0, i, pos, big, moves = 0;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d diameters, from the bottom up: ", n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &disc[i]);
	}

	/* FILL THE ROD FROM THE BOTTOM: POSITION POS GETS THE LARGEST OF THE DISCS POS ... N */
	for (pos = 1; pos < n; pos++)
	{
		big = pos;
		for (i = pos + 1; i <= n; i++)
		{
			if (disc[i] > disc[big])
			{
				big = i;
			}
		}
		if (big != pos)
		{
			if (big != n)
			{
				flip(disc, n, n - big + 1); /* FIRST BRING THE LARGEST DISC TO THE TOP */
				moves++;
			}
			flip(disc, n, n - pos + 1); /* THEN TURN OVER ALL THE DISCS FROM POS UP */
			moves++;
		}
	}

	if (moves == 0)
	{
		printf("The discs are already in order\n");
	}

	return 0;
}
