/* PATTERN: A TRIANGLE OF NUMBERS
 * 1
 * 12
 * 123
 * 1234
 * 12345 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 5;
	int i, j;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++) /* ROW I: THE NUMBERS 1 TO I */
		{
			printf("%d", j);
		}
		printf("\n");
	}

	return 0;
}
