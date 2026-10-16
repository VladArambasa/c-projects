/* CULEGERE III.1.1 - NUMBERS A23A DIVISIBLE BY 6
 * PRINT ALL THE NUMBERS OF THE FORM A23A THAT ARE DIVISIBLE BY 6
 * (FOUR-DIGIT NUMBERS WHOSE FIRST AND LAST DIGIT ARE THE SAME DIGIT A)
 * EXAMPLE: NO INPUT -> 2232 8238 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int a, number;

	/* A IS THE FIRST DIGIT, SO IT GOES FROM 1 TO 9 */
	for (a = 1; a <= 9; a++)
	{
		number = a * 1000 + 230 + a; /* THE DIGITS A, 2, 3, A */
		if (number % 6 == 0)
		{
			printf("%d ", number);
		}
	}
	printf("\n");

	return 0;
}
