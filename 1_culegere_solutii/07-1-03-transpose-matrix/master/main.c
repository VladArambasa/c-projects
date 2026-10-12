/* CULEGERE VII.1.3 - ROWS BECOME COLUMNS
 * A MATRIX WITH M ROWS AND N COLUMNS IS READ; PRINT IT SO THAT ITS ROWS BECOME COLUMNS
 * (THE TRANSPOSED MATRIX, WITH N ROWS AND M COLUMNS)
 * EXAMPLE: M=2 N=3, 1 2 3 / 4 5 6 -> 1 4 / 2 5 / 3 6 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 50 /* AT MOST 50 ROWS AND 50 COLUMNS */

int main(void)
{
	int a[MAX][MAX] = {0};
	int m = 0, n = 0, i, j;

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

	/* LINE J OF THE OUTPUT IS COLUMN J OF THE MATRIX, READ FROM TOP TO BOTTOM */
	printf("The transposed matrix:\n");
	for (j = 0; j < n; j++)
	{
		for (i = 0; i < m; i++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}
