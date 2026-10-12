/* CULEGERE VI.6.1 - PROPORTIONAL SEQUENCES
 * TWO SEQUENCES OF N NUMBERS ARE READ; CHECK IF THEIR VALUES, IN THE GIVEN ORDER, ARE
 * PROPORTIONAL: A1 / B1 = A2 / B2 = ... = AN / BN
 * ASSUMPTION: THE NUMBERS ARE NON-ZERO INTEGERS
 * EXAMPLE: N=3, 1 2 3 AND 3 6 9 -> YES */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100 /* AT MOST 100 NUMBERS IN EACH SEQUENCE */

int main(void)
{
	int a[MAX], b[MAX];
	int n = 0, i, ok;

	printf("n = ");
	scanf("%d", &n);
	printf("First sequence: ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("Second sequence: ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
	}

	/* EVERY RATIO A[I] / B[I] MUST BE EQUAL TO THE FIRST ONE, A[0] / B[0]. CROSS
	 * MULTIPLICATION CHECKS THIS WITHOUT DIVIDING: A[I] * B[0] = A[0] * B[I] */
	ok = 1; /* PROPORTIONAL, UNTIL A PAIR PROVES THE OPPOSITE */
	for (i = 1; i < n; i++)
	{
		if (a[i] * b[0] != a[0] * b[i])
		{
			ok = 0;
		}
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
