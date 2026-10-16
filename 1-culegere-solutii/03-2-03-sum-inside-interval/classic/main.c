/* CULEGERE III.2.3 - SUM OF THE NUMBERS IN AN INTERVAL
 * READ THE TWO ENDS OF AN INTERVAL AND PRINT THE SUM OF THE NATURAL NUMBERS BETWEEN THEM
 * ASSUMPTION: THE ENDS ARE NOT ADDED, AS THE EXAMPLE SHOWS (4 + 5 = 9), AND COME IN ANY ORDER
 * EXAMPLE: 3 6 -> SUM=9 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int a = 0, b = 0, aux, i, sum;

	printf("Interval ends: ");
	scanf("%d %d", &a, &b);

	/* THE THREE GLASSES RULE: A MUST BE THE SMALLER END, OTHERWISE THE LOOP WOULD NOT RUN */
	if (a > b)
	{
		aux = a;
		a = b;
		b = aux;
	}

	sum = 0;
	for (i = a + 1; i < b; i++) /* ONLY THE NUMBERS STRICTLY BETWEEN THE ENDS */
	{
		sum = sum + i;
	}
	printf("sum=%d\n", sum);

	return 0;
}
