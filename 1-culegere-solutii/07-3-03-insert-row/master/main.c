/* CULEGERE VII.3.3 - INSERT A ROW
 * A MATRIX WITH M ROWS AND N COLUMNS, A VECTOR WITH N ELEMENTS AND A NUMBER K ARE READ; ADD THE
 * ELEMENTS OF THE VECTOR AS ROW K OF THE MATRIX AND PRINT THE NEW MATRIX
 * EXAMPLE: M=2 N=3, 1 2 3 / 4 5 6, VECTOR 7 8 9, K=2 -> 1 2 3 / 7 8 9 / 4 5 6
 * ASSUMPTION: K IS READ AFTER THE VECTOR, 1 <= K <= M+1 (K = M+1 ADDS THE ROW AT THE END) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 50 /* AT MOST 50 ROWS AND 50 COLUMNS */

int main(void)
{
	int a[MAX + 1][MAX] = {0}; /* ONE ROW MORE, FOR THE NEW ROW */
	int v[MAX] = {0};
	int m = 0, n = 0, k = 0, i, j;

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
	printf("The vector (%d numbers): ", n);
	for (j = 0; j < n; j++)
	{
		scanf("%d", &v[j]);
	}
	printf("k = ");
	scanf("%d", &k);

	/* ROWS K, K+1, ..., M MOVE ONE PLACE DOWN, STARTING WITH THE LAST ONE,
	 * SO THAT NO ROW IS WRITTEN OVER BEFORE IT IS MOVED */
	for (i = m - 1; i >= k - 1; i--)
	{
		for (j = 0; j < n; j++)
		{
			a[i + 1][j] = a[i][j];
		}
	}

	/* THE VECTOR TAKES THE FREE PLACE OF ROW K */
	for (j = 0; j < n; j++)
	{
		a[k - 1][j] = v[j];
	}
	m++;

	printf("The new matrix:\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}
