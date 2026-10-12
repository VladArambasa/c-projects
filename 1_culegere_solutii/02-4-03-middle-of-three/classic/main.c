/* CULEGERE II.4.3 - MIDDLE OF THREE
 * THREE DIFFERENT NUMBERS ARE READ; PRINT THE ONE WHOSE VALUE LIES BETWEEN THE OTHER TWO
 * EXAMPLE: 12 14 10 -> 12 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int a = 0, b = 0, c = 0;

	printf("The three numbers: ");
	scanf("%d %d %d", &a, &b, &c);

	/* A IS IN THE MIDDLE IF B < A < C OR C < A < B; THE SAME IDEA FOR B */
	if ((b < a && a < c) || (c < a && a < b))
	{
		printf("%d\n", a);
	}
	else if ((a < b && b < c) || (c < b && b < a))
	{
		printf("%d\n", b);
	}
	else
	{
		printf("%d\n", c);
	}

	return 0;
}
