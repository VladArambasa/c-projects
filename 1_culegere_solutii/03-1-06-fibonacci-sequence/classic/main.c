/* CULEGERE III.1.6 - FIBONACCI SEQUENCE
 * PRINT THE FIRST N TERMS OF THE FIBONACCI SEQUENCE 0,1,1,2,3,5,8,13,21,...
 * (EVERY TERM IS THE SUM OF THE TWO TERMS BEFORE IT)
 * ASSUMPTION: N <= 90, SO THAT EVERY TERM FITS IN A LONG LONG
 * EXAMPLE: N=9 -> 0 1 1 2 3 5 8 13 21 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0, i;
	long long a, b, next; /* THE TERMS GROW FAST: FROM THE 48TH ON THEY DO NOT FIT IN AN INT */

	printf("n = ");
	scanf("%d", &n);

	a = 0; /* THE CURRENT TERM */
	b = 1; /* THE TERM AFTER IT */
	for (i = 1; i <= n; i++)
	{
		printf("%lld ", a);
		next = a + b; /* ONE STEP FORWARD: (A, B) BECOMES (B, A + B) */
		a = b;
		b = next;
	}
	printf("\n");

	return 0;
}
