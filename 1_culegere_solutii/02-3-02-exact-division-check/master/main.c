/* CULEGERE II.3.2 - EXACT DIVISION CHECK
 * READ TWO NONZERO NUMBERS AND CHECK WHETHER THE FIRST ONE CAN BE DIVIDED EXACTLY BY THE SECOND
 * EXAMPLE: 45 7 -> NO */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int a = 0, b = 0;

	printf("The two numbers: ");
	scanf("%d %d", &a, &b);

	if (a % b == 0) /* REMAINDER 0 MEANS EXACT DIVISION */
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}

	return 0;
}
