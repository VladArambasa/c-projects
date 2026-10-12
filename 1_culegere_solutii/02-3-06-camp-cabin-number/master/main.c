/* CULEGERE II.3.6 - CAMP CABIN NUMBER
 * IN A CAMP THE BOYS ARE PUT 4 IN A CABIN, IN THE ORDER THEY ARRIVE. IONEL ARRIVED N-TH:
 * PRINT THE NUMBER OF HIS CABIN
 * EXAMPLE: N=69 -> CABIN 18
 * NOTE: THE BOOK'S EXAMPLE SAYS N=69 -> CABIN 17; THE CORRECT RESULT IS CABIN 18
 *       (CABIN 17 HOLDS THE BOYS 65-68, SO BOY 69 STARTS CABIN 18) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0, cabin;

	printf("n = ");
	scanf("%d", &n);

	cabin = n / 4; /* THE FIRST N BOYS FILL N / 4 CABINS COMPLETELY */
	if (n % 4 != 0)
	{
		cabin = cabin + 1; /* THE BOYS LEFT OVER, IONEL TOO, GO TO THE NEXT CABIN */
	}

	printf("cabin %d\n", cabin);

	return 0;
}
