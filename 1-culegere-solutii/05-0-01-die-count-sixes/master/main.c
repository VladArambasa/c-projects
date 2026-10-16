/* CULEGERE V.1 - ROLLING A DIE
 * SIMULATE N ROLLS OF A DIE: PRINT THE FACE OF EVERY ROLL AND HOW MANY TIMES THE VALUE 6 APPEARED
 * EXAMPLE: N=5 -> FACES: 3 6 1 6 2 / THE VALUE 6 APPEARED 2 TIMES (THE FACES ARE RANDOM) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0, i, face;
	int sixes = 0;

	srand(time(NULL)); /* START THE RANDOM NUMBERS FROM THE CLOCK, SO EVERY RUN IS DIFFERENT */

	printf("n = ");
	scanf("%d", &n);

	printf("Faces:");
	for (i = 1; i <= n; i++)
	{
		face = rand() % 6 + 1; /* THE REMAINDER IS 0..5, SO THE FACE IS 1..6 */
		printf(" %d", face);
		if (face == 6)
		{
			sixes++;
		}
	}
	printf("\n");

	printf("The value 6 appeared %d %s\n", sixes, (sixes == 1) ? "time" : "times");

	return 0;
}
