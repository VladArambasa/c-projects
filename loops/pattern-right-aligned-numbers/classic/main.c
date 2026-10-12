/* PATTERN: NUMBERS ALIGNED TO THE RIGHT
 *     5
 *    45
 *   345
 *  2345
 * 12345 */
#include <stdio.h> /* PRINTF */

int main(void)
{
	int n = 5;
	int i, j;

	for (i = n; i >= 1; i--)
	{
		for (j = 1; j < i; j++) /* I - 1 SPACES */
		{
			printf(" ");
		}
		for (j = i; j <= n; j++) /* THEN THE NUMBERS I TO N */
		{
			printf("%d", j);
		}
		printf("\n");
	}

	return 0;
}
