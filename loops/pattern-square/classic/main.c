/* PATTERN: A SQUARE OF STARS
 * *****
 * *****
 * *****
 * *****
 * ***** */
#include <stdio.h> /* PRINTF */

int main(void)
{
	int n = 5; /* SIZE: CHANGE IT FOR A BIGGER SQUARE */
	int i, j;

	for (i = 1; i <= n; i++) /* ROWS */
	{
		for (j = 1; j <= n; j++) /* STARS IN THE ROW */
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
