/* CULEGERE III.1.8 - SUM OF TWO CONSECUTIVE NUMBERS
 * WRITE A NUMBER, IF POSSIBLE, AS A SUM OF TWO CONSECUTIVE NUMBERS
 * ASSUMPTION: 0 IS A NATURAL NUMBER TOO, SO 1=0+1
 * IMPROVEMENT: NO LOOP; I + (I + 1) = 2 * I + 1 IS ALWAYS ODD, AND THEN I = N / 2
 * EXAMPLES: 5 -> 5=2+3; 6 -> NOT POSSIBLE */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0;

	printf("Number: ");
	scanf("%d", &n);

	/* TWO CONSECUTIVE NUMBERS ALWAYS ADD UP TO AN ODD NUMBER */
	if (n % 2 == 1)
	{
		printf("%d=%d+%d\n", n, n / 2, n / 2 + 1); /* INTEGER DIVISION: 5 / 2 = 2 */
	}
	else
	{
		printf("Not possible\n");
	}

	return 0;
}
