/* CULEGERE VI.7.12 - ELEMENT AT POSITION K
 * IN THE SEQUENCE 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, ... EVERY NUMBER V IS WRITTEN V TIMES.
 * READ K AND PRINT THE ELEMENT ON POSITION K
 * V2: NO VECTOR: THE GROUP OF V HAS V ELEMENTS, SO SKIP WHOLE GROUPS UNTIL K FALLS INSIDE ONE
 * EXAMPLE (NOT IN THE BOOK): K=7 -> 4 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int k = 0, v;

	printf("k = ");
	scanf("%d", &k);

	v = 1;
	while (k > v) /* POSITION K IS AFTER THE WHOLE GROUP OF V */
	{
		k = k - v; /* SKIP THE V ELEMENTS EQUAL TO V */
		v++;
	}

	printf("%d\n", v); /* NOW K <= V: POSITION K IS INSIDE THE GROUP OF V */

	return 0;
}
