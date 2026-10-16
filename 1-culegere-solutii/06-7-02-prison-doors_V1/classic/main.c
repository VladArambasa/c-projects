/* CULEGERE VI.7.2 - PRISON DOORS
 * A PRISON HAS N CELLS, N PRISONERS AND N GUARDS; ALL THE DOORS ARE CLOSED AT FIRST. GUARD K
 * STARTS AT CELL K AND, GOING K CELLS AT A TIME, CHANGES THE STATE OF EVERY DOOR HE PASSES
 * (A CLOSED DOOR IS OPENED, AN OPEN ONE IS CLOSED). THE PRISONERS WHOSE DOORS STAY OPEN ARE
 * RELEASED: PRINT THEIR CELLS
 * V1: SIMULATE THE WALK OF EVERY GUARD ON A VECTOR OF DOORS
 * EXAMPLE: N=50 -> 1 4 9 16 25 36 49 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 1000 /* AT MOST 1000 CELLS */

int main(void)
{
	int door[MAX + 1]; /* DOOR[I] = 1 IF THE DOOR OF CELL I IS OPEN; CELLS ARE NUMBERED FROM 1 */
	int n = 0, i, k;

	printf("n = ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++) /* ALL THE DOORS ARE CLOSED AT FIRST */
	{
		door[i] = 0;
	}

	for (k = 1; k <= n; k++) /* GUARD K VISITS THE CELLS K, 2K, 3K, ... */
	{
		for (i = k; i <= n; i = i + k)
		{
			door[i] = 1 - door[i]; /* 0 BECOMES 1 AND 1 BECOMES 0 */
		}
	}

	printf("Released from cells: ");
	for (i = 1; i <= n; i++)
	{
		if (door[i] == 1)
		{
			printf("%d ", i);
		}
	}
	printf("\n");

	return 0;
}
