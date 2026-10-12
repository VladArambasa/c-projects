/* CULEGERE VII.4.2 - ROWS WITH ALL ELEMENTS EQUAL
 * A MATRIX WITH M ROWS AND N COLUMNS IS READ; PRINT HOW MANY ROWS HAVE ALL THEIR ELEMENTS EQUAL
 * EXAMPLE: M=3 N=3, 2 2 2 / 1 2 1 / 5 5 5 -> 2 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 50 /* AT MOST 50 ROWS AND 50 COLUMNS */

int main(void)
{
	int a[MAX][MAX] = {0};
	int m = 0, n = 0, i, j, equal, count;

	printf("m = ");
	scanf("%d", &m);
	printf("n = ");
	scanf("%d", &n);
	for (i = 0; i < m; i++)
	{
		printf("Row %d: ", i + 1);
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	count = 0;
	for (i = 0; i < m; i++)
	{
		/* A ROW IS GOOD WHEN EVERY ELEMENT EQUALS THE FIRST ONE OF THE ROW */
		equal = 1;
		for (j = 1; j < n; j++)
		{
			if (a[i][j] != a[i][0])
			{
				equal = 0;
			}
		}
		if (equal == 1)
		{
			count++;
		}
	}
	printf("Rows with all elements equal: %d\n", count);

	return 0;
}
