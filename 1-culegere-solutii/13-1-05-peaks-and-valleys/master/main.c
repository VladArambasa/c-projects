/* CULEGERE XIII.1.5 - PEAKS AND VALLEYS
 * THE DIGITS OF A NUMBER GIVE THE HEIGHTS OF A SKI ROUTE; THE SKIER WANTS AT LEAST ONE PEAK
 * (A DIGIT BIGGER THAN BOTH ITS NEIGHBOURS) AND AT LEAST ONE VALLEY (A DIGIT SMALLER THAN BOTH
 * NEIGHBOURS); SAY WHETHER HE TAKES THE ROUTE
 * EXAMPLE: 5745 -> YES;  123 -> NO;  68556 -> NO
 * ASSUMPTION: A DIGIT EQUAL TO ONE OF ITS NEIGHBOURS IS NEITHER A PEAK NOR A VALLEY */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int digit[10]; /* AN INT HAS AT MOST 10 DIGITS */
	int x = 0, n = 0, i, peak = 0, valley = 0;

	printf("The number: ");
	scanf("%d", &x);

	do /* SPLIT THE NUMBER INTO DIGITS (FROM THE RIGHT: THE ORDER DOES NOT CHANGE THE ANSWER) */
	{
		digit[n] = x % 10;
		n++;
		x = x / 10;
	} while (x > 0);

	for (i = 1; i < n - 1; i++) /* THE FIRST AND THE LAST DIGIT HAVE ONLY ONE NEIGHBOUR */
	{
		if (digit[i] > digit[i - 1] && digit[i] > digit[i + 1])
		{
			peak = 1;
		}
		if (digit[i] < digit[i - 1] && digit[i] < digit[i + 1])
		{
			valley = 1;
		}
	}

	if (peak == 1 && valley == 1)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}

	return 0;
}
