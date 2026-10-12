/* PATTERN: EACH ROW ENDS IN 5 AND STARTS ONE NUMBER LOWER
 * 5
 * 45
 * 345
 * 2345
 * 12345 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 5;
	int i, j;

	for (i = n; i >= 1; i--) /* THE ROW STARTS AT I */
	{
		for (j = i; j <= n; j++)
		{
			printf("%d", j);
		}
		printf("\n");
	}

	return 0;
}
