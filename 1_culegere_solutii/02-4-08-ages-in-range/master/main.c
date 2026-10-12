/* CULEGERE II.4.8 - AGES BETWEEN 18 AND 60
 * READ THE AGES OF 3 PEOPLE AND PRINT THE AGES BETWEEN 18 AND 60
 * EXAMPLE: 56 34 12 -> 56 34
 * ASSUMPTION: 18 AND 60 ARE INCLUDED */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int a = 0, b = 0, c = 0;

	printf("The three ages: ");
	scanf("%d %d %d", &a, &b, &c);

	/* AN AGE IS PRINTED IF IT IS AT LEAST 18 AND AT MOST 60 */
	if (a >= 18 && a <= 60)
	{
		printf("%d ", a);
	}
	if (b >= 18 && b <= 60)
	{
		printf("%d ", b);
	}
	if (c >= 18 && c <= 60)
	{
		printf("%d ", c);
	}
	printf("\n");

	return 0;
}
