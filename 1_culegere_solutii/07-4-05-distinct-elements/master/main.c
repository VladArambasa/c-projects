/* CULEGERE VII.4.5 - ALL ELEMENTS DIFFERENT
 * A MATRIX WITH M ROWS AND N COLUMNS IS READ; CHECK IF ALL ITS ELEMENTS ARE DIFFERENT
 * EXAMPLE: M=2 N=3, 1 2 3 / 4 5 6 -> YES;  M=2 N=3, 1 2 3 / 4 2 6 -> NO */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 50 /* AT MOST 50 ROWS AND 50 COLUMNS */

int main(void)
{
	int a[MAX][MAX] = {0};
	int m = 0, n = 0, i, j, p, q, distinct;

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

	/* EVERY ELEMENT (I, J) IS COMPARED WITH EVERY ELEMENT (P, Q) ON ANOTHER POSITION */
	distinct = 1;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (p = 0; p < m; p++)
			{
				for (q = 0; q < n; q++)
				{
					if ((i != p || j != q) && a[i][j] == a[p][q])
					{
						distinct = 0;
					}
				}
			}
		}
	}

	if (distinct == 1)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}

	return 0;
}
