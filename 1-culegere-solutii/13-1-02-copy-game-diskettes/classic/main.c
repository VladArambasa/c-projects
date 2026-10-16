/* CULEGERE XIII.1.2 - COPY THE GAME ON DISKETTES
 * NICU HAS N DISKETTES OF 1400 KB EACH; DISKETTE I ALREADY HAS O[I] KB TAKEN; THE GAME HAS X KB
 * CHOOSE AS FEW DISKETTES AS POSSIBLE TO COPY THE GAME, OR PRINT "THE GAME CANNOT BE COPIED!"
 * EXAMPLE: N=4, O = 1000 200 700 1300, X=1500 -> 2 DISKETTES: 2 3 (1200 + 700 KB FREE)
 * ASSUMPTION: THE GAME MAY BE SPLIT OVER SEVERAL DISKETTES, SO THE ONES WITH THE MOST FREE SPACE
 *   ARE TAKEN FIRST */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100       /* MOST DISKETTES */
#define CAPACITY 1400 /* KB ON EVERY DISKETTE */

int main(void)
{
	int space[MAX + 1];  /* FREE KB ON EVERY DISKETTE */
	int used[MAX + 1];   /* 1 = ALREADY CHOSEN */
	int chosen[MAX + 1]; /* THE CHOSEN DISKETTES, IN THE ORDER THEY WERE TAKEN */
	int n = 0, x = 0, taken = 0, i, best, total = 0, copied = 0, count = 0;

	printf("N = ");
	scanf("%d", &n);
	printf("KB taken on each of the %d diskettes: ", n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &taken);
		space[i] = CAPACITY - taken;
		used[i] = 0;
		total = total + space[i];
	}
	printf("x = ");
	scanf("%d", &x);

	if (total < x) /* EVEN ALL THE FREE SPACE TOGETHER IS NOT ENOUGH */
	{
		printf("The game cannot be copied!\n");
		return 0;
	}

	/* THE BIGGEST FREE SPACES FIRST GIVE THE FEWEST DISKETTES */
	while (copied < x)
	{
		best = 0; /* THE UNUSED DISKETTE WITH THE MOST FREE SPACE */
		for (i = 1; i <= n; i++)
		{
			if (used[i] == 0 && (best == 0 || space[i] > space[best]))
			{
				best = i;
			}
		}
		used[best] = 1;
		copied = copied + space[best];
		count++;
		chosen[count] = best;
	}

	printf("Number of diskettes: %d\n", count);
	printf("Diskettes:");
	for (i = 1; i <= count; i++)
	{
		printf(" %d", chosen[i]);
	}
	printf("\n");

	return 0;
}
