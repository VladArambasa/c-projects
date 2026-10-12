/* CULEGERE III.7.4 - EVEN AND ODD DIGITS TAKE TURNS
 * CHECK WHETHER, IN A NATURAL NUMBER, EVEN AND ODD DIGITS ALTERNATE
 * EXAMPLE: 347092 -> YES (ODD, EVEN, ODD, EVEN, ODD, EVEN) */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0, digit, last;
	int ok = 1; /* STAYS 1 WHILE NO TWO NEIGHBOUR DIGITS HAVE THE SAME PARITY */

	printf("n = ");
	scanf("%d", &n);

	last = n % 10; /* START WITH THE LAST DIGIT */
	n = n / 10;
	while (n > 0)
	{
		digit = n % 10; /* THE DIGIT JUST LEFT OF LAST */
		if (digit % 2 == last % 2) /* BOTH EVEN OR BOTH ODD: THEY DO NOT ALTERNATE */
		{
			ok = 0;
		}
		last = digit;
		n = n / 10;
	}

	if (ok == 1)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}

	return 0;
}
