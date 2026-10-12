/* CULEGERE XIII.2.6 - THE DUCK HUNTER
 * DUCKS COME IN ROWS OF 1, 2, 3, 5, 8, 13... (EACH ROW HAS AS MANY DUCKS AS THE TWO ROWS BEFORE
 * IT TOGETHER). IN A ROW THE COLORS ALTERNATE, STARTING WITH A WHITE DUCK. WHITE DUCKS NEED WHITE
 * ARROWS, BLACK DUCKS NEED BLACK ARROWS, AND A ROW MAY BE STARTED ONLY IF ALL ITS DUCKS CAN BE
 * SHOT. WITH KA WHITE AND KB BLACK ARROWS (0 <= KA, KB <= 2000000000) PRINT THE NUMBER OF ROWS
 * SHOT DOWN AND HOW MANY WHITE AND BLACK ARROWS ARE LEFT
 * EXAMPLE: KA=9 KB=10 -> 4 ROWS, 2 WHITE AND 6 BLACK ARROWS LEFT */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	long long ka = 0, kb = 0;          /* THE ARROWS LEFT */
	long long size = 1, next = 2, sum; /* DUCKS IN THE CURRENT ROW AND IN THE ONE AFTER IT */
	int rows = 0;

	printf("ka = ");
	scanf("%lld", &ka);
	printf("kb = ");
	scanf("%lld", &kb);

	/* A ROW OF SIZE DUCKS HAS (SIZE + 1) / 2 WHITE DUCKS (1ST, 3RD, ...) AND SIZE / 2 BLACK ONES;
	 * THE ROWS ONLY GROW, SO THE HUNTER STOPS AT THE FIRST ROW HE CANNOT SHOOT COMPLETELY */
	while (ka >= (size + 1) / 2 && kb >= size / 2)
	{
		ka = ka - (size + 1) / 2;
		kb = kb - size / 2;
		rows++;

		sum = size + next; /* MOVE ON TO THE NEXT ROW */
		size = next;
		next = sum;
	}

	printf("Rows shot down: %d\n", rows);
	printf("White arrows left: %lld\n", ka);
	printf("Black arrows left: %lld\n", kb);

	return 0;
}
