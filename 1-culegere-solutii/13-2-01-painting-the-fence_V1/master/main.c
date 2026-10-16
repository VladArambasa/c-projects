/* CULEGERE XIII.2.1 - PAINTING THE FENCE
 * THE BOARDS OF A FENCE ARE NUMBERED 1..N. ONE CHILD PAINTS RED THE BOARDS P, 2P, 3P..., THE
 * OTHER PAINTS BLUE THE BOARDS Q, 2Q, 3Q... (A BOARD PAINTED WITH BOTH COLORS BECOMES VIOLET).
 * PRINT HOW MANY BOARDS ARE A) UNPAINTED, B) RED, C) BLUE, D) VIOLET
 * EXAMPLE: N=25 P=4 Q=6 -> 17 UNPAINTED, 4 RED, 2 BLUE, 2 VIOLET */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0, p = 0, q = 0;
	int board, unpainted = 0, red = 0, blue = 0, violet = 0;

	printf("n = ");
	scanf("%d", &n);
	printf("p = ");
	scanf("%d", &p);
	printf("q = ");
	scanf("%d", &q);

	/* LOOK AT EVERY BOARD: IT GETS RED PAINT IF P DIVIDES ITS NUMBER, BLUE PAINT IF Q DOES */
	for (board = 1; board <= n; board++)
	{
		if (board % p == 0 && board % q == 0)
		{
			violet++; /* RED AND BLUE MAKE VIOLET */
		}
		else if (board % p == 0)
		{
			red++;
		}
		else if (board % q == 0)
		{
			blue++;
		}
		else
		{
			unpainted++;
		}
	}

	printf("a) unpainted: %d\n", unpainted);
	printf("b) red: %d\n", red);
	printf("c) blue: %d\n", blue);
	printf("d) violet: %d\n", violet);

	return 0;
}
