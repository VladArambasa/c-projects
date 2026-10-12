/* CULEGERE II.3.1 - EVEN OR ODD
 * READ THREE NUMBERS AND PRINT THEM ONE UNDER THE OTHER, EACH ONE FOLLOWED BY THE WORD EVEN
 * OR ODD
 * EXAMPLE: 45 3 24 -> 45 ODD / 3 ODD / 24 EVEN (ONE PER LINE) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int a = 0, b = 0, c = 0;

	printf("The three numbers: ");
	scanf("%d %d %d", &a, &b, &c);

	/* A NUMBER IS EVEN WHEN THE REMAINDER OF ITS DIVISION BY 2 IS 0 */
	if (a % 2 == 0)
	{
		printf("%d even\n", a);
	}
	else
	{
		printf("%d odd\n", a);
	}

	if (b % 2 == 0)
	{
		printf("%d even\n", b);
	}
	else
	{
		printf("%d odd\n", b);
	}

	if (c % 2 == 0)
	{
		printf("%d even\n", c);
	}
	else
	{
		printf("%d odd\n", c);
	}

	return 0;
}
