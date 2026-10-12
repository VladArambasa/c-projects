/* PATTERN: 1, 3, 5, 7, 9 STARS, THEN BACK DOWN TO 1
 * *
 * ***
 * *****
 * *******
 * *********
 * *******
 * *****
 * ***
 * * */
#include <stdio.h> /* PRINTF */

int main(void)
{
	int n = 5;
	int i, j;

	for (i = 1; i <= n; i++) /* GOING UP */
	{
		for (j = 1; j <= 2 * i - 1; j++) /* ROW I HAS 2I - 1 STARS */
		{
			printf("*");
		}
		printf("\n");
	}

	for (i = n - 1; i >= 1; i--) /* GOING DOWN, WITHOUT REPEATING THE LONGEST ROW */
	{
		for (j = 1; j <= 2 * i - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
