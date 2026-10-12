/* CULEGERE XIII.1.1 - FLOWERS OF ORINTIA
 * A FLOWER OF ORINTIA MAKES X SEEDS EVERY YEAR; WITHIN A YEAR EVERY SEED BECOMES A FLOWER THAT ALSO
 * MAKES X SEEDS; A FLOWER DISAPPEARS AFTER K YEARS; IN THE FIRST YEAR THERE ARE F FLOWERS
 * HOW MANY FLOWERS ARE THERE AT THE END OF YEAR Z?
 * LIMITS: 1 <= F <= 10, 1 <= X <= 6, 1 <= K <= 5, 1 < Z < 5
 * EXAMPLE: F=1 X=2 K=3 Z=3 -> 8 FLOWERS
 *   YEAR 1: 1 FLOWER, 2 SEEDS; YEAR 2: 3 FLOWERS, 6 SEEDS; YEAR 3: 3 + 6 - 1 = 8 FLOWERS
 * ASSUMPTION: A FLOWER MAKES SEEDS IN EACH OF ITS K YEARS AND DISAPPEARS AT THE END OF ITS
 *   K-TH YEAR, SO IT IS NOT COUNTED AT THE END OF THAT YEAR (THE "- 1" OF THE EXAMPLE) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAXZ 4 /* Z < 5 */

int main(void)
{
	int born[MAXZ + 1]; /* BORN[Y] = HOW MANY NEW FLOWERS APPEAR IN YEAR Y */
	int f = 0, x = 0, k = 0, z = 0;
	int y, b, alive, total;

	printf("f = ");
	scanf("%d", &f);
	printf("x = ");
	scanf("%d", &x);
	printf("k = ");
	scanf("%d", &k);
	printf("z = ");
	scanf("%d", &z);

	born[1] = f;
	for (y = 1; y < z; y++)
	{
		alive = 0; /* THE FLOWERS LIVING IN YEAR Y ARE THOSE BORN IN YEARS Y-K+1 ... Y */
		for (b = 1; b <= y; b++)
		{
			if (b >= y - k + 1)
			{
				alive = alive + born[b];
			}
		}
		born[y + 1] = alive * x; /* THEIR SEEDS ARE THE NEW FLOWERS OF NEXT YEAR */
	}

	total = 0; /* AT THE END OF YEAR Z, THE FLOWERS BORN IN YEAR Z-K+1 OR EARLIER ARE GONE */
	for (b = 1; b <= z; b++)
	{
		if (b >= z - k + 2)
		{
			total = total + born[b];
		}
	}
	printf("%d flowers\n", total);

	return 0;
}
