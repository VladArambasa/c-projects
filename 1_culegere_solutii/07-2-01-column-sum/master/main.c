/* CULEGERE VII.2.1 - SUM OF A COLUMN
 * A MATRIX WITH M ROWS AND N COLUMNS AND A NUMBER K (K <= N) ARE READ; PRINT THE SUM OF THE
 * ELEMENTS ON COLUMN K
 * EXAMPLE: M=2 N=4 K=1, 4 3 6 8 / 7 4 9 0 -> S=11 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 50 /* AT MOST 50 ROWS AND 50 COLUMNS */

int main(void)
{
	int a[MAX][MAX] = {0};
	int m = 0, n = 0, k = 0, i, j, s;

	printf("m = ");
	scanf("%d", &m);
	printf("n = ");
	scanf("%d", &n);
	printf("k = ");
	scanf("%d", &k);
	for (i = 0; i < m; i++)
	{
		printf("Row %d: ", i + 1);
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	/* PARTIAL TRAVERSAL: ONLY COLUMN K, ONE ELEMENT FROM EACH ROW;
	 * COLUMN K HAS THE INDEX K - 1 BECAUSE INDEXES START FROM 0 */
	s = 0;
	for (i = 0; i < m; i++)
	{
		s = s + a[i][k - 1];
	}
	printf("s=%d\n", s);

	return 0;
}
