/* CULEGERE III.7.12 - LAST DIGIT OF A SUM (V2)
 * TWO NUMBERS A < B < 5000000 ARE READ; PRINT THE LAST DIGIT OF THE SUM OF ALL THE NUMBERS
 * BETWEEN A AND B
 * ASSUMPTION: A AND B ARE PART OF THE SUM, AS THE EXAMPLE SHOWS (12 + 13 + 14 = 39)
 * V2: GAUSS'S FORMULA (FIRST + LAST) * COUNT / 2 GIVES THE SUM AT ONCE, WITH NO LOOP
 * EXAMPLES: A=12 B=14 -> 9; A=1000000 B=3000000 -> 0 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int a = 0, b = 0;
	long long sum; /* UP TO ABOUT 12500000000000: TOO BIG FOR AN INT */

	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);

	/* WRITE THE SUM ONCE FORWARDS AND ONCE BACKWARDS, ONE UNDER THE OTHER: EVERY COLUMN
	 * ADDS UP TO A + B AND THERE ARE B - A + 1 COLUMNS,
	 * SO TWICE THE SUM IS (A + B) * (B - A + 1) */
	sum = (long long)(a + b) * (b - a + 1) / 2;

	printf("%lld\n", sum % 10);

	return 0;
}
