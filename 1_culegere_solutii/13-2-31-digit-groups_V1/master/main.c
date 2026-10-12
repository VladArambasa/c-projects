/* CULEGERE XIII.2.31 - DIGIT GROUPS
 * THE NATURAL NUMBERS ARE WRITTEN ONE AFTER ANOTHER: 123456789101112131415... AND THE DIGITS ARE
 * CUT INTO GROUPS OF 1, 2, 3, ... DIGITS: 1, 23, 456, 7891, 01112, 131415, ...
 * FOR A GIVEN N (1 <= N <= 250) PRINT THE FIRST AND THE LAST DIGIT OF GROUP N
 * EXAMPLE: N = 8 -> 9 2 (GROUP 8 IS 92021222)
 * METHOD: WRITE THE DIGITS OF 1, 2, 3, ... IN AN ARRAY UNTIL GROUP N IS COMPLETE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAXD 31400 /* GROUPS 1 TO 250 HOLD 250 * 251 / 2 = 31375 DIGITS */

int stream[MAXD]; /* STREAM[P] = THE DIGIT ON POSITION P (POSITIONS START AT 1) */

int main(void)
{
	int d[5]; /* THE DIGITS OF ONE NUMBER, FROM THE LAST ONE */
	int n = 0, first, last, count = 0, number = 0, x, len, i;

	printf("N = ");
	scanf("%d", &n);
	first = (n - 1) * n / 2 + 1; /* GROUPS 1 TO N - 1 HOLD 1 + 2 + ... + (N - 1) DIGITS */
	last = n * (n + 1) / 2;

	/* WRITE 1, 2, 3, ... ONE AFTER ANOTHER UNTIL THE STREAM REACHES POSITION LAST */
	while (count < last)
	{
		number++;
		x = number;
		len = 0;
		while (x > 0)
		{
			d[len] = x % 10;
			x = x / 10;
			len++;
		}
		for (i = len - 1; i >= 0; i--)
		{
			count++;
			stream[count] = d[i]; /* THE DIGITS GO IN STARTING WITH THE FIRST ONE */
		}
	}

	printf("%d %d\n", stream[first], stream[last]);
	return 0;
}
