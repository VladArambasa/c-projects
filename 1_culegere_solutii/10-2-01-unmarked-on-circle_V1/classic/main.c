/* CULEGERE X.2.1 - UNMARKED NUMBERS ON A CIRCLE
 * THE NUMBERS 1..N STAND IN INCREASING ORDER ON A CIRCLE, SO N IS NEXT TO 1. STARTING WITH
 * THE NUMBER S, EVERY K-TH NUMBER IS MARKED, GOING UP, UNTIL A NUMBER IS MARKED A SECOND TIME.
 * HOW MANY NUMBERS STAY UNMARKED?
 * EXAMPLE: N = 12, S = 1, K = 4 -> 1, 5, 9 ARE MARKED, THEN 1 AGAIN -> 9 UNMARKED NUMBERS */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 10000 /* AT MOST 10000 NUMBERS ON THE CIRCLE */

int main(void)
{
	int marked[MAX + 1]; /* MARKED[I] = 1 WHEN THE NUMBER I IS MARKED */
	int n = 0, s = 0, k = 0, i, pos, count = 0;

	printf("n = ");
	scanf("%d", &n);
	printf("s = ");
	scanf("%d", &s);
	printf("k = ");
	scanf("%d", &k);

	for (i = 1; i <= n; i++)
	{
		marked[i] = 0;
	}
	pos = s;
	while (marked[pos] == 0) /* STOP AT THE FIRST NUMBER THAT IS ALREADY MARKED */
	{
		marked[pos] = 1;
		count++;
		pos = (pos - 1 + k) % n + 1; /* K PLACES FURTHER; AFTER N COMES 1 AGAIN */
	}

	printf("Unmarked numbers: %d\n", n - count);

	return 0;
}
