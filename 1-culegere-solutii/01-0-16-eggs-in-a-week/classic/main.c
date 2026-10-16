/* CULEGERE I.16 - EGGS IN A WEEK
 * A HOUSEHOLD HAS 4 HENS; THE NUMBERS OF EGGS THEY LAY IN A DAY ARE READ INTO A, B, C, D.
 * PRINT HOW MANY EGGS ARE OBTAINED IN A WEEK
 * EXAMPLE: 1 1 0 1 -> 21 EGGS */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int a = 0, b = 0, c = 0, d = 0, per_day;

	printf("a b c d = ");
	scanf("%d %d %d %d", &a, &b, &c, &d);

	per_day = a + b + c + d; /* EGGS FROM ALL 4 HENS IN ONE DAY */

	printf("%d eggs\n", per_day * 7); /* A WEEK HAS 7 DAYS */

	return 0;
}
