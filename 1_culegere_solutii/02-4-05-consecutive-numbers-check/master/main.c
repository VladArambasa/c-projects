/* CULEGERE II.4.5 - CONSECUTIVE NUMBERS
 * READ THREE NUMBERS AND CHECK WHETHER THEY FORM A SEQUENCE OF CONSECUTIVE NUMBERS
 * EXAMPLES: 3 4 5 -> YES; 4 5 7 -> NO
 * ASSUMPTION: THE NUMBERS MUST FOLLOW EACH OTHER IN THE ORDER READ (5 4 3 -> NO) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int a = 0, b = 0, c = 0;

	printf("The three numbers: ");
	scanf("%d %d %d", &a, &b, &c);

	if (b == a + 1 && c == b + 1) /* EACH NUMBER IS THE PREVIOUS ONE PLUS 1 */
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}

	return 0;
}
