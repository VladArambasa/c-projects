/* CULEGERE II.4.2 - THREE NUMBERS IN INCREASING ORDER
 * READ THREE DIFFERENT NUMBERS AND PRINT THEM IN INCREASING ORDER
 * EXAMPLE: 4 2 6 -> 2 4 6 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int a = 0, b = 0, c = 0;

	printf("The three numbers: ");
	scanf("%d %d %d", &a, &b, &c);

	/* THREE NUMBERS CAN BE ARRANGED IN 6 WAYS; EXACTLY ONE OF THESE CONDITIONS IS TRUE */
	if (a < b && b < c)
	{
		printf("%d %d %d\n", a, b, c);
	}
	else if (a < c && c < b)
	{
		printf("%d %d %d\n", a, c, b);
	}
	else if (b < a && a < c)
	{
		printf("%d %d %d\n", b, a, c);
	}
	else if (b < c && c < a)
	{
		printf("%d %d %d\n", b, c, a);
	}
	else if (c < a && a < b)
	{
		printf("%d %d %d\n", c, a, b);
	}
	else
	{
		printf("%d %d %d\n", c, b, a); /* THE LAST CASE: C < B < A */
	}

	return 0;
}
