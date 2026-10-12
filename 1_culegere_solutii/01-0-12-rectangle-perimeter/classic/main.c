/* CULEGERE I.12 - RECTANGLE PERIMETER
 * READ THE LENGTH AND THE WIDTH OF A RECTANGLE; PRINT THE WORD PERIMETER FOLLOWED BY ITS VALUE
 * EXAMPLE: 5 3 -> PERIMETER 16
 * ASSUMPTION: THE SIDES ARE WHOLE NUMBERS */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int length = 0, width = 0, perimeter;

	printf("Length and width: ");
	scanf("%d %d", &length, &width);

	perimeter = 2 * (length + width); /* TWO LENGTHS AND TWO WIDTHS */

	printf("PERIMETER %d\n", perimeter);

	return 0;
}
