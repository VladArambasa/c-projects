/* CULEGERE II.2.8 - MENU: SUM OR PRODUCT
 * SHOW THE MENU "1. SUM  2. PRODUCT", READ TWO NUMBERS AND THE NUMBER OF THE CHOSEN OPERATION;
 * PRINT THE EXPRESSION AND ITS VALUE
 * EXAMPLE: 3 4, OPTION 2 -> 3*4=12 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int a = 0, b = 0, option = 0;

	/* THE MENU */
	printf("1. sum\n");
	printf("2. product\n");

	printf("Two numbers: ");
	scanf("%d %d", &a, &b);
	printf("Option: ");
	scanf("%d", &option);

	/* THE OPTION IS COMPARED WITH THE NUMBERS OF THE MENU */
	if (option == 1)
	{
		printf("%d+%d=%d\n", a, b, a + b);
	}
	else if (option == 2)
	{
		printf("%d*%d=%d\n", a, b, a * b);
	}
	else
	{
		printf("Wrong option\n");
	}

	return 0;
}
