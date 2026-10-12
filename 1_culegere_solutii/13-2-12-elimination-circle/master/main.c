/* CULEGERE XIII.2.12 - THE ELIMINATION CIRCLE
 * N CHILDREN WITH THE NUMBERS 1 ... N ON THEIR SHIRTS STAND ON A CIRCLE. THE TEACHER COUNTS K
 * CHILDREN AND THE K-TH ONE LEAVES THE CIRCLE; THE COUNT GOES ON FROM THE NEXT CHILD, AND SO ON.
 * FIND HOW THE CHILDREN MUST STAND SO THAT THEY LEAVE IN THE ORDER 1, 2, ..., N (N, K <= 50);
 * PRINT THE CIRCLE STARTING WITH CHILD 1
 * EXAMPLE: N=5 K=2 -> 1 5 2 4 3 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 50

int main(void)
{
	int place[MAX] = {0}; /* PLACE[I] = THE CHILD ON PLACE I OF THE CIRCLE, 0 = NOT KNOWN YET */
	int n = 0, k = 0, child, pos, count, first = 0, i;

	printf("n = ");
	scanf("%d", &n);
	printf("k = ");
	scanf("%d", &k);

	/* PLAY THE GAME ON EMPTY PLACES: THE PLACE THAT LEAVES FIRST MUST HOLD CHILD 1, THE NEXT
	 * ONE CHILD 2, AND SO ON; A PLACE THAT ALREADY HAS ITS CHILD IS OUT OF THE CIRCLE */
	pos = n - 1; /* THE COUNT STARTS WITH PLACE 0 */
	for (child = 1; child <= n; child++)
	{
		count = 0;
		while (count < k)
		{
			pos = (pos + 1) % n; /* NEXT PLACE ON THE CIRCLE */
			if (place[pos] == 0)
			{
				count++; /* THIS PLACE IS STILL IN THE GAME */
			}
		}
		place[pos] = child;
		if (child == 1)
		{
			first = pos;
		}
	}

	/* GO ROUND THE CIRCLE ONCE, STARTING FROM CHILD 1 */
	printf("Starting order:");
	for (i = 0; i < n; i++)
	{
		printf(" %d", place[(first + i) % n]);
	}
	printf("\n");

	return 0;
}
