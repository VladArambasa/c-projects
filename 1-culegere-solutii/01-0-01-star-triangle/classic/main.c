/* CULEGERE I.1 - STAR TRIANGLE
 * PRINT A TRIANGLE OF STARS WITH 3 ROWS (*, **, ***), THEN READ A CHARACTER
 * AND PRINT THE SAME TRIANGLE MADE OF THAT CHARACTER
 * EXAMPLE: # -> #, ##, ### (ONE ROW PER LINE) */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	char c = ' ';

	/* THE STAR TRIANGLE: ONE PRINTF FOR EACH ROW */
	printf("*\n");
	printf("**\n");
	printf("***\n");

	printf("Character: ");
	scanf(" %c", &c); /* THE SPACE BEFORE %C SKIPS SPACES AND NEW LINES */

	/* THE SAME TRIANGLE, BUILT WITH THE CHARACTER READ */
	printf("%c\n", c);
	printf("%c%c\n", c, c);
	printf("%c%c%c\n", c, c, c);

	return 0;
}
