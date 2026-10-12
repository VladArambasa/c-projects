/* CULEGERE III.1.8 - SUM OF TWO CONSECUTIVE NUMBERS
 * WRITE A NUMBER, IF POSSIBLE, AS A SUM OF TWO CONSECUTIVE NUMBERS
 * ASSUMPTION: 0 IS A NATURAL NUMBER TOO, SO 1=0+1
 * EXAMPLES: 5 -> 5=2+3; 6 -> NOT POSSIBLE */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0, i, found;

	printf("Number: ");
	scanf("%d", &n);

	found = 0;
	/* TRY EVERY PAIR OF CONSECUTIVE NUMBERS I AND I + 1 */
	for (i = 0; i < n; i++)
	{
		if (i + (i + 1) == n)
		{
			printf("%d=%d+%d\n", n, i, i + 1);
			found = 1;
		}
	}
	if (found == 0)
	{
		printf("Not possible\n");
	}

	return 0;
}
