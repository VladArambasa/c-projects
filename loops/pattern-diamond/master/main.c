/* PATTERN: A DIAMOND OF STARS
 *    *
 *   ***
 *  *****
 * *******
 *  *****
 *   ***
 *    * */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 4; /* ROWS IN THE TOP HALF */
	int i, j;

	for (i = 1; i <= n; i++) /* TOP HALF */
	{
		for (j = 1; j <= n - i; j++) /* SPACES BEFORE THE STARS */
		{
			printf(" ");
		}
		for (j = 1; j <= 2 * i - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	for (i = n - 1; i >= 1; i--) /* BOTTOM HALF */
	{
		for (j = 1; j <= n - i; j++)
		{
			printf(" ");
		}
		for (j = 1; j <= 2 * i - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
