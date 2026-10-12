/* PATTERN: AN UPSIDE-DOWN TRIANGLE PUSHED TO THE RIGHT
 * *****
 *  ****
 *   ***
 *    **
 *     * */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 5;
	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i; j++) /* I SPACES FIRST */
		{
			printf(" ");
		}
		for (j = 0; j < n - i; j++) /* THEN N - I STARS */
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
