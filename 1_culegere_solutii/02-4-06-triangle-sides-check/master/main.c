/* CULEGERE II.4.6 - TRIANGLE SIDES CHECK
 * READ THREE NUMBERS SMALLER THAN 32000 AND CHECK WHETHER THEY CAN BE THE SIDES OF A TRIANGLE:
 * EACH ONE MUST BE SMALLER THAN THE SUM OF THE OTHER TWO
 * EXAMPLES: 3 5 7 -> YES; 2 5 9 -> NO */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int a = 0, b = 0, c = 0;

	printf("The three numbers: ");
	scanf("%d %d %d", &a, &b, &c);

	if (a < b + c && b < a + c && c < a + b) /* ALL THREE CONDITIONS MUST BE TRUE */
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}

	return 0;
}
