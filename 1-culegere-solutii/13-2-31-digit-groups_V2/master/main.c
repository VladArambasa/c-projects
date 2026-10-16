/* CULEGERE XIII.2.31 - DIGIT GROUPS
 * THE NATURAL NUMBERS ARE WRITTEN ONE AFTER ANOTHER: 123456789101112131415... AND THE DIGITS ARE
 * CUT INTO GROUPS OF 1, 2, 3, ... DIGITS: 1, 23, 456, 7891, 01112, 131415, ...
 * FOR A GIVEN N (1 <= N <= 250) PRINT THE FIRST AND THE LAST DIGIT OF GROUP N
 * EXAMPLE: N = 8 -> 9 2 (GROUP 8 IS 92021222)
 * IMPROVEMENT: THE DIGIT ON A POSITION IS FOUND DIRECTLY, SKIPPING WHOLE BLOCKS OF NUMBERS */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

/* THE DIGIT ON POSITION P (POSITIONS START AT 1) OF 123456789101112... */
int digit_at(int p)
{
	int len = 1, count = 9, start = 1, number, i;

	/* SKIP THE 9 ONE-DIGIT NUMBERS, THE 90 TWO-DIGIT NUMBERS, ... WHILE P IS AFTER THEM */
	while (p > len * count)
	{
		p = p - len * count;
		len++;
		count = count * 10;
		start = start * 10;
	}
	number = start + (p - 1) / len; /* EVERY NUMBER OF THIS BLOCK TAKES LEN POSITIONS */
	/* THE WANTED DIGIT IS DIGIT (P - 1) % LEN OF THE NUMBER, COUNTED FROM THE LEFT FROM 0:
	 * CUT OFF THE DIGITS ON ITS RIGHT */
	for (i = (p - 1) % len; i < len - 1; i++)
	{
		number = number / 10;
	}
	return number % 10;
}

int main(void)
{
	int n = 0, first, last;

	printf("N = ");
	scanf("%d", &n);
	first = (n - 1) * n / 2 + 1; /* GROUPS 1 TO N - 1 HOLD 1 + 2 + ... + (N - 1) DIGITS */
	last = n * (n + 1) / 2;

	printf("%d %d\n", digit_at(first), digit_at(last));
	return 0;
}
