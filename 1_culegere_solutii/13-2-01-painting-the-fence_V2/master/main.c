/* CULEGERE XIII.2.1 - PAINTING THE FENCE
 * THE BOARDS OF A FENCE ARE NUMBERED 1..N. ONE CHILD PAINTS RED THE BOARDS P, 2P, 3P..., THE
 * OTHER PAINTS BLUE THE BOARDS Q, 2Q, 3Q... (A BOARD PAINTED WITH BOTH COLORS BECOMES VIOLET).
 * PRINT HOW MANY BOARDS ARE A) UNPAINTED, B) RED, C) BLUE, D) VIOLET
 * EXAMPLE: N=25 P=4 Q=6 -> 17 UNPAINTED, 4 RED, 2 BLUE, 2 VIOLET
 * V2: NO LOOP OVER THE BOARDS; THE MULTIPLES ARE COUNTED WITH N / P, N / Q AND N / LCM(P, Q) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

/* GREATEST COMMON DIVISOR (EUCLID) */
int gcd(int a, int b)
{
	int r;

	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main(void)
{
	int n = 0, p = 0, q = 0;
	int unpainted, red, blue, violet;
	long long lcm; /* P * Q CAN BE TOO BIG FOR AN INT */

	printf("n = ");
	scanf("%d", &n);
	printf("p = ");
	scanf("%d", &p);
	printf("q = ");
	scanf("%d", &q);

	/* A BOARD IS VIOLET WHEN BOTH P AND Q DIVIDE ITS NUMBER, THAT IS WHEN LCM(P, Q) DIVIDES IT */
	lcm = p / gcd(p, q);
	lcm = lcm * q;
	violet = (int)(n / lcm);

	/* N / P BOARDS GOT RED PAINT, BUT THE VIOLET ONES ARE NOT RED ANY MORE; THE SAME FOR BLUE */
	red = n / p - violet;
	blue = n / q - violet;
	unpainted = n - red - blue - violet;

	printf("a) unpainted: %d\n", unpainted);
	printf("b) red: %d\n", red);
	printf("c) blue: %d\n", blue);
	printf("d) violet: %d\n", violet);

	return 0;
}
