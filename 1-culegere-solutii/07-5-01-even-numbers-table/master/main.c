/* CULEGERE VII.5.1 - TABLE OF EVEN NUMBERS
 * BUILD AN N X N TABLE WITH THE FIRST N*N EVEN NUMBERS (2, 4, 6, ...), ROW BY ROW, AND PRINT IT
 * EXAMPLE: N=3 -> 2 4 6 / 8 10 12 / 14 16 18 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 50 /* AT MOST 50 ROWS AND 50 COLUMNS */

int main(void)
{
	int a[MAX][MAX];
	int n = 0, i, j, value;

	printf("n = ");
	scanf("%d", &n);

	/* EACH ELEMENT, ROW BY ROW, GETS THE NEXT EVEN NUMBER */
	value = 2;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			a[i][j] = value;
			value = value + 2;
		}
	}

	printf("The table:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}
