/* CULEGERE VI.6.2 - INCREASING VECTOR
 * CHECK IF A VECTOR OF N INTEGERS IS MONOTONICALLY INCREASING
 * ASSUMPTION: EQUAL NEIGHBOURS ARE ALLOWED: EVERY ELEMENT MUST BE AT LEAST AS LARGE AS THE ONE
 * BEFORE IT
 * EXAMPLES (NOT IN THE BOOK): N=4, 1 3 3 8 -> YES; N=3, 2 5 4 -> NO */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100 /* AT MOST 100 NUMBERS */

int main(void)
{
	int a[MAX];
	int n = 0, i, ok;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	ok = 1; /* INCREASING, UNTIL TWO NEIGHBOURS PROVE THE OPPOSITE */
	for (i = 1; i < n; i++)
	{
		if (a[i] < a[i - 1]) /* A STEP DOWN; FOR STRICTLY INCREASING, WRITE <= HERE */
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
