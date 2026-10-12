/* PATTERN: A RIGHT TRIANGLE OF STARS
 * *
 * **
 * ***
 * ****
 * ***** */
#include <stdio.h> /* PRINTF */

int main(void)
{
	int n = 5;
	int i, j;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++) /* ROW I HAS I STARS */
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
