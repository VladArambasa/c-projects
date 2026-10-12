/* CULEGERE II.1.1 - SMALLER OF TWO
 * READ TWO NUMBERS AND PRINT THE SMALLER ONE
 * EXAMPLE: 44 32 -> 32 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int a = 0, b = 0;

	printf("The two numbers: ");
	scanf("%d %d", &a, &b);

	if (a < b) /* COMPARE THE TWO VALUES */
	{
		printf("%d\n", a);
	}
	else
	{
		printf("%d\n", b); /* B IS SMALLER (OR THEY ARE EQUAL) */
	}

	return 0;
}
