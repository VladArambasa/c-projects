/* CULEGERE VII.2.2 - TOTAL SCORE OF EACH COMPETITOR
 * THE SCORES OF M COMPETITORS AT N EVENTS FORM A MATRIX WITH M ROWS AND N COLUMNS; PRINT THE
 * TOTAL SCORE OF EACH COMPETITOR
 * EXAMPLE: M=3 N=2, 7 9 / 10 8 / 9 9 -> COMPETITOR1 16  COMPETITOR2 18  COMPETITOR3 18 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 50 /* AT MOST 50 COMPETITORS AND 50 EVENTS */

int main(void)
{
	int a[MAX][MAX] = {0};
	int m = 0, n = 0, i, j, total;

	printf("m = ");
	scanf("%d", &m);
	printf("n = ");
	scanf("%d", &n);
	for (i = 0; i < m; i++)
	{
		printf("Scores of competitor %d: ", i + 1);
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	/* THE TOTAL OF A COMPETITOR IS THE SUM OF HIS ROW */
	for (i = 0; i < m; i++)
	{
		total = 0;
		for (j = 0; j < n; j++)
		{
			total = total + a[i][j];
		}
		printf("competitor%d %d\n", i + 1, total);
	}

	return 0;
}
