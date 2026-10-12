/* CULEGERE II.4.10 - LARGER DIVISIBLE BY SMALLER
 * READ TWO NUMBERS AND CHECK WHETHER THE LARGER ONE CAN BE DIVIDED EXACTLY BY THE SMALLER ONE
 * EXAMPLE: 10 250 -> 250 IS DIVISIBLE BY 10
 * ASSUMPTION: THE NUMBERS ARE NOT 0 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int a = 0, b = 0, big, small;

	printf("The two numbers: ");
	scanf("%d %d", &a, &b);

	/* FIRST FIND OUT WHICH ONE IS LARGER */
	if (a > b)
	{
		big = a;
		small = b;
	}
	else
	{
		big = b;
		small = a;
	}

	if (big % small == 0) /* REMAINDER 0 MEANS EXACT DIVISION */
	{
		printf("%d is divisible by %d\n", big, small);
	}
	else
	{
		printf("%d is not divisible by %d\n", big, small);
	}

	return 0;
}
